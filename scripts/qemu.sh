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

kvm -M q35 -m 4096 -vga std \
    -bios "build/${MODEL}/coreboot.rom" \
    -chardev stdio,mux=on,id=debug \
    -device isa-serial,index=2,chardev=debug \
    -device isa-debugcon,iobase=0x402,chardev=debug \
    "$@"

# COM1: -device isa-serial,index=0,chardev=debug
# COM2: -device isa-serial,index=1,chardev=debug
# COM3: -device isa-serial,index=2,chardev=debug
# COM4: -device isa-serial,index=3,chardev=debug
