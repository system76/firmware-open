#!/usr/bin/env bash

# Create a USB image file that can be written to a USB flash drive to update
# firmware on another computer.

if [ -z "$1" ]; then
    echo "$0 <model>" >&2
    exit 1
fi
MODEL="$1"

if [ "${MODEL}" = "qemu" ]; then
    echo "can't build USB image for flashing QEMU" >&2
    exit 1
fi

if [ ! -d "models/${MODEL}" ]; then
    echo "model '${MODEL}' not found" >&2
    exit 1
fi
MODEL_DIR="$(realpath "models/${MODEL}")"

DATE="$(git show --format="%cd" --date="format:%Y-%m-%d" --no-patch --no-show-signature)"
REV="$(git describe --always --dirty --abbrev=7)"
VERSION="${DATE}_${REV}"

BUILD="$(realpath "build/${MODEL}")"
if [ ! -e "${BUILD}/firmware.rom" ]; then
    echo "'${BUILD}/firmware.rom' not found" >&2
    exit 1
fi

USB="${BUILD}/usb.img"

# Rebuild firmware-update
export BASEDIR="system76_${MODEL}_${VERSION}"
make -C apps/firmware-update "build/x86_64-unknown-uefi/boot.img"
cp -v "apps/firmware-update/build/x86_64-unknown-uefi/boot.img" "${USB}.partial"

# Copy firmware to USB image
mmd -i "${USB}.partial@@1M" "::${BASEDIR}/firmware"
mcopy -v -i "${USB}.partial@@1M" "${COREBOOT}" "::${BASEDIR}/firmware/firmware.rom"
if [ -e "${BUILD}/ec.rom" ]; then
    mcopy -v -i "${USB}.partial@@1M" "${BUILD}/ec.rom" "::${BASEDIR}/firmware/ec.rom"
elif [ -e "${MODEL_DIR}/ec.rom" ]; then
    mcopy -v -i "${USB}.partial@@1M" "${MODEL_DIR}/ec.rom" "::${BASEDIR}/firmware/ec.rom"
fi
if [ -e "${MODEL_DIR}/uecflash.efi" ]; then
    mcopy -v -i "${USB}.partial@@1M" "${MODEL_DIR}/uecflash.efi" "::${BASEDIR}/firmware/uecflash.efi"
fi
mv -v "${USB}.partial" "${USB}"
