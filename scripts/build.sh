#!/usr/bin/env bash

set -e

export XGCCPATH="${XGCCPATH:-$PWD/coreboot/util/crossgcc/xgcc/bin}"
export PATH="$XGCCPATH:$PATH:/usr/sbin"

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

DATE="$(git show --format="%cd" --date="format:%Y-%m-%d" --no-patch --no-show-signature)"
REV="$(git describe --always --dirty --abbrev=7)"
VERSION="${DATE}_${REV}"
echo "Building '${VERSION}' for '${MODEL}'"

# Clean build directory
mkdir -p build
BUILD="$(realpath "build/${MODEL}")"
rm -rf "${BUILD}"
mkdir -p "${BUILD}"

# Rebuild firmware-setup (used by edk2)
make -C apps/firmware-setup
EDK2_CUSTOM_BUILD_PARAMS+=(
    -D FIRMWARE_OPEN_FIRMWARE_SETUP="firmware-setup/firmware-setup.inf"
)

# Rebuild gop-policy (used by edk2)
if [ -e "${MODEL_DIR}/IntelGopDriver.efi" ] && [ -e "${MODEL_DIR}/vbt.rom" ]
then
    make -C apps/gop-policy
    EDK2_CUSTOM_BUILD_PARAMS+=(
        -D FIRMWARE_OPEN_GOP_POLICY="gop-policy/gop-policy.inf"
    )
fi

# Rebuild coreboot and edk2 payload
# NOTE: coreboot expects paths to be relative to it
PACKAGES_PATH="${MODEL_DIR}:$(realpath apps)" \
FIRMWARE_OPEN_MODEL_DIR="../models/${MODEL}" \
KERNELVERSION="${VERSION}" \
    ./scripts/_build/coreboot.sh \
        "${MODEL_DIR}/coreboot.config" \
        "${BUILD}/firmware.rom" \
        "${BUILD}/UEFIPAYLOAD.fd"

# Rebuild EC firmware for System76 EC models
if [ ! -e  "${MODEL_DIR}/ec.rom" ] && [ -e "${MODEL_DIR}/ec.config" ]
then
    env VERSION="${VERSION}" \
        ./scripts/_build/ec.sh \
        "${MODEL_DIR}/ec.config" \
        "${BUILD}/ec.rom"
fi

echo "Built '${VERSION}' for '${MODEL}'"
