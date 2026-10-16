#!/usr/bin/env bash

set -e

if [ -z "$1" ]
then
  echo "$0 [model]" >&2
  exit 1
fi
MODEL="$1"

. scripts/_ch341a.sh

flashrom \
    --programmer ch341a_spi \
    --chip "${CHIP}" \
    --progress \
    --write "build/${MODEL}/firmware.rom"
