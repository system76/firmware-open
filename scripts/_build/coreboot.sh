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
  make CPUS="$(nproc)" crossgcc-i386
  make distclean
  cp -v "${CONFIG}" .config
  make --jobs="$(nproc)"
  cp -v "build/coreboot.rom" "${COREBOOT}"
popd >/dev/null
