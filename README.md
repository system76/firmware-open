# System76 Open Firmware

An open source distribution of firmware utilizing coreboot, EDK2, and System76 firmware applications.

Please note that only the darp6, galp4, lemp9, oryp6 models are officially supported - if you brick your device it will be up to you to restore the current firmware using an external programmer.

If you would like to view schematics for any supported System76 model, please send an email to firmware@system76.com with the subject line Schematics for MODEL, where MODEL is the name of a directory in the models directory, such as darp6.

## Dependencies

### Install toolchain
```
./scripts/deps.sh
```

### Load Rust environment (or optionally reboot)
```
source ~/.cargo/env
```

### Build firmware, replace qemu with your model (look in the models directory for examples)
```
./scripts/build.sh qemu
```

### Emulate firmware, only available after building the qemu model
```
./scripts/qemu.sh
```

## Flashing

**Flashing firmware manually is *not* recommended for the normal user!**

### Internal programmer

Use this method for flashing a system already running System76 Open Firmware.

```
./scripts/flash.sh <model>
```

### External programmer

Use one of these methods for first-time flashing or flashing a bricked system.

#### CH341A USB programmer - slower, but easier to set up

These can be purchased from many places for around 15 USD. Make sure that the
one you get has a ROM clip. Here is an example:
https://www.amazon.com/Organizer-Socket-Adpter-Programmer-CH341A/dp/B07R5LPTYM

**Then you can follow these steps to flash the ROM chip:**

1. Turn off the computer
2. Unplug the AC adapter
3. Remove the bottom panel
4. Attach the clip to the SPI ROM chip
5. Plug the CH341A into a computer with this repository built
6. Verify that you can access the ROM chip, replacing `<model>` with your model:
```
./scripts/ch341a-dump.sh <model>
```
7. Flash the firmware you built, replacing `<model>` with your model:
```
./scripts/ch341a-flash.sh <model>
```

#### SPI Pi - faster, but harder to set up

SPI Pi is a Raspberry Pi used to flash the SPI ROM. To create a SPI Pi:

- Get a Raspberry Pi 2 or 3 with Ubuntu 16.04
- Hook up a SPI clip to the SPI Pi
  - The SPI Pi's SPI pinout can be found here: https://pinout.xyz/pinout/spi#
  - The pinout of a SPI rom can be found here: https://www.totalphase.com/media/wysiwyg/soic8-pinout.png
  - If you need more instructions, you should not be hooking up the SPI clip
- Connect the SPI Pi's SPI clip to the SPI ROM, ensuring pin 1 of the clip aligns with pin 1 on the ROM
- On the SPI Pi, run the following commands:

```
sudo apt install flashrom
git clone https://github.com/system76/firmware-open.git firmware
```

**Then you can follow these steps to flash the ROM chip:**

1. Turn off the computer
2. Unplug the AC adapter
3. Remove the bottom panel
4. Attach the clip to the SPI ROM chip
5. Connect to the Raspberry Pi and wait it for boot
```
sudo tio -b 115200 /dev/ttyUSB0
```
5. From the RPi session, test that the chip is detected.
```
cd firmware
./scripts/spipi.sh -r backup.rom
```
6. From the host, flash the firmware
```
SPIPI=<user@spipi> ./scripts/spipi-flash.sh <model>
```

## Intel Management Engine

The IME is present, but disabled. This is accomplished by [sending a HECI
command on boot][heci_disable], before RAM is initalized. This puts the IME in
a state similar to setting the HAP bit on earlier platforms. [me_cleaner] is
not used as it does not support IME version 14.0.

[heci_disable]: https://github.com/system76/coreboot/blob/f3ba5937e778105cb7e75de9a1d4adf54ea825e5/src/soc/intel/cannonlake/me.c#L186
[me_cleaner]:https://github.com/corna/me_cleaner

## Contents

- [apps](./apps) - Applications
- [coreboot](https://github.com/system76/coreboot.git) - coreboot README
- [docs](./docs) - System76 Open Firmware Documentation
- [ec](https://github.com/system76/ec.git) - System76 EC
- [edk2](https://github.com/system76/edk2.git) - EDK II Project
- [edk2-non-osi](https://github.com/tianocore/edk2-non-osi.git)
- [edk2-platforms](https://github.com/system76/edk2-platforms.git) - This branch holds all platforms actively maintained against the
- [FSP](https://github.com/IntelFsp/FSP.git) - Intel® Firmware Support Package (Intel® FSP) Binaries
- [libs](./libs) - Libraries
- [models](./models) - Models
- [scripts](./scripts)
- [tools](./tools) - Tools
