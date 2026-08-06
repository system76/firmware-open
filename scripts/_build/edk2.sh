#!/usr/bin/env bash

# shellcheck disable=SC1091

set -e

if [ -z "$1" ]
then
  echo "$0 [UEFIPAYLOAD.fd] <ARGS..>" >&2
  exit 1
fi
UEFIPAYLOAD="$(realpath "$1")"

PACKAGE=UefiPayloadPkg
BUILD_ARCH=X64
BUILD_TYPE=RELEASE
TOOLCHAIN=GCC

# Use Python 3
export PYTHON_COMMAND=python3
# Use coreboot-provided GCC
export GCC_BIN="${XGCCPATH}/x86_64-elf-"
export GCCNOLTO_BIN="${XGCCPATH}/x86_64-elf-"
#export GCC_AARCH64_PREFIX="${XGCCPATH}/aarch64-elf-"
#export GCCNOLTO_AARCH64_PREFIX="${XGCCPATH}/aarch64-elf-"

pushd edk2 >/dev/null
  make -C BaseTools --jobs="$(nproc)"
  source edksetup.sh --reconfig

  build \
    -a IA32 \
    -a ${BUILD_ARCH} \
    -b "${BUILD_TYPE}" \
    -t "${TOOLCHAIN}" \
    -p "${PACKAGE}/${PACKAGE}.dsc" \
    -DBUILD_ARCH=${BUILD_ARCH} \
    "${@:2}"

  cp -v \
    "Build/${PACKAGE}${BUILD_ARCH}/${BUILD_TYPE}_${TOOLCHAIN}/FV/UEFIPAYLOAD.fd" \
    "${UEFIPAYLOAD}"
popd >/dev/null
