# System76 Open Firmware Changelog

Changes are identified by the date of the released firmware including them. If
you are running System76 Open Firmware, opening the boot menu will show this
date followed by an underscore and a short git revision. To see if specific
features apply to your model and firmware version, see the
[feature matrix](./docs/features.md).

## unreleased

- Updated coreboot to 24.02
- adl-p: Updated FSP to C.1.75.10
- adl-s: Updated FSP to C.0.75.10
- adl: Updated microcode to revision 0x430
- rpl-p: Updated FSP to C.1.BD.40
- rpl-s: Updated FSP to C.0.BD.40
- rpl: Updated microcode to revision 0x411c
- tgl: Updated FSP to A.0.7E.70
- tgl-u: Updated microcode to revision 0xb4
- tgl-h: Updated microcode to revision 0x4e
- adl: Fixed PCIe 4.0 drives in PCIe 3.0 slot failing to initialize on resume
- rpl: Fixed PCIe 4.0 drives in PCIe 3.0 slot failing to initialize on resume
- rpl: Fixed TCSS ACPI access
- Changed the EC version to be distinct from the SBIOS version

## 2024-01-18

- darp9: Added SSD RTD3 configs to fix suspend with some drives

## 2024-01-10

- darp8: Fixed suspend issue on new boards by switching to S0ix by default
- darp9: Fixed suspend issue on new boards by switching to S0ix by default

## 2023-10-20

- tgl-u: Fixed CPU not going lower than C2 due to card reader LTR
- bonw15: Fixed speaker audio cutting in/out
- oryp11: Fixed speaker audio cutting in/out

## 2023-10-13

- tgl-u: Fixed potential EC lock up during opportunistic suspend
- galp5: Fixed CPU not going lower than C2 due to card reader LTR

## 2023-09-19

- rpl-hx: Added support for 5600 MHz RAM

## 2023-09-08

- adl: Updated CSME to 16.1.25.2124
- adl,rpl: Fixed SMMSTORE init sometimes failing
- Increased key debounce from 5ms to 10ms

## 2023-08-23

- rpl: Fixed RPL-S GPIO driver on Windows

## 2023-08-18

- cml-u: Fixed boot failing at FSP-S
- Added KBC reset on CPU reset to prevent keyboard from being locked
- Enabled power switch Watch Dog Timer with a timeout of 10 seconds
- Fixed detecting if PECI is available on eSPI systems using S0ix
- Added support for a FnLock key
- tgl: Fixed Bluetooth performance by enabling audio offload
- gaze16: Fixed CPU not going lower than C2 due to card reader LTR
- adl: Fixed CPU not going lower than C2 due to card reader LTR
- rpl: Fixed CPU not going lower than C2 due to card reader LTR
- Changed battery charge start threshold to 90%
- Changed charger to disable when battery is full

## 2023-07-19

- bonw14: Fixed loading CPU microcode
- rpl-hx: Fixed setting PL1 and PL2 power limits
- rpl-hx: Fixed LPM substates
- gaze17: Removed invalid RTD3 configs
- oryp10: Removed invalid RTD3 configs
- galp8: Removed SATA RTD3 to fix drives being lost on suspend
- lemp11: Removed SATA RTD3 to fix drives being lost on suspend
- Reduced key debounce from 15ms to 5ms
- galp6: Fixed fan tachometer GPIOs
- lemp9: Fixed fan tachometer GPIOs
- lemp10: Fixed fan tachometer GPIOs
- lemp11: Fixed fan tachometer GPIOs

## 2023-07-10

- Updated Secure Boot DBX to version 371 (2023-05-09)
- bonw15: Added initial release of open firmware with System76 EC
- oryp11: Changed adapter Rsense to 10 milliohms
- serw13: Changed adapter Rsense to 10 milliohms

## 2023-06-22

- addw3: Enabled support for 5200 MT/s memory
- serw13: Enabled support for 5200 MT/s memory
- oryp11: Added initial release of open firmware with System76 EC
- rpl: Enabled TPM read delay to fix occasional failures with Infineon chips
- Changed TPM behavior to perform TPM Restart if TPM Resume fails

## 2023-06-08

- darp9: Added initial release of open firmware with System76 EC
- Added detection of RGB keyboards at runtime
- oryp9: Enabled firmware security
- oryp9: Enabled NVIDIA Dynamic Boost
- oryp10: Enabled firmware security
- oryp10: Enabled NVIDIA Dynamic Boost
- Invalidated CMOS checksum after flashing to ensure default options are used

