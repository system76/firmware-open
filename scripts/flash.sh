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

DMI_MODEL="$(cat /sys/class/dmi/id/product_version)"
if [ "${DMI_MODEL}" != "${MODEL}" ]
then
    echo "Refusing to flash model '${MODEL}' to model '${DMI_MODEL}'" >&2
    exit 1
fi

# Define base directory for firmware-update
export BASEDIR="system76-firmware-update"

# Clean build directory
mkdir -p build
BUILD="$(realpath "build/${MODEL}")"
rm -rf "${BUILD:?}/${BASEDIR}"
mkdir -p "${BUILD}/${BASEDIR}"

# Rebuild and copy firmware-update
pushd apps/firmware-update >/dev/null
    rm -rf "build/x86_64-unknown-uefi"
    make "build/x86_64-unknown-uefi/boot.efi"
    cp -v "build/x86_64-unknown-uefi/boot.efi" "${BUILD}/${BASEDIR}"
    cp -rv "res" "${BUILD}/${BASEDIR}"
popd >/dev/null

# Copy firmware
mkdir -p "${BUILD}/${BASEDIR}/firmware"
cp -v "${BUILD}/firmware.rom" "${BUILD}/${BASEDIR}/firmware"
if [ -f "${BUILD}/ec.rom" ]
then
    cp -v "${BUILD}/ec.rom" "${BUILD}/${BASEDIR}/firmware"
fi

# Locate EFI partition mount path
EFI_PATH="$(bootctl --print-esp-path)"
if [ -z "${EFI_PATH}" ] || [ ! -d "${EFI_PATH}" ]
then
    echo "EFI system partition '${EFI_PATH}' not found" >&2
    exit 1
fi

# Locate EFI partition
EFI_PART_NAME="$(awk '$2 == "'"${EFI_PATH}"'"' /proc/mounts | awk '{print $1}' | awk -F/ '{print $3}')"
if [ -z "${EFI_PART_NAME}" ]
then
    echo "EFI system partition name not found" >&2
    exit 1
fi
EFI_PART="$(cat "/sys/class/block/${EFI_PART_NAME}/partition")"

# Locate EFI disk
EFI_DISK=""
for block in /sys/block/*; do
    if test -e "${block}/${EFI_PART_NAME}"
    then
        EFI_DISK="/dev/$(basename "${block}")"
        break
    fi
done
if [ -z "${EFI_DISK}" ]
then
    echo "EFI system partition disk device not found" >&2
    exit 1
fi

# Install to EFI_PATH
sudo rsync -rv --delete "${BUILD}/${BASEDIR}/" "${EFI_PATH}/${BASEDIR}/"

# Ensure boot num is deleted
if [ -f /sys/firmware/efi/efivars/Boot1776-8be4df61-93ca-11d2-aa0d-00e098032b8c ]
then
    sudo efibootmgr --quiet --bootnum 1776 --delete-bootnum
fi

# Add entry to EFI boot variables
sudo efibootmgr \
    --quiet \
    --create \
    --bootnum 1776 \
    --disk "${EFI_DISK}" \
    --part "${EFI_PART}" \
    --loader "\\${BASEDIR}\\boot.efi" \
    --label "${BASEDIR}"

# Set entry as next boot item
sudo efibootmgr --quiet --bootnext 1776

echo "Reboot to flash firmware"
