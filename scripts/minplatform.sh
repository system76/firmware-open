#!/usr/bin/env bash

set -e

if [ -z "$1" ]
then
  echo "$0 [model]" >&2
  exit 1
fi
MODEL="$1"

if [ ! -d "models/${MODEL}" ]
then
  echo "model '${MODEL}' not found" >&2
  exit 1
fi
MODEL_DIR="$(realpath "models/${MODEL}")"

case "${MODEL}" in
  galp3 | galp3-b)
    PLATFORM=GalagoPro3
    ;;
  *)
    echo "model '${MODEL}' has no matching platform" >&2
    exit 1
    ;;
esac

rm -rf "build/${MODEL}"
mkdir -p "build/${MODEL}"

# Copy correct VBT
mkdir -p "build/${MODEL}/${PLATFORM}/Gop"
cp -v "models/${MODEL}/vbt.rom" "build/${MODEL}/${PLATFORM}/Gop/Vbt.bin"

export PACKAGES_PATH="\
$(realpath "build/${MODEL}"):\
$(realpath edk2-platforms/Platform/Intel):\
$(realpath edk2-platforms/Silicon/Intel):\
$(realpath edk2-non-osi/Silicon/Intel):\
$(realpath FSP)"

pushd edk2 >/dev/null
  make -C BaseTools --jobs="$(nproc)"
  source edksetup.sh --reconfig
popd >/dev/null

pushd edk2-platforms/Platform/Intel >/dev/null
  python3 build_bios.py \
    --platform "${PLATFORM}" \
    --RELEASE
popd >/dev/null
