# System76 Open Firmware

An open source distribution of firmware utilizing coreboot, EDK2, and System76
firmware applications.

## Supported models

These models are supported and will receive updates through the firmware
manager:

- addw2
- bonw14
- darp6
- galp4
- lemp9
- oryp6

Other models may be in development or available without support, and can be
seen in the `models/` directory.

If the device becomes bricked it will require restoring the current firmware
using an external programmer. See [flashing](./docs/flashing.md) for details.

### Schematics

Board schematics can be provided on request by sending an email to
firmware@system76.com with the subject line  "Schematics for _model_", where
_model_ is the name of a directory in the `models/` directory, such as darp6.

You may not share these without explicit permission from System76.

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
