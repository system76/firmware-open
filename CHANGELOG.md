# Changelog

Changes are identified by the date of the released firmware including them. If
you are running System76 Open Firmware, opening the boot menu will show this
date followed by an underscore and a short git revision.

## UNRELEASED

- Fixed building for QEMU
- Updated coreboot to upstream commit 670572ff6a
- Improved NVIDIA Optimus support
- gaze17-3060-b: Release of open firmware with System76 EC

## 2022-02-15

- Update ME for all supported systems
- Ensure that system powers off S5 plane if it fails to reach S0

## 2022-01-06

- Added support to enable/disable Intel ME via the CMOS option `me_state`
- Enabled coreboot measured boot
- Updated Rust toolchain to nightly-2021-06-15
- Updated coreboot to 4.15
- Updated EDK2 to edk2-stabke202108
- Updated TGL-U microcode blobs to revision 0x9a
- Updated TGL-H microcode blobs to revision 0x3c
- Updated all other boards to use microcode blobs from Intel's public repo
- Updated TGL FSP to A.0.51.31 from Intel's public repo
- Removed behavior of erasing NVRAM on CMOS reset

## 2021-09-30

- gaze16: Do not require unplugging the AC adapter after flashing
- gaze16: Fix using USB 2.0 devices in Type-C port

## 2021-09-23

- oryp8: Release of open firmware with System76 EC
- gaze16: Fix input current on 3050 variant
- gaze16: Fix power limit when booting on battery
- gaze16: Fix touchpad on newer Linux kernel and Windows
- Fix brightness controls on TGL platforms
- Fix PCIe subsystem IDs on TGL platforms
- Fix spurious clearing of boot options on Windows
- Provide battery cycle count

## 2021-07-20

- gaze16: Release of open firmware with System76 EC
- Improved thermals by syncing CPU and GPU fans
- Enabled fan speed interpolation
- Fixed ACPI timeout on S3 resume if a key is held
- Fixed keyboard responsiveness when touchpad uses wrong protocol
- Fixed entering firmware-setup due to missed keystrokes on boot
- Added scroll lock to default keyboard layouts

## 2021-04-07

- darp7, galp5, lemp10: Update microcode

## 2021-04-02

- Fix fan max keeping fan on when in S0iX
- Report all keys as released when lid is closed

## 2021-03-19

- gaze15: Release of open firmware with System76 EC
- gaze15: Add ELAN touchpad settings

## 2021-03-16

- oryp6, oryp7: Fix buzzing at lowest fan speed

## 2021-03-11

- lemp9: Fix backlight ACPI issues and TPM interrupt

## 2021-03-08

- oryp6, oryp7: Improved fan curve

## 2021-03-03

- oryp7: Release of open firmware with System76 EC

## 2021-02-15

- darp7, galp5: Raise HDMI data rate to support 4K@60Hz

## 2021-02-09

- galp5: Fix GPU driver crash in compute graphics mode

## 2021-02-05

- darp7: Fix keyboard scanning glitches

## 2021-01-21

- darp7: Release of open firmware with System76 EC

## 2021-01-19

- Update boot options on device hotplug
- Add fan toggle key (Fn+1)
- Clear NVRAM when CMOS battery is removed
- galp5, lemp10: Fix NVRAM compacting

## 2021-12-15

- galp5: Support variant with NVIDIA GPU

## 2020-12-04

- galp5, lemp10: Release of open firmware with System76 EC

## 2020-10-19

- Support customizing keyboard at runtime
- Add battery charging thresholds
- oryp6: Fix smart charger values
- Prevent wake when lid is closed

## 2020-09-22

- darp6: Release of open firmware with System76 EC
- darp6: Fix allocation of memory type range registers

## 2020-09-17

- Enable Wake-on-Lan (on supported models)
- Add ACPI thermal interface
- Fix ESXi keyboard issue

## 2020-09-03

- addw2: Release of open firmware with System76 EC

## 2020-08-24

- bonw14: Release of open firmware with System76 EC

## 2020-08-13

- Add UEFI TPM2 support

## 2020-08-06

- Enable ACPI backlight
- Add firmware configuration information

## 2020-07-06

- oryp6: Release of open firmware with System76 EC

## 2020-05-20

- Warn if no bootable media is found

## 2020-05-15

- Enable i2c-hid touchpad interface

## 2020-05-07

- Fix ghost key debouncing

## 2020-05-04

- Improve ghost key handling and reduce key debounce

## 2020-04-23

- Fix duplicate release of key after release of function key

## 2020-04-18

- lemp9: Update fan curve

## 2020-04-09

- lemp9: Release of open firmware with System76 EC

## 2020-02-05

- Use descriptive device names
- Only show bootable devices

## 2020-01-13

- Fix NVIDIA eGPU issues
- Iimprove boot order editing

## 2019-10-31

- darp6, galp4: Release of open firmware with proprietary EC
