# firmware-open

System76 Open Source Firmware

## Dependencies

### Install toolchain
```
sudo apt-get install \
  build-essential \
  bison \
  ccache \
  flex \
  git-lfs \
  gnat \
  mtools \
  nasm \
  uuid-dev \
  zlib1g-dev
```

### Make sure git lfs is set up
```
git lfs install
git lfs pull
```

### Install rust
```
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs \
  | sh -s -- -y --default-toolchain nightly
```

### Load cargo environment (or optionally reboot)
```
source ~/.cargo/env
```

### Ensure rust source is installed for current toolchain
```
rustup component add --toolchain "$(cat rust-toolchain)" rust-src
```

### Install cargo-xbuild
```
cargo install cargo-xbuild
```

### Build firmware, replace darp5 with your model (look in the models directory for examples)
```
./scripts/build.sh darp5
```

### Flashing firmware manually is not recommended for the normal user. For the advanced user, there is a script flash.sh which takes the same arguments as build.sh

## Contents

- [apps](./apps) - Applications
- [coreboot](https://github.com/system76/coreboot.git) - coreboot README
- [edk2](https://github.com/system76/edk2.git) - EDK II Project
- [edk2-non-osi](https://github.com/tianocore/edk2-non-osi.git)
- [edk2-platforms](https://github.com/system76/edk2-platforms.git) - This branch holds all platforms actively maintained against the
- [FSP](https://github.com/IntelFsp/FSP.git) - Intel® Firmware Support Package (Intel® FSP) Binaries
- [libs](./libs) - Libraries
- [models](./models) - Models
- [scripts](./scripts)
- [tools](./tools) - Tools
