# Adding a new board

In order to add support for a new board you will need the current proprietary
BIOS ROM, the schematics for the system, and, if porting System76 EC, the EC
specification document. While the BIOS ROM is available from the manufacturer,
board schematics and EC specification typically require NDAs to access.

## Configuring the system

Before starting the porting process, the system should be configured to
enable as many devices as possible to provide a more complete output for
coreboot.

1. Boot into the proprietary BIOS
2. Enable things such as
    - TPM
    - Network stack
    - VT-d
3. Disable the Intel Management Engine (IME) if possible
4. Exit, saving changes
5. If the system is a laptop, connect to AC power with the adapter
6. If the device has a Thunderbolt port, attach and authorize a TBT device
7. If the device has a dGPU, ensure it present on the PCI bus
    - On Pop!\_OS, switch to NVIDIA graphics mode

```
sudo bash -c 'echo 1 > /sys/bus/pci/rescan'
```

## Generating required output

The `generate.sh` script will perform most steps for collecting the required
data for coreboot and EC firmware development. If regenerating for an existing
model, it will automatically overwrite the data.

If planning to use System76 EC firmware, perform the following before running:
- Set keyboard backlight to full brightness and white light
- Set display backlight to full brightness
- Set CPU fan to full speed

```
./scripts/generate.sh <model> <firmware.rom> [ec.rom]
```

If the microcode blobs from coreboot will not be used, then `microcode.rom`
must be generated for the correct CPU set from the private [intel-microcode]
repo.

## Porting coreboot

To port coreboot to a new board, see the coreboot documentation.

Once coreboot is ported, add its configuration.

```
cp coreboot/.config models/<model>/coreboot.config
```

## Porting System76 EC

To port System76 EC firmware to a new board, see the EC documentation.

Once System76 EC is ported, add `ec.config`.

```
echo "BOARD=system76/<model>" > models/<model>/ec.config"
```

If the proprietary EC was previously used, remove `ec.rom` and regenerate the
READMEs.

[intel-microcode]: https://github.com/system76/intel-microcode
