# Flashing firmware

**Flashing firmware manually is *not* recommended for the normal user!**

## Internal programmer

Use this method for flashing a system already running System76 Open Firmware.

```
./scripts/flash.sh <model>
```

## External programmer

Use one of these methods for first-time flashing or flashing a bricked system.

### CH341A USB programmer - slower, but easier to set up

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

### SPI Pi - faster, but harder to set up

SPI Pi is a Raspberry Pi used to flash the SPI ROM. To create a SPI Pi:

- Get a Raspberry Pi with Ubuntu LTS
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

