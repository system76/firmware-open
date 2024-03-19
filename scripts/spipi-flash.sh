#!/usr/bin/env bash

# shellcheck disable=SC2087

set -e

if [ -z "$1" ]
then
  echo "$0 [model]" >&2
  exit 1
fi
MODEL="$1"

. scripts/_spipi.sh

rsync -v "build/${MODEL}/firmware.rom" "${SPIPI}:firmware/${MODEL}.rom"

ssh -T "${SPIPI}" <<EOF
cd firmware
./scripts/spipi.sh -c "${CHIP}" -w "${MODEL}.rom"
EOF
