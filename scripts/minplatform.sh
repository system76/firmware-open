#!/usr/bin/env bash

set -e

BUILD_TYPE=RELEASE
TOOLCHAIN=GCC5

export PACKAGES_PATH="\
$(realpath edk2-platforms/Platform/Intel):\
$(realpath edk2-platforms/Silicon/Intel):\
$(realpath edk2-non-osi/Silicon/Intel):\
$(realpath FSP)"

pushd edk2 >/dev/null
  make -C BaseTools --jobs="$(nproc)"
  source edksetup.sh --reconfig

  build \
    -a IA32 \
    -a X64 \
    -b "${BUILD_TYPE}" \
    -t "${TOOLCHAIN}" \
    -p KabylakeOpenBoardPkg/KabylakeRvp3/OpenBoardPkg.dsc
popd >/dev/null
