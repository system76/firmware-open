#!/usr/bin/env bash

set -e

if [ -z "$1" ]
then
  echo "$0 [UEFIPAYLOAD.fd] <ARGS..>" >&2
  exit 1
fi
UEFIPAYLOAD="$(realpath "$1")"

#PACKAGE=CorebootPayloadPkg
PACKAGE=UefiPayloadPkg
BUILD_TYPE=RELEASE
#BUILD_TYPE=DEBUG
TOOLCHAIN=GCC5

# Force use of python3
export PYTHON_COMMAND=python3

pushd edk2 >/dev/null
  make -C BaseTools --jobs="$(nproc)"
  source edksetup.sh --reconfig

  build \
    -a IA32 \
    -a X64 \
    -b "${BUILD_TYPE}" \
    -t "${TOOLCHAIN}" \
    -p "${PACKAGE}/${PACKAGE}.dsc" \
    "${@:2}"

  cp -v \
    "Build/${PACKAGE}X64/${BUILD_TYPE}_${TOOLCHAIN}/FV/UEFIPAYLOAD.fd" \
    "${UEFIPAYLOAD}"
popd >/dev/null
