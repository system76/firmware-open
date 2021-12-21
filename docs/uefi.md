# UEFI

System76 uses [EDK2](https://github.com/tianocore/edk2) to implement UEFI.

[coreboot](https://coreboot.org/) is used for Platform Initialization (PI).

## Booting

System76 Open Firmware only supports UEFI booting. Legacy BIOS-MBR booting is
not supported. `\EFI\BOOT\BOOTX64.EFI` must exist on the EFI System Partition
to be considered valid.

Network functionality is disabled. Native PXE booting is not supported.

### Secure Boot

Secure Boot support is currently disabled.

The implementation from 9elements is in development. If building a custom
image, the edk2 config `SECURE_BOOT_ENABLE` can be set to enable support.

There is currently no firmware UI to view or configure Secure Boot.

## Shell

The internal UEFI shell is disabled. A separate binary on a bootable drive
must be used to access the shell environment.
