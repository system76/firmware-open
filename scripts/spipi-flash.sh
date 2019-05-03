#!/usr/bin/env bash

set -e

if [ -z "$1" ]
then
  echo "$0 [model]" >&2
  exit 1
fi
MODEL="$1"

source scripts/_spipi.sh

sftp "${SPIPI}" <<EOF
cd firmware
put "build/${MODEL}/coreboot.rom" "${MODEL}.rom"
EOF

ssh -T "${SPIPI}" <<EOF
cd firmware
./spipi.sh -c "${CHIP}" -w "${MODEL}.rom"
EOF
