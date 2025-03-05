#!/usr/bin/env bash

if [ -z "$1" ]
then
  echo "$0 <model>" >&2
  exit 1
fi
MODEL="$1"
if [ ! -d "models/${MODEL}" ]
then
  echo "model '${MODEL}' not found" >&2
  exit 1
fi
MODEL_DIR="$(realpath "models/${MODEL}")"

if [ ! -e "${MODEL_DIR}/firmware.rom" ]
then
  echo "No firmware built for '${MODEL}' (use 'build.sh ${MODEL}' first)" >&2
  exit 1
fi

if [ "${MODEL}" == "qemu" ]
then
  echo "Can't build a USB image for QEMU"
  exit 1
fi

# Rebuild firmware-update
export BASEDIR="system76_${MODEL}_${VERSION}"
pushd apps/firmware-update >/dev/null
  make "build/x86_64-unknown-uefi/boot.img"
  cp -v "build/x86_64-unknown-uefi/boot.img" "${USB}.partial"
popd >/dev/null

# Copy firmware to USB image
mmd -i "${USB}.partial@@1M" "::${BASEDIR}/firmware"
mcopy -v -i "${USB}.partial@@1M" "${COREBOOT}" "::${BASEDIR}/firmware/firmware.rom"
if [ -e "${BUILD}/ec.rom" ]
then
    mcopy -v -i "${USB}.partial@@1M" "${BUILD}/ec.rom" "::${BASEDIR}/firmware/ec.rom"
elif [ -e "${MODEL_DIR}/ec.rom" ]
then
    mcopy -v -i "${USB}.partial@@1M" "${MODEL_DIR}/ec.rom" "::${BASEDIR}/firmware/ec.rom"
fi
if [ -e "${MODEL_DIR}/uecflash.efi" ]
then
    mcopy -v -i "${USB}.partial@@1M" "${MODEL_DIR}/uecflash.efi" "::${BASEDIR}/firmware/uecflash.efi"
fi
mv -v "${USB}.partial" "${USB}"
