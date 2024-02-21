#!/usr/bin/env bash
#
# Copyright 2020 System76

# shellcheck disable=SC2024

set -e

SCRIPT_DIR=$(dirname "$0")

if [ -z "$1" ]
then
    echo "$0 <model> [firmware.rom] [ec.rom]" >&2
    exit 1
fi
MODEL="$1"

BIOS_IMAGE=
if [ -n "$2" ]
then
    if [ ! -f "$2" ]
    then
        echo "Could not find BIOS image '$2'" >&2
        exit 1
    fi
    BIOS_IMAGE=$(realpath "$2")
fi

EC_ROM=
if [ -n "$3" ]
then
    if [ ! -f "$3" ]
    then
        echo "Could not find EC ROM '$3'" >&2
        exit 1
    fi

    EC_ROM=$(realpath "$3")
fi

if [ ! -d "models/${MODEL}" ]
then
    echo "Generating for new model '${MODEL}'"
    mkdir "models/${MODEL}"
    read -rp "Manufacturer: " _mfr
    read -rp "Product name: " _name
    read -rp "Product version: " _version
    echo "# ${_mfr} ${_name} (${_version})" > "models/${MODEL}/README.md.in"
fi
MODEL_DIR=$(realpath "models/${MODEL}")

echo "Generating data for coreboot..."

pushd tools/coreboot-collector
cargo build --release
sudo target/release/coreboot-collector > "${MODEL_DIR}/coreboot-collector.txt"
popd

"${SCRIPT_DIR}/coreboot-gpio.sh" "${MODEL_DIR}/coreboot-collector.txt" > "${MODEL_DIR}/gpio.c"
"${SCRIPT_DIR}/coreboot-hda.sh" "${MODEL_DIR}/coreboot-collector.txt" > "${MODEL_DIR}/hda_verb.c"

if [ -n "${BIOS_IMAGE}" ]
then
    # Get the flash descriptor and Intel ME blobs
    make -C coreboot/util/ifdtool
    coreboot/util/ifdtool/ifdtool -x "${BIOS_IMAGE}"
    # TODO: Don't hardcode flash region index
    mv flashregion_0_flashdescriptor.bin "${MODEL_DIR}/fd.rom"
    mv flashregion_2_intel_me.bin "${MODEL_DIR}/me.rom"
    rm -f flashregion_*.bin
fi

# Get the Video BIOS Table and GOP driver for Intel systems
if sudo [ -e /sys/kernel/debug/dri/0/i915_vbt ]
then
    sudo cat /sys/kernel/debug/dri/0/i915_vbt > "${MODEL_DIR}/vbt.rom"

    INTEL_GOP_DRIVER_GUID="7755CA7B-CA8F-43C5-889B-E1F59A93D575"
    EXTRACT_DIR="extract"

    if [ -n "${BIOS_IMAGE}" ]
    then
        if "${SCRIPT_DIR}/extract.sh" "${BIOS_IMAGE}" "${INTEL_GOP_DRIVER_GUID}" -o "${EXTRACT_DIR}" > /dev/null
        then
            cp -v "$(find "${EXTRACT_DIR}" | grep IntelGopDriver | grep PE32 | grep body.bin)" "${MODEL_DIR}/IntelGopDriver.efi"
            rm -rf "${EXTRACT_DIR}"
        else
            echo "IntelGopDriver not present in firmware image"
        fi
    fi
fi

# XXX: More reliable way to determine if system has an EC?
DMI_CHASSIS_TYPE=$(cat /sys/class/dmi/id/chassis_type)
if [ "${DMI_CHASSIS_TYPE}" = "9" ] || [ "${DMI_CHASSIS_TYPE}" = "10" ]
then
    if [ -n "${EC_ROM}" ]
    then
        echo "Using proprietary EC ROM file"
        cp "${EC_ROM}" "${MODEL_DIR}/ec.rom"
    else
        echo "Generating output for System76 EC firmware"
        pushd ec/ecspy
        cargo build --release
        # TODO: Set backlights and fans to max and restore after
        sudo target/release/ecspy > "${MODEL_DIR}/ecspy.txt"
        # Strip EC RAM entries from output
        sed -i '/^0x/d' "${MODEL_DIR}/ecspy.txt"
        popd
    fi
fi

"${SCRIPT_DIR}/readmes.sh"
