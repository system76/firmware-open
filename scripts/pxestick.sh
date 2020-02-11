#!/usr/bin/env bash

set -e

BUILD_TYPE=RELEASE
#BUILD_TYPE=DEBUG
TOOLCHAIN=GCC5

pushd edk2 >/dev/null
  make -C BaseTools --jobs="$(nproc)"
  source edksetup.sh --reconfig

  build \
    -a X64 \
    -b "${BUILD_TYPE}" \
    -t "${TOOLCHAIN}" \
    -p "OptionRomPkg/OptionRomPkg.dsc"
  DRIVER="${PWD}/Build/OptionRomPkg/${BUILD_TYPE}_${TOOLCHAIN}/X64/Ax88772.efi"

  build \
    -a X64 \
    -b "${BUILD_TYPE}" \
    -t "${TOOLCHAIN}" \
    -p "ShellPkg/ShellPkg.dsc"
  SHELL="${PWD}/Build/Shell/${BUILD_TYPE}_${TOOLCHAIN}/X64/Shell.efi"
popd >/dev/null

rm -rf build/pxestick
mkdir -p build/pxestick
cd build/pxestick

wget -O ipxe.efi http://boot.ipxe.org/ipxe.efi

cat > startup.nsh <<EOF
@echo -off

if exist "fs0:driver.efi" then
    fs0:
endif

if exist "fs1:driver.efi" then
    fs1:
endif

if exist "fs2:driver.efi" then
    fs2:
endif

if exist "fs3:driver.efi" then
    fs3:
endif

if exist "fs4:driver.efi" then
    fs4:
endif

if exist "fs5:driver.efi" then
    fs5:
endif

if exist "fs6:driver.efi" then
    fs6:
endif

if exist "fs7:driver.efi" then
    fs7:
endif

if exist "fs8:driver.efi" then
    fs8:
endif

if exist "fs9:driver.efi" then
    fs9:
endif

if not exist "driver.efi" then
    echo "Did not find driver.efi"
    exit 1
endif

load "driver.efi"
"ipxe.efi"
EOF

dd if=/dev/zero of=usb.img.partial bs=512 count=4096
mkfs.vfat usb.img.partial
mmd -i usb.img.partial efi
mmd -i usb.img.partial efi/boot
mcopy -i usb.img.partial "${SHELL}" ::efi/boot/bootx64.efi
mcopy -i usb.img.partial "${DRIVER}" ::driver.efi
mcopy -i usb.img.partial ipxe.efi ::ipxe.efi
mcopy -i usb.img.partial startup.nsh ::startup.nsh
mv usb.img.partial usb.img
