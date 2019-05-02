#!/usr/bin/env bash

set -e

if [ -z "$1" ]
then
  echo "$0 [model]" >&2
  exit 1
fi
MODEL="$1"

if [ ! -d "models/${MODEL}" ]
then
  echo "model '${MODEL}' not found" >&2
  exit 1
fi
MODEL_DIR="$(realpath "models/${MODEL}")"

rm -rf build
mkdir -p build

# Rebuild firmware-setup (used by edk2)
touch apps/firmware-setup/Cargo.toml
make -C apps/firmware-setup

# Rebuild CorebootPayloadPkg using edk2
export
./scripts/_build/edk2.sh build/UEFIPAYLOAD.fd \
  -D FIRMWARE_OPEN_FIRMWARE_SETUP="firmware-setup/firmware-setup.inf"

# Rebuild coreboot
export FIRMWARE_OPEN_UEFIPAYLOAD="$(realpath build/UEFIPAYLOAD.fd)"
export FIRMWARE_OPEN_MODEL_DIR="${MODEL_DIR}"
COREBOOT="$(realpath "build/${MODEL}.rom")"
./scripts/_build/coreboot.sh "${MODEL_DIR}/coreboot.config" "${COREBOOT}"

# Rebuild firmware-update
set -x
SHASUM="$(sha384sum "${COREBOOT}" | cut -d " " -f 1)"
USB="$(realpath "build/${MODEL}.img")"
export BASEDIR="system76-${SHASUM}"
pushd apps/firmware-update >/dev/null
  rm -rf "build/x86_64-efi-pe"
  make "build/x86_64-efi-pe/boot.img"
  cp -v "build/x86_64-efi-pe/boot.img" "${USB}.partial"
popd >/dev/null
mmd -i "${USB}.partial@@1M" "::${BASEDIR}/firmware"
mcopy -i "${USB}.partial@@1M" "${COREBOOT}" "::${BASEDIR}/firmware/firmware.rom"
mv -v "${USB}.partial" "${USB}"
