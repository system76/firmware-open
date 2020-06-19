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

- Create a directory under `model/`
- Create `README.md.in` with basic info about the board
    - Title should be "\<manufacturer\> \<product\> (\<version\>)"
- Generate `coreboot-collector.txt` using [coreboot-collector]

```
cargo build --release --manifest-path=tools/coreboot-collector/Cargo.toml
sudo ./tools/coreboot-collector/target/release/coreboot-collector > models/<model>/coreboot-collector.txt
```

- Generate `gpio.h` and `hda.h`

```
./scripts/coreboot-gpio.sh models/<model>/coreboot-collector.txt > models/<model>/gpio.h
./scripts/coreboot-hda.sh models/<model>/coreboot-collector.txt > models/<model>/hda.h
```

- Extract the flash descriptor and Intel ME

```
make -C coreboot/util/ifdtool
coreboot/util/ifdtool/ifdtool -x <bios_image>
mv flashregion_0_flashdescriptor.bin models/<model>/fd.rom
mv flashregion_2_intel_me.bin models/<model>/me.rom
rm -f flashregion_*.bin
```

- If using the proprietary EC firmware, add it as `ec.rom`
- Otherwise, generate `ecspy.txt`
    - Set keyboard backlight to full brightness, white color
    - Set display backlight to full brightness
    - Set fans to full speed

```
cargo build --release --manifest-path=ec/ecspy/Cargo.toml
sudo ./ec/ecspy/target/release/ecspy > models/<model>/ecspy.txt
# Strip EC RAM entries
sed -i '/^0x/d' models/<model>/ecspy.txt
```

- Generate `microcode.rom` from the private [intel-microcode] repo

- Generate the READMEs

```
./scripts/readmes.sh
```

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

The model name used for the EC may be different from the name used for
firmware-open (e.g., `galp3-c` used for `galp4`).

If the proprietary EC was previously used, remove `ec.rom` and regenerate the
READMEs.

[coreboot-collector]: https://github.com/system76/coreboot-collector
[intel-microcode]: https://github.com/system76/intel-microcode
