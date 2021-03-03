# Adding a new board

In order to add support for a new board you will need the current proprietary
BIOS ROM, the schematics for the system, and, if porting System76 EC, the EC
specification document. While the BIOS ROM is available from the manufacturer,
board schematics and EC specification typically require NDAs to access.

## Recommended hardware

The presence of hardware will affect the output of the script used to generate
the GPIO configuration for coreboot. It is recommended to have enough spare
hardware to fill all available slots on the motherboard. This includes RAM
modules, SATA drives, and M.2 modules. If the system has a Thunderbolt port, a
dock will also be useful for verifying Thunderbolt and PCIe hotplug
functionality.

These should be ready before attempting to boot a new port:

- An [external programmer][external-programmer]; for flashing the BIOS chip
- A [Mega 2560][mega2560]; for flashing the EC and debug logging

## Configuring the system

Before starting the porting process, the system should be configured to
enable as many devices as possible to provide a more complete output for
coreboot.

1. If the motherboard has open slots (RAM, M.2, SATA), fill them
2. Boot into the proprietary BIOS
3. Enable things such as
    - TPM
    - Network stack
    - VT-d
4. Disable the Intel Management Engine (IME) if possible
5. Exit, saving changes
6. If the system is a laptop, connect to AC power with the adapter
7. If the device has a Thunderbolt port, attach and authorize a TBT device
8. If the device has a dGPU, ensure it present on the PCI bus
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

- [TAS5825M] smart amp

Once coreboot is ported, add its configuration.

```
cp coreboot/.config models/<model>/coreboot.config
```

### devicetree

`generate.sh` does not create `devicetree.cb`. Some values for this file can be
produced using the `devicetree.py` script.

## Porting System76 EC

To port System76 EC firmware to a new board, see the EC documentation.

Once System76 EC is ported, add `ec.config`.

```
echo "BOARD=system76/<model>" > models/<model>/ec.config"
```

If the proprietary EC was previously used, remove `ec.rom` and regenerate the
READMEs.

[external-programmer]: ./flashing.md#external-programmer
[intel-microcode]: https://github.com/system76/intel-microcode
[mega2560]: https://github.com/system76/ec/blob/master/doc/mega2560.md
[TAS5825M]: https://github.com/system76/smart-amp
