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

ssh -T "${SPIPI}" <<EOF
cd firmware
./scripts/spipi.sh -c "${CHIP}" -r dump.rom
EOF

sftp "${SPIPI}" <<EOF
cd firmware
get dump.rom build/dump.rom
EOF

./coreboot/build/cbfstool build/dump.rom read -r CONSOLE -f build/dump.log

less build/dump.log
