# System76 Open Firmware Feature Matrix

This lists important features provided by System76 Open Firmware. Your system
must be updated to at least the firmware version specified in the following
[platform tables](#platforms) to include all specified [features](#features).
To see the changes in specific firmware versions, see the
[changelog](./../CHANGELOG.md).

## Platforms

- [Intel 13th Gen (Raptor Lake)](#intel-13th-gen-raptor-lake)
- [Intel 12th Gen (Alder Lake)](#intel-12th-gen-alder-lake)
- [Intel 11th Gen (Tiger Lake)](#intel-11th-gen-tiger-lake)
- [Intel 10th Gen (Comet Lake)](#intel-10th-gen-comet-lake)

### Intel 13th Gen (Raptor Lake)

This generation universally supports these features with up-to-date firmware:

- [Intel VT-x](#intel-vt-x)
- [Intel VT-d](#intel-vt-d)
- [Disabled Management Engine](#disabled-management-engine)
- [TPM 2.0 Support](#tpm-20-support)
- [Battery Charging Thresholds](#battery-charging-thresholds)
- [Keyboard Customization](#keyboard-customization)
- [Measured Boot](#measured-boot)
- [Firmware Security System](#firmware-security-system)
- [Secure Boot Support](#secure-boot-support)

| System76 Model (Version) | Firmware Version    | SoC    | [Windows 11 Support](#windows-11-support) | [NVIDIA Dynamic Boost](#nvidia-dynamic-boost) |
|--------------------------|---------------------|--------|-----|-----|
| Adder WS (addw3)         | 2023-05-17\_9560b2e | RPL-HX | ✔   | ✔   |
| Bonobo WS (bonw15)       | 2023-07-10\_0e4a64a | RPL-HX | ✔   | ✔   |
| Darter Pro (darp9)       | 2023-06-08\_a8590a5 | RPL-P  | ✔   | N/A |
| Galago Pro (galp7)       | 2023-05-25\_5608a8d | RPL-H  | ✔   | N/A |
| Gazelle (gaze18)         | 2023-03-22\_799ed79 | RPL-H  | ✔   | ✔   |
| Lemur Pro (lemp12)       | 2023-05-16\_e9b9ea8 | RPL-U  | ✔   | N/A |
| Oryx Pro (oryp11)        | 2023-06-22\_e5c3632 | RPL-H  | ✔   | ✔   |
| Serval WS (serw13)       | 2023-05-17\_9560b2e | RPL-HX | ✔   | ✔   |

### Intel 12th Gen (Alder Lake)

This generation universally supports these features with up-to-date firmware:

- [Intel VT-x](#intel-vt-x)
- [Intel VT-d](#intel-vt-d)
- [TPM 2.0 Support](#tpm-20-support)
- [Battery Charging Thresholds](#battery-charging-thresholds)
- [Keyboard Customization](#keyboard-customization)
- [Measured Boot](#measured-boot)

| System76 Model (Version) | Firmware Version    | SoC    |
|--------------------------|---------------------|--------|
| Darter Pro (darp8)       | 2022-11-21\_b337ac6 | ADL-P  |
| Galago Pro (galp6)       | 2022-11-21\_b337ac6 | ADL-P  |
| Gazelle (gaze17-3050)    | 2022-11-21\_b337ac6 | ADL-H  |
| Gazelle (gaze17-3060-b)  | 2022-06-07\_090f9e0 | ADL-H  |
| Lemur Pro (lemp11)       | 2022-11-21\_b337ac6 | ADL-U  |
| Oryx Pro (oryp9)         | 2022-07-20\_ae6aa72 | ADL-H  |
| Oryx Pro (oryp10)        | 2022-09-26\_aa797d2 | ADL-H  |

### Intel 11th Gen (Tiger Lake)

This generation universally supports these features with up-to-date firmware:

- [Intel VT-x](#intel-vt-x)
- [Intel VT-d](#intel-vt-d)
- [TPM 2.0 Support](#tpm-20-support)
- [Battery Charging Thresholds](#battery-charging-thresholds)
- [Keyboard Customization](#keyboard-customization)

| System76 Model (Version) | Firmware Version    | SoC    | [Measured Boot](#measured-boot) |
|--------------------------|---------------------|--------|----|
| Darter Pro (darp7)       | 2022-11-21\_b337ac6 | TGL-U  | ✔️  |
| Galago Pro (galp5)       | 2022-11-21\_b337ac6 | TGL-U  | ✔️  |
| Gazelle (gaze16-3050)    | 2022-11-21\_b337ac6 | TGL-H  | ✔️  |
| Gazelle (gaze16-3060)    | 2021-09-30\_14b8a6e | TGL-H  | ❌ |
| Gazelle (gaze16-3060-b)  | 2021-11-01\_fb9d759 | TGL-H  | ❌ |
| Lemur Pro (lemp10)       | 2022-11-21\_b337ac6 | TGL-U  | ✔️  |
| Oryx Pro (oryp8)         | 2022-10-14\_4136ef8 | TGL-H  | ✔️  |

### Intel 10th Gen (Comet Lake)

This generation universally supports these features with up-to-date firmware:

- [Intel VT-x](#intel-vt-x)
- [Intel VT-d](#intel-vt-d)
- [Disabled Management Engine](#disabled-management-engine)
- [TPM 2.0 Support](#tpm-20-support)
- [Battery Charging Thresholds](#battery-charging-thresholds)
- [Keyboard Customization](#keyboard-customization)

| System76 Model (Version) | Firmware Version    | SoC    | [Measured Boot](#measured-boot) |
|--------------------------|---------------------|--------|----|
| Adder WS (addw2)         | 2022-11-21\_b337ac6 | CML-H  | ✔️  |
| Bonobo WS (bonw14)       | 2021-07-20\_93c2809 | CML-S  | ❌ |
| Darter Pro (darp6)       | 2021-07-20\_93c2809 | CML-U  | ❌ |
| Gazelle (gaze15)         | 2022-11-21\_b337ac6 | CML-H  | ✔️  |
| Lemur Pro (lemp9)        | 2021-07-20\_93c2809 | CML-U  | ❌ |
| Oryx Pro (oryp6)         | 2021-07-20\_93c2809 | CML-H  | ❌ |
| Oryx Pro (oryp7)         | 2022-11-21\_b337ac6 | CML-H  | ✔️  |

## Features

### Intel VT-x

Intel Virtualization Technology is enabled, which provides support for high
performance virtual machines.

### Intel VT-d

Intel Virtualization Technology for Directed I/O is enabled, which provides
support for passing PCIe devices to virtual machines, and for protecting against
PCIe device craches and DMA attacks.

### Disabled Management Engine

The Intel Management Engine is disabled at runtime to improve security.

### TPM 2.0 Support

**Introduced in firmware version 2020-08-13.**

A discrete TPM 2.0 is available for use.

### Battery Charging Thresholds

**Introduced in firmware version 2020-10-19.**

Battery charging thresholds extend the life of the battery by reducing the
maximum charge that the battery is charged to, as well as the minimum charge
when charging the battery begins.

### Keyboard Customization

**Introduced in firmware version 2020-10-19.**

Keyboard customization allows the keyboard layout to be modified at runtime
using the
[System76 Keyboard Configurator](https://github.com/pop-os/keyboard-configurator/).

### Measured Boot

**Introduced in firmware version 2022-01-06.**

Measured boot uses the TPM to maintain hashes of all binaries used in the boot
process. This allows for detecting changes to the firmware, which can be used
by a system such as TPM2-TOTP or BitLocker to improve security.

### Firmware Security System

**Introduced in firmware version 2023-04-03.**

The firmware security system ensures both SoC and EC firmware is read-only at
runtime. Unlocking the firmware requires the system to reboot and physical
presence is required. The user must enter in a secure, randomly generated number
before the system can boot any third-party code while unlocked. Both EC firmware
and system firmware are locked on any boots where the prompt is not shown. For
screenshots showing this prompt, see the pull request here:
https://github.com/system76/firmware-setup/pull/18

### Secure Boot Support

**Introduced in firmware version 2023-04-03.**

A new firmware setup menu allows enabling and disabling Secure Boot and also
allows for entering setup mode for custom key enrollment. Work is being done in
Pop!\_OS to enable the use of custom secure boot keys, in addition to adding
TPM2-TOTP authentication of the firmware boot path. For screenshots showing the
new menus, see the pull request here:
https://github.com/system76/edk2/pull/38

### Windows 11 Support

**Introduced in firmware version 2023-04-03.**

Windows 11 requires [TPM 2.0 Support](#tpm-20-support) and
[Secure Boot Support](#secure-boot-support). For users wanting to use Windows, the use of Windows 11 is
recommended for Intel 12th Generation (Alder Lake) and newer systems, as it
includes a new scheduler that supports the efficiency cores.

### NVIDIA Dynamic Boost

**Introduced in firmware version 2023-04-03.**

On new systems with the NVIDIA 4000 series GPUs, NVIDIA Dynamic Boost has been
enabled with new code in coreboot. This allows power to be shared between the
CPU and GPU, diverting power to the subsystem that needs it most. This can
provide an additional 25W boost split between the CPU and GPU depending on the
task, significantly improving throughput and framerates.
