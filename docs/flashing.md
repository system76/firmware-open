# Flashing firmware

**Flashing firmware manually is *not* recommended for the normal user!**

## Boot time

The first boot after flashing will take a long time. This is due to coreboot
initializing RAM modules for the first time. Once memory training is complete,
coreboot will cache this information and subsequent boots will take
significantly less time.

coreboot's `cbmem` tool can be used to verify this. The call to
`FspMemoryInit()` can report 20+ seconds on the first boot, and a few hundred
milliseconds on subsequent boots.

## UEFI application

This is the default method for flashing firmware (using firmware-update). When
used from this repo, it only works with systems running System76 open firmware.

```
./scripts/flash.sh <model>
```

By default the script will attempt to flash both the BIOS and the EC. Their
respective file can be deleted to skip flashing them.

If the EC is flashed, the system will immediately power off.

## Internal programmer

### Availability

This method is only possible when firmware is unlock. Firmware is unlocked by
one of two methods:

- The EC feature `CONFIG_SECURITY` is unset/disabled
- The EC is unlock for a single boot (via firmware-update or ectool)

The current state can be determined using ectool:

```
./ec/scripts/ectool.sh security
```

- `Lock`: This method can't be used
- `Unlock`: This method can be used

### flashrom

```
sudo flashrom -p internal -w build/<model>/firmware.rom
```

## External programmer

Use one of these methods for first-time flashing or flashing a bricked system.

### Identifying the BIOS chip

The packaging and protocol can be determined by `board_info.txt` in coreboot.
Pin 1 is sometimes marked by a small dot indent and a white paint mark. The
silkscreen may also indicate pin 1.

### CH341A USB programmer - slower, but easier to set up

These can be purchased from many places for around 15 USD. Make sure that the
one you get has a ROM clip. Here are some examples:

- [Amazon.com, Organizer.](https://www.amazon.com/Organizer-Socket-Adpter-Programmer-CH341A/dp/B07R5LPTYM)
- [Amazon.com, KeeYees.](https://www.amazon.com/KeeYees-SOIC8-EEPROM-CH341A-Programmer/dp/B07SHSL9X9) 
- [AliExpress.com, TZT.](https://aliexpress.com/item/32725360255.html)

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
