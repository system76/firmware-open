#!/usr/bin/env bash

set -e

if [ -z "$1" -o ! -e "$1" -o -z "$2" ]
then
  echo "$0 [coreboot.config] [coreboot.rom]" >&2
  exit 1
fi
CONFIG="$(realpath "$1")"
COREBOOT="$(realpath "$2")"

function check_configs() {
  local defconfig="$1"

  while read -r line; do
    if [[ "${line}" =~ ^# ]] || [[ -z "${line}" ]]; then
      continue
    fi

    if [[ "${line}" =~ "=n" ]]; then
      local config="${line//=n/} is not set"
    else
      local config="${line}"
    fi

    if ! grep -q "${config}" ".config"; then
      echo "expected config not found: '${config}'" >&2
      exit 1
    fi
  done < "${defconfig}"
}

pushd coreboot >/dev/null
  if [ ! -d util/crossgcc/xgcc ]
  then
    make CPUS="$(nproc)" crossgcc-i386
  fi
  make distclean
  make defconfig KBUILD_DEFCONFIG="${CONFIG}"
  check_configs "${CONFIG}"

  make --jobs="$(nproc)"
  cp -v "build/coreboot.rom" "${COREBOOT}"
popd >/dev/null
