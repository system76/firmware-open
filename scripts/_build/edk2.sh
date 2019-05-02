#!/usr/bin/env bash

set -e

if [ -z "$1" ]
then
  echo "$0 [UEFIPAYLOAD.fd]" >&2
  exit 1
fi
UEFIPAYLOAD="$(realpath "$1")"

BUILD_TYPE=RELEASE
TOOLCHAIN=GCC5

export PACKAGES_PATH="$(realpath edk2-platforms):$(realpath apps)"

pushd edk2 >/dev/null
  make -C BaseTools --jobs="$(nproc)"
  source edksetup.sh --reconfig

  build \
    -a IA32 \
    -a X64 \
    -b "${BUILD_TYPE}" \
    -t "${TOOLCHAIN}" \
    -p CorebootPayloadPkg/CorebootPayloadPkgIa32X64.dsc

  cp -v \
    "Build/CorebootPayloadPkgX64/${BUILD_TYPE}_${TOOLCHAIN}/FV/UEFIPAYLOAD.fd" \
    "${UEFIPAYLOAD}"
popd >/dev/null
