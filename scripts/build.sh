#!/usr/bin/env bash

set -e

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

DATE="$(git show --format="%cd" --date="format:%Y-%m-%d" --no-patch)"
REV="$(git describe --always --dirty)"
VERSION="${DATE}_${REV}"
echo "Building '${VERSION}' for '${MODEL}'"

# Clean build directory
mkdir -p build
BUILD="$(realpath "build/${MODEL}")"
rm -rf "${BUILD}"
mkdir -p "${BUILD}"

UEFIPAYLOAD="${BUILD}/UEFIPAYLOAD.fd"
COREBOOT="${BUILD}/coreboot.rom"
USB="${BUILD}/usb.img"
EDK2_ARGS=(
    -D USE_HPET_TIMER=FALSE
    -D SHELL_TYPE=NONE
    -D SOURCE_DEBUG_ENABLE=FALSE
)

# Rebuild firmware-setup (used by edk2)
touch apps/firmware-setup/Cargo.toml
make -C apps/firmware-setup
EDK2_ARGS+=(
    -D FIRMWARE_OPEN_FIRMWARE_SETUP="firmware-setup/firmware-setup.inf"
)

# Rebuild firmware-smmstore (used by edk2)
if [ "${MODEL}" != "qemu" ]
then
    touch apps/firmware-smmstore/Cargo.toml
    make -C apps/firmware-smmstore
    EDK2_ARGS+=(
        -D FIRMWARE_OPEN_FIRMWARE_SMMSTORE="firmware-smmstore/firmware-smmstore.inf"
    )
fi

# Rebuild gop-policy (used by edk2)
if [ -e "${MODEL_DIR}/IntelGopDriver.inf" -a -e "${MODEL_DIR}/vbt.rom" ]
then
    touch apps/gop-policy/Cargo.toml
    FIRMWARE_OPEN_VBT="${MODEL_DIR}/vbt.rom" \
        make -C apps/gop-policy
    EDK2_ARGS+=(
        -D FIRMWARE_OPEN_GOP_POLICY="gop-policy/gop-policy.inf"
        -D FIRMWARE_OPEN_GOP="IntelGopDriver.inf"
    )
fi

# Rebuild CorebootPayloadPkg using edk2
PACKAGES_PATH="${MODEL_DIR}:$(realpath edk2-platforms):$(realpath apps)" \
    ./scripts/_build/edk2.sh \
        "${UEFIPAYLOAD}" \
        "${EDK2_ARGS[@]}"

# Rebuild coreboot
FIRMWARE_OPEN_MODEL_DIR="${MODEL_DIR}" \
FIRMWARE_OPEN_UEFIPAYLOAD="${UEFIPAYLOAD}" \
KERNELVERSION="${VERSION}" \
    ./scripts/_build/coreboot.sh \
        "${MODEL_DIR}/coreboot.config" \
        "${COREBOOT}"

# Rebuild EC firmware for System76 EC models
if [ ! -e  "${MODEL_DIR}/ec.rom" -a -e "${MODEL_DIR}/ec.config" ]
then
    env VERSION="${VERSION}" \
        ./scripts/_build/ec.sh \
        "${MODEL_DIR}/ec.config" \
        "${BUILD}/ec.rom"
fi

if [ "${MODEL}" != "qemu" ]
then
    # Rebuild firmware-update
    SHASUM="$(sha384sum "${COREBOOT}" | cut -d " " -f 1)"
    export BASEDIR="system76-${SHASUM}"
    pushd apps/firmware-update >/dev/null
      rm -rf "build/x86_64-efi-pe"
      make "build/x86_64-efi-pe/boot.img"
      cp -v "build/x86_64-efi-pe/boot.img" "${USB}.partial"
    popd >/dev/null

    # Copy firmware to USB image
    mmd -i "${USB}.partial@@1M" "::${BASEDIR}/firmware"
    mcopy -i "${USB}.partial@@1M" "${COREBOOT}" "::${BASEDIR}/firmware/firmware.rom"
    if [ -e "${MODEL_DIR}/ec.rom" -a -e "${MODEL_DIR}/uecflash.efi" ]
    then
        mcopy -i "${USB}.partial@@1M" "${MODEL_DIR}/ec.rom" "::${BASEDIR}/firmware/ec.rom"
        mcopy -i "${USB}.partial@@1M" "${MODEL_DIR}/uecflash.efi" "::${BASEDIR}/firmware/uecflash.efi"
    fi
    mv -v "${USB}.partial" "${USB}"
fi

echo "Built '${VERSION}' for '${MODEL}'"
