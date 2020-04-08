#!/usr/bin/env bash

set -e

if [ -z "$1" ]
then
  echo "$0 <model> [--without-ec]" >&2
  exit 1
fi
MODEL="$1"

WITH_EC=true
if [ "$2" = "--without-ec" ]
then
    WITH_EC=false
fi

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
sudo libs/intel-spi/target/release/intel-spi "build/${MODEL}/firmware.rom"

if [ "$WITH_EC" = true ]
then
    if [ -e "build/${MODEL}/ec.rom" ]
    then
        cargo build --release --manifest-path ec/tool/Cargo.toml
        sudo ec/tool/target/release/system76_ectool flash "build/${MODEL}/ec.rom"
    fi
else
    echo "Skipping EC flash"
fi
