# UEFI

System76 uses [EDK2](https://github.com/tianocore/edk2) to implement UEFI.

[coreboot](https://coreboot.org/) is used for Platform Initialization (PI).

## Booting

System76 Open Firmware only supports UEFI booting. Legacy BIOS-MBR booting is
not supported. `\EFI\BOOT\BOOTX64.EFI` must exist on the EFI System Partition
to be considered valid.

Network functionality is disabled. Native PXE booting is not supported.

### Secure Boot

Secure Boot support is enabled since system76/firmware-open@105e74b14613
(2023-04-03).

A minimal firmware UI is available to delete all keys and enroll the default
keys. It is intended that most management is done from the OS.

Note that the Secure Boot support present is only intended for allowing
Microsoft Windows installation checks to pass. It should not be relied on for
system security due to limitations of the implementation.

## Shell

The internal UEFI shell is disabled. A separate binary on a bootable drive
must be used to access the shell environment.
