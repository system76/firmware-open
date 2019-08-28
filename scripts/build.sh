#!/usr/bin/env bash

set -e

if [ -z "$1" ]
then
  echo "$0 [model]" >&2
  exit 1
fi
MODEL="$1"

if [ ! -d "models/$1" ]
then
  echo "model '$1' not found" >&2
  exit 1
fi
MODEL_DIR="$(realpath "models/${MODEL}")"

# Clean build directory
mkdir -p build
BUILD="$(realpath "build/${MODEL}")"
rm -rf "${BUILD}"
mkdir -p "${BUILD}"

UEFIPAYLOAD="${BUILD}/UEFIPAYLOAD.fd"
COREBOOT="${BUILD}/coreboot.rom"
USB="${BUILD}/usb.img"

# Rebuild firmware-setup (used by edk2)
touch apps/firmware-setup/Cargo.toml
make -C apps/firmware-setup

# Rebuild gop-policy (used by edk2)
touch apps/gop-policy/Cargo.toml
FIRMWARE_OPEN_VBT="${MODEL_DIR}/vbt.rom" \
    make -C apps/gop-policy

# Rebuild CorebootPayloadPkg using edk2
PACKAGES_PATH="${MODEL_DIR}:$(realpath edk2-platforms):$(realpath apps)" \
    ./scripts/_build/edk2.sh \
        "${UEFIPAYLOAD}" \
        -D USE_HPET_TIMER=TRUE \
        -D SOURCE_DEBUG_ENABLE=FALSE \
        -D FIRMWARE_OPEN_FIRMWARE_SETUP="firmware-setup/firmware-setup.inf" \
        -D FIRMWARE_OPEN_GOP_POLICY="gop-policy/gop-policy.inf" \
        -D FIRMWARE_OPEN_GOP="IntelGopDriver.inf"

# Rebuild coreboot
FIRMWARE_OPEN_MODEL_DIR="${MODEL_DIR}" \
FIRMWARE_OPEN_UEFIPAYLOAD="${UEFIPAYLOAD}" \
    ./scripts/_build/coreboot.sh \
        "${MODEL_DIR}/coreboot.config" \
        "${COREBOOT}"

# Rebuild firmware-update
SHASUM="$(sha384sum "${COREBOOT}" | cut -d " " -f 1)"
export BASEDIR="system76-${SHASUM}"
pushd apps/firmware-update >/dev/null
  rm -rf "build/x86_64-efi-pe"
  make "build/x86_64-efi-pe/boot.img"
  cp -v "build/x86_64-efi-pe/boot.img" "${USB}.partial"
popd >/dev/null
mmd -i "${USB}.partial@@1M" "::${BASEDIR}/firmware"
mcopy -i "${USB}.partial@@1M" "${MODEL_DIR}/ec.rom" "::${BASEDIR}/firmware/ec.rom"
mcopy -i "${USB}.partial@@1M" "${COREBOOT}" "::${BASEDIR}/firmware/firmware.rom"
mv -v "${USB}.partial" "${USB}"
