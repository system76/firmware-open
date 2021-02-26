#!/usr/bin/env bash

set -e

if [ -z "$1" -o ! -e "$1" -o -z "$2" ]
then
  echo "$0 [coreboot.config] [coreboot.rom]" >&2
  exit 1
fi
CONFIG="$(realpath "$1")"
COREBOOT="$(realpath "$2")"

pushd coreboot >/dev/null
  if [ ! -d util/crossgcc/xgcc ]
  then
    make CPUS="$(nproc)" crossgcc-i386
  fi
  make distclean
  make defconfig KBUILD_DEFCONFIG="${CONFIG}"

  # Ensure config is correct
  while read line; do
      if [[ "${line}" =~ "^#" ]] || [[ -z "${line}" ]]; then
          continue
      fi

      if ! grep -q "${line}" ".config"; then
          echo "expected config not found: ${line}" >&2
          exit 1
      fi
  done < "${CONFIG}"

  make --jobs="$(nproc)"
  cp -v "build/coreboot.rom" "${COREBOOT}"
popd >/dev/null
