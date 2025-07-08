#!/usr/bin/env bash

# shellcheck disable=SC1091

set -e

if [ -z "$1" ]
then
  echo "$0 [UEFIPAYLOAD.fd] <ARGS..>" >&2
  exit 1
fi
UEFIPAYLOAD="$(realpath "$1")"

PACKAGE=System76PayloadPkg
BUILD_ARCH=X64
BUILD_TYPE=RELEASE
TOOLCHAIN=COREBOOT

COREBOOT_TOOLS_DEF="$XGCCPATH/../share/edk2config/tools_def.txt"

# Force use of python3
export PYTHON_COMMAND=python3

pushd edk2 >/dev/null
  make -C BaseTools --jobs="$(nproc)"
  source edksetup.sh --reconfig
  cat "${COREBOOT_TOOLS_DEF}" >> Conf/tools_def.txt

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
