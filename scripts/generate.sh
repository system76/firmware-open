#!/usr/bin/env bash
#
# Copyright 2020 System76

set -e

SCRIPT_DIR=$(dirname "$0")

if [ -z "$1" ] || [ -z "$2" ]
then
    echo "$0 <model> <firmware.rom> [ec.rom]" >&2
    exit 1
fi
MODEL="$1"

if [ ! -f "$2" ]
then
    echo "Could not find BIOS image '$2'" >&2
    exit 1
fi
BIOS_IMAGE=$(realpath "$2")

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
    read -rp "Produce name: " _name
    read -rp "Product version: " _version
    echo "# ${_mfr} ${_name} (${_version})" > "models/${MODEL}/README.md.in"
fi
MODEL_DIR=$(realpath "models/${MODEL}")

echo "Generating data for coreboot..."

cargo build --release --manifest-path=tools/coreboot-collector/Cargo.toml
sudo ./tools/coreboot-collector/target/release/coreboot-collector > "${MODEL_DIR}/coreboot-collector.txt"

${SCRIPT_DIR}/coreboot-gpio.sh "${MODEL_DIR}/coreboot-collector.txt" > "${MODEL_DIR}/gpio.h"
${SCRIPT_DIR}/coreboot-hda.sh "${MODEL_DIR}/coreboot-collector.txt" > "${MODEL_DIR}/hda_verb.c"

# Get the flash descriptor and Intel ME blobs
make -C coreboot/util/ifdtool
coreboot/util/ifdtool/ifdtool -x "${BIOS_IMAGE}"
# TODO: Don't hardcode flash region index
mv flashregion_0_flashdescriptor.bin "${MODEL_DIR}/fd.rom"
mv flashregion_2_intel_me.bin "${MODEL_DIR}/me.rom"
rm -f flashregion_*.bin

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
        cargo build --release --manifest-path=ec/ecspy/Cargo.toml
        # TODO: Set backlights and fans to max and restore after
        sudo ./ec/ecspy/target/release/ecspy > "${MODEL_DIR}/ecspy.txt"
        # Strip EC RAM entries from output
        sed -i '/^0x/d' "${MODEL_DIR}/ecspy.txt"
    fi
fi

${SCRIPT_DIR}/readmes.sh
