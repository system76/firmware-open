# Debugging

## Component

### coreboot

coreboot debug logging is enabled by default at the level of `Debug`. This can
be changed using `nvramtool` to set the CMOS option `debug_level`.

```
sudo nvramtool -w debug_level=<level>
```

Available log levels are:

- Emergency
- Alert
- Critical
- Error
- Warning
- Notice
- Info
- Debug
- Spew

### edk2

Modify `./scripts/_build/edk2.sh` so `BUILD_TYPE` is set to `DEBUG` instead of
`RELEASE`.

```sh
#BUILD_TYPE=RELEASE
BUILD_TYPE=DEBUG
```

The default PCD values are used, so a lot of ouput will be generated. This can
have a significant impact on the boot time.

This also unconditionally enables asserts, so any failures will result in edk2
hanging and require a reflash to fix.

### Rust UEFI apps

Debug logging can be enabled in the Rust UEFI apps (e.g., `firmware-setup`) by
selecting the `debug` feature in `Cargo.toml`.

## Method

A couple of methods can be used to get debug logging.

### Parallel port

This method requires no soldering of board components.

See [Debugging the EC firmware](https://github.com/system76/ec/blob/master/docs/debugging.md)
for details on setting up EC debugging over the parallel port.

cbmem output can be passed through the EC by enabling the driver in coreboot.
Uncomment the config in `models/<model>/coreboot.config` to enable logging the
cbmem console through the EC.

```
CONFIG_CONSOLE_SYSTEM76_EC=y
```

edk2 output can be passed through as well by enabling the driver in edk2.
This causes boot to be *very* slow, as edk2 generates a lot of output.
Uncomment the config in `models/<model>/edk2.config` to enable the driver.

```
SYSTEM76_EC_LOGGING=TRUE
```

### Using QEMU

A `qemu` target is provided to allow development and debugging in a VM.

```
./scripts/build.sh qemu
```

Install QEMU:

```sh
# Arch
sudo pacman -S qemu
# Fedora
sudo dnf install qemu-system-x86
# Ubuntu
sudo apt install qemu-system-x86
```

And run the image in a VM:

```
./scripts/qemu.sh
```
