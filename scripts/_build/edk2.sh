#!/usr/bin/env bash

set -e

if [ -z "$1" ]
then
  echo "$0 [UEFIPAYLOAD.fd] <ARGS..>" >&2
  exit 1
fi
UEFIPAYLOAD="$(realpath "$1")"

PACKAGE=UefiPayloadPkg
BUILD_TYPE=RELEASE
#BUILD_TYPE=DEBUG
TOOLCHAIN=COREBOOT

COREBOOT_TOOLS_DEF="${PWD}/coreboot/payloads/external/tianocore/tools_def.txt"
export GCC_CC_x86_32="${PWD}/coreboot/util/crossgcc/xgcc/bin/i386-elf-gcc"
export GCC_CC_x86_64="${PWD}/coreboot/util/crossgcc/xgcc/bin/x86_64-elf-gcc"
export OBJCOPY_x86_32="${PWD}/coreboot/util/crossgcc/xgcc/bin/i386-elf-objcopy"
export OBJCOPY_x86_64="${PWD}/coreboot/util/crossgcc/xgcc/bin/x86_64-elf-objcopy"
export NASM_PREFIX="${PWD}/coreboot/util/crossgcc/xgcc/bin/"

# Force use of python3
export PYTHON_COMMAND=python3

pushd edk2 >/dev/null
  make -C BaseTools --jobs="$(nproc)"
  source edksetup.sh --reconfig
  cat "${COREBOOT_TOOLS_DEF}" >> Conf/tools_def.txt

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
