#!/usr/bin/env bash

set -e

# if [ -z "$1" ]
# then
#   echo "$0 [model]" >&2
#   exit 1
# fi
# MODEL="$1"
MODEL="qemu"

if [ ! -d "models/${MODEL}" ]
then
  echo "model '${MODEL}' not found" >&2
  exit 1
fi
MODEL_DIR="$(realpath "models/${MODEL}")"

kvm -M q35 -m 1024 -vga std \
    -bios "build/${MODEL}/coreboot.rom" \
    -chardev stdio,id=debug -device isa-debugcon,iobase=0x402,chardev=debug \
    "$@"
