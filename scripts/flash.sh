#!/usr/bin/env bash

set -e

if [ -z "$1" ]
then
  echo "$0 [model]" >&2
  exit 1
fi
MODEL="$1"

if [ ! -d "models/$1" ]
then
  echo "model '$1' not found" >&2
  exit 1
fi
MODEL_DIR="$(realpath "models/${MODEL}")"

cargo build --release --manifest-path libs/intel-spi/Cargo.toml
sudo libs/intel-spi/target/release/intel-spi "build/${MODEL}/coreboot.rom"