## 2023-05-25

- Set PL4 based on AC state for all boards
- Increased PL4 on battery to 45W for dGPU boards
- galp6: Enabled firmware security
- galp7: Added initial release of open firmware with System76 EC

## 2023-05-17

- serw13: Added initial release of open firmware with System76 EC
- Fixed Windows BSoD on RPL-HX

## 2023-05-16

- lemp12: Added initial release of open firmware with System76 EC

## 2023-04-28

- addw3: Added initial release of open firmware with System76 EC

## 2023-03-22

- Updated coreboot to upstream commit decbf7b4d975
- Enabled support for Secure Boot
- Enabled minimal UI for enforcing Secure Boot and resetting keys
- Added firmware locking support
- Enabled S3 suspend on everything but TGL-U
- Disabled ME by default on everything but TGL-U
- Added support for NVIDIA Dynamic Boost
- gaze18: Added initial release of open firmware with System76 EC

## 2022-11-21

- lemp11: Added workaround to force S0ix entry on suspend
- tgl-u: Removed CPU PCIe RP RTD3 config to fix suspend with certain drives
- adl-p: Removed CPU PCIe RP RTD3 config to fix suspend with certain drives
- adl-p: Fixed ACPI brightness controls on Windows 10 and Linux 6.1
- adl-p: Disabled SATA DevSlp to fix S0ix entry
- tgl-u: Disabled SATA DevSlp to fix S0ix entry
- Updated Rust toolchain to nightly-2022-03-18
- adl-p: Added workaround to force S0ix entry on suspend
- adl-p: Fixed case where system gets stuck in S5 due to power loss
- tgl-u: Fixed case where system gets stuck in S5 due to power loss
- galp5: Fixed power off failing due to WLAN GPIO

## 2022-10-14

- Fixed smart charger values for all boards
- Fixed keyboard backlight color with custom values
- lemp11: Removed RTD3 config for card reader to fix suspend

## 2022-09-26

- oryp8: Fixed brightness controls on Windows
- oryp10: Added initial release of open firmware with System76 EC

## 2022-09-07

- Updated CSME for TGL-H to 15.0.41.2158
- Updated CSME for TGL-U to 15.0.41.2158
- Changed build to use coreboot toolchain for edk2
- Fixed signal used to detect S0ix
- Fixed off-by-one for battery charging start/stop thresholds

## 2022-08-03

- Updated coreboot to upstream commit 37bf8c6dd590
- Updated TGL-U microcode to revision 0xa4 from Intel's public repo
- Updated TGL-H microcode to revision 0x3e from Intel's public repo
- Updated ADL microcode to revision 0x41c from Intel's public repo
- Updated ADL FSP to C.0.69.74 from Intel's public repo
- Updated CSME for ADL-P to 16.0.15.1810v8 (16.0.15.1829)
- Fixed uncommon I2C HID initialization failure on boot
- Fixed smart charger values for all boards
- galp6: Added initial release of open firmware with System76 EC

## 2022-07-27

- gaze17-3050: Added initial release of open firmware with System76 EC
- gaze17-3060: Fixed suspend with WD drives

## 2022-07-20

- oryp9: Added initial release of open firmware with System76 EC

## 2022-07-13

- darp8: Fixed power off under load while on battery power

## 2022-07-05

- lemp11: Added initial release of open firmare with System76 EC

## 2022-06-23

- darp8: Added initial release of open firmware with System76 EC

## 2022-06-07

- Fixed building for QEMU
- Updated coreboot to upstream commit 670572ff6a
- Fixed NVIDIA subsystem ID being lost on suspend
- TGL: Fixed Device Manager warning about missing drivers for Tiger Lake IPC
  Controller and System76 EC ACPI devices
- Improved NVIDIA Optimus support
- tgl-u: Fixed suspend with certain drives
- gaze17-3060-b: Added initial release of open firmware with System76 EC

## 2022-02-15

- Updated ME for all supported systems
- Ensured that system powers off S5 plane if it fails to reach S0

## 2022-01-06

- Added support to enable/disable Intel ME via the CMOS option `me_state`
- Enabled coreboot measured boot
- Updated Rust toolchain to nightly-2021-06-15
- Updated coreboot to 4.15
- Updated EDK2 to edk2-stable202108
- Updated TGL-U microcode blobs to revision 0x9a
- Updated TGL-H microcode blobs to revision 0x3c
- Updated all other boards to use microcode blobs from Intel's public repo
- Updated TGL FSP to A.0.51.31 from Intel's public repo
- Removed behavior of erasing NVRAM on CMOS reset

