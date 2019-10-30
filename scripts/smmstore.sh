#!/usr/bin/env bash

set -e

cargo build --manifest-path libs/intel-spi/Cargo.toml --example read --release
sudo ./libs/intel-spi/target/release/examples/read

make -C coreboot/util/cbfstool -j "$(nproc)"
./coreboot/util/cbfstool/cbfstool read.rom read -r SMMSTORE -f smmstore.rom 

cargo build --manifest-path libs/smmstore/Cargo.toml --release
./libs/smmstore/target/release/smmstore smmstore.rom
