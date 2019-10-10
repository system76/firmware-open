#!/usr/bin/env bash

set -e

if [ -z "$1" ]
then
  echo "$0 [model]" >&2
  exit 1
fi
MODEL="$1"

if [ ! -d "models/${MODEL}" ]
then
  echo "model '${MODEL}' not found" >&2
  exit 1
fi
MODEL_DIR="$(realpath "models/${MODEL}")"

DMI_MODEL="$(cat /sys/class/dmi/id/product_version)"
if [ "${DMI_MODEL}" != "${MODEL}" ]
then
  echo "Refusing to flash model '${MODEL}' to model '${DMI_MODEL}'" >&2
  exit 1
fi

cargo build --release --manifest-path libs/intel-spi/Cargo.toml
sudo libs/intel-spi/target/release/intel-spi "build/${MODEL}/coreboot.rom"
