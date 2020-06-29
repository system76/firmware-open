#!/usr/bin/env bash

set -e

if [ -z "$1" ]
then
  echo "$0 [model]" >&2
  exit 1
fi
MODEL="$1"

source scripts/_ch341a.sh

flashrom -p ch341a_spi -c "${CHIP}" -w "build/${MODEL}/firmware.rom"
