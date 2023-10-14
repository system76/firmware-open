#!/usr/bin/env bash

set -e

if [ -z "$1" ]
then
  echo "$0 [model]" >&2
  exit 1
fi
MODEL="$1"

. scripts/_ch341a.sh

flashrom -p ch341a_spi -c "${CHIP}" -r build/dump.rom

./coreboot/build/cbfstool build/dump.rom read -r CONSOLE -f build/dump.log

less build/dump.log