## 2021-09-30

- gaze16: Removed need to unplug the AC adapter after flashing
- gaze16: Fixed using USB 2.0 devices in Type-C port

## 2021-09-23

- oryp8: Added initial release of open firmware with System76 EC
- gaze16: Fixed input current on 3050 variant
- gaze16: Fixed power limit when booting on battery
- gaze16: Fixed touchpad on newer Linux kernel and Windows
- Fixed brightness controls on TGL platforms
- Fixed PCIe subsystem IDs on TGL platforms
- Fixed spurious clearing of boot options on Windows
- Added battery cycle count

## 2021-07-20

- gaze16: Added initial release of open firmware with System76 EC
- Improved thermals by syncing CPU and GPU fans
- Enabled fan speed interpolation
- Fixed ACPI timeout on S3 resume if a key is held
- Fixed keyboard responsiveness when touchpad uses wrong protocol
- Fixed entering firmware-setup due to missed keystrokes on boot
- Added scroll lock to default keyboard layouts

## 2021-04-07

- tgl-u: Updated microcode

## 2021-04-02

- Fixed fan max keeping fan on when in S0iX
- Changed keyboard behavior to report all keys as released when lid is closed

## 2021-03-19

- gaze15: Added initial release of open firmware with System76 EC
- gaze15: Added ELAN touchpad settings

## 2021-03-16

- oryp6: Fixed buzzing at lowest fan speed
- oryp7: Fixed buzzing at lowest fan speed

## 2021-03-11

- lemp9: Fixed backlight ACPI issues and TPM interrupt

## 2021-03-08

- oryp6: Improved fan curve
- oryp7: Improved fan curve

## 2021-03-03

- oryp7: Added initial release of open firmware with System76 EC

## 2021-02-15

- darp7: Increased HDMI data rate to support 4K@60Hz
- galp5: Increased HDMI data rate to support 4K@60Hz

## 2021-02-09

- galp5: Fixed GPU driver crash in compute graphics mode

## 2021-02-05

- darp7: Fixed keyboard scanning glitches

## 2021-01-21

- darp7: Added initial release of open firmware with System76 EC

## 2021-01-19

- Added behavior to update boot options on device hotplug
- Added fan toggle key (Fn+1)
- Added behavior to clear NVRAM when CMOS battery is removed
- galp5: Fixed NVRAM compacting
- lemp10: Fixed NVRAM compacting

## 2021-12-15

- galp5: Added support for variant with NVIDIA GPU

## 2020-12-04

- galp5: Added initial release of open firmware with System76 EC
- lemp10: Added initial release of open firmware with System76 EC

## 2020-10-19

- Added support for customizing keyboard at runtime
- Added battery charging thresholds
- oryp6: Fixed smart charger values
- Prevented wake when lid is closed

## 2020-09-22

- darp6: Added initial release of open firmware with System76 EC
- darp6: Fixed allocation of memory type range registers

## 2020-09-17

- Enabled Wake-on-Lan (on supported models)
- Added ACPI thermal interface
- Fixed ESXi keyboard issue

## 2020-09-03

- addw2: Added initial release of open firmware with System76 EC

## 2020-08-24

- bonw14: Added initial release of open firmware with System76 EC

## 2020-08-13

- Added UEFI TPM2 support

## 2020-08-06

- Enabled ACPI backlight
- Added firmware configuration information

## 2020-07-06

- oryp6: Added initial release of open firmware with System76 EC

## 2020-05-20

- Added warning if no bootable media is found

## 2020-05-15

- Enabled i2c-hid touchpad interface

## 2020-05-07

- Fixed ghost key debouncing

## 2020-05-04

- Improved ghost key handling and reduce key debounce

## 2020-04-23

- Fixed duplicate release of key after release of function key

## 2020-04-18

- lemp9: Updated fan curve

## 2020-04-09

- lemp9: Added initial release of open firmware with System76 EC

## 2020-02-05

- Changed boot manager to use descriptive device names
- Changed boot manager to only show bootable devices

## 2020-01-13

- Fixed NVIDIA eGPU issues
- Improved boot order editing

## 2019-10-31

- darp6: Added intial release of open firmware with proprietary EC
- galp4: Added intial release of open firmware with proprietary EC
