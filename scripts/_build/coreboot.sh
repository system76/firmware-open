#!/usr/bin/env bash

set -e

# Use Python 3 for edk2 payload
export PYTHON_COMMAND=python3
# Use coreboot-provided GCC when building edk2 payload
export GCC_BIN="${XGCCPATH}/x86_64-elf-"
export GCCNOLTO_BIN="${XGCCPATH}/x86_64-elf-"
#export GCC_AARCH64_PREFIX="${XGCCPATH}/aarch64-elf-"
#export GCCNOLTO_AARCH64_PREFIX="${XGCCPATH}/aarch64-elf-"

if [ -z "$1" ] || [ ! -e "$1" ] || [ -z "$2" ]
then
  echo "$0 [coreboot.config] [coreboot.rom]" >&2
  exit 1
fi
CONFIG="$(realpath "$1")"
COREBOOT="$(realpath "$2")"
UEFIPAYLOAD="$(realpath "$3")"

check_configs() {
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
  make distclean
  make defconfig KBUILD_DEFCONFIG="${CONFIG}"
  check_configs "${CONFIG}"

  # Avoid re-cloning the edk2 checkout
  if [ ! -d "payloads/external/edk2/workspace/edk2" ]; then
      mkdir -p payloads/external/edk2/workspace
      ln -svr ../edk2 payloads/external/edk2/workspace/edk2
  fi

  make --jobs="$(nproc)"
  cp -v "build/coreboot.rom" "${COREBOOT}"
  cp -v "build/UEFIPAYLOAD.fd" "${UEFIPAYLOAD}"
popd >/dev/null
