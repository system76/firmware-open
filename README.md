# System76 Open Firmware

An open source distribution of firmware utilizing coreboot, EDK2, and System76
firmware applications.

## Supported models

These models are supported and will receive updates through the firmware
manager:

- addw2
- bonw14
- darp6
- darp7
- darp8
- galp4
- galp5
- galp6
- gaze15
- gaze16-3050
- gaze16-3060
- gaze16-3060-b
- gaze17-3050
- gaze17-3060-b
- lemp9
- lemp10
- lemp11
- oryp6
- oryp7
- oryp8
- oryp9

Other models may be in development or available without support, and can be
seen in the `models/` directory.

If the device becomes bricked it will require restoring the current firmware
using an external programmer. See [flashing](./docs/flashing.md) for details.

### Schematics

System76 customers may request board schematics for their system by sending an
email to firmware@system76.com with the subject line  "Schematics for _model_",
where _model_ is one of the supported models listed above. Please include the
serial number of your system for verification.

You may not share these without explicit permission from System76.

## Changelog

For a list of important changes please see the [changelog](./CHANGELOG.md).

## Building

Dependencies can be installed with the provided script.

```
./scripts/deps.sh
```

If rustup was installed for the first time, it will be required to source the
environment file it installed to use the correct Rust toolchain.

```
source ~/.cargo/env
```

A script is provided to build the firmware. The available targets for building
are the model folders in `models/`. For example, to build for QEMU:

```
./scripts/build.sh qemu
```

Once built, the firmware must be flashed to use. Several scripts are available
to flash the new firmware, depending on how it is going to be written.

- `scripts/qemu.sh`: [Run the firmware in QEMU](./docs/debugging.md#using-qemu) (specific to the QEMU model)
- `scripts/flash.sh`: Flash using the internal flasher
- `scripts/ch341a-flash.sh`: Flash using a CH341A programmer
- `scripts/spipi-flash.sh`: Flash using a Raspberry Pi

See [Flashing firmware](./docs/flashing.md) for more details.
