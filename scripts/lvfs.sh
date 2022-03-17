#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-3.0-only

# Generate LVFS MetaInfo from a template file.

warn() {
    echo -e "\x1B[33m$*\x1B[0m" >&2
}

error() {
    echo -e "\x1B[31m$*\x1B[0m" >&2
}

if [[ -z "$1" ]]; then
    echo "$0 <model>" >&2
    exit 1
fi
MODEL="$1"

if [[ ! -d "models/${MODEL}" ]]; then
    echo "model '${MODEL}' not found" >&2
    exit 1
fi
MODEL_DIR="$(realpath "models/${MODEL}")"

BUILD_DIR="build/${MODEL}"
if [[ ! -d "${BUILD_DIR}" ]]; then
    error "Model not built"
    exit 1
fi

export LVFS_VENDOR_NAME="${LVFS_VENDOR_NAME:-System76}"
export LVFS_VENDOR_HOMEPAGE="${LVFS_VENDOR_HOMEPAGE:-https://system76.com/}"

if [[ ! -r "${MODEL_DIR}/lvfs.config" ]]; then
    error "${MODEL} does not have an LVFS config"
    exit 1
fi
source "${MODEL_DIR}/lvfs.config"
export LVFS_DEVICE_ID
export LVFS_DEVICE_NAME
export LVFS_DEVICE_UUID

GIT_COMMIT_HASH=$(git describe --always --abbrev=12 --exclude='*')
GIT_COMMIT_URL="https://github.com/system76/firmware-open/tree/${GIT_COMMIT_HASH}"

GIT_COMMIT_RELEASE=$(git describe --always --dirty --abbrev=7 --exclude='*')
GIT_COMMIT_DATE=$(git show --format="%cd" --date="format:%Y-%m-%d" --no-patch)
BIOS_VERSION="${GIT_COMMIT_DATE}_${GIT_COMMIT_RELEASE}"

export LVFS_RELEASE_VERSION="${LVFS_RELEASE_VERSION:-${BIOS_VERSION}}"
export LVFS_RELEASE_DATE="${LVFS_RELEASE_DATE:-${GIT_COMMIT_DATE}}"

export LVFS_RELEASE_SOURCE_URL="${LVFS_RELEASE_SOURCE_URL:-${GIT_COMMIT_URL}}"
export LVFS_RELEASE_SOURCE_TAG="<url type=\"source\">${LVFS_RELEASE_SOURCE_URL}</url>"

if [[ -z "$LVFS_RELEASE_DESCRIPTION" ]]; then
    warn "LVFS_RELEASE_DESCRIPTION is not set"
fi

envsubst < "firmware.metainfo.xml.in" > "${BUILD_DIR}/firmware.metainfo.xml"

# File name must be `firmware.bin`
cp ${BUILD_DIR}/firmware.rom ${BUILD_DIR}/firmware.bin

gcab --verbose --create --nopath \
    ${BUILD_DIR}/firmware.cab \
    ${BUILD_DIR}/firmware.metainfo.xml \
    ${BUILD_DIR}/firmware.bin
