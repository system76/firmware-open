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

  if [[ "$@" =~ "SECURE_BOOT_ENABLE=TRUE" ]]; then
    # Build the Secure Boot FV
    build \
      -a IA32 \
      -a X64 \
      -b "${BUILD_TYPE}" \
      -t "${TOOLCHAIN}" \
      -p "UefiVariableBinary/UefiVariableBinary.dsc"

    # TODO: Fix where the FV is stored.
    cp -v \
      "Build/UefiVariableBinary/${BUILD_TYPE}_${TOOLCHAIN}/FV/SECUREBOOT.Fv" \
      "UefiVariableBinary/"
  fi

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
