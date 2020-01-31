#!/usr/bin/env bash

set -e

rm -rf build/pxestick
mkdir -p build/pxestick
cd build/pxestick

wget -O ipxe.efi http://boot.ipxe.org/ipxe.efi
dd if=/dev/zero of=usb.img.partial bs=512 count=2048
mkfs.vfat usb.img.partial
mmd -i usb.img.partial efi
mmd -i usb.img.partial efi/boot
mcopy -i usb.img.partial ipxe.efi ::efi/boot/bootx64.efi
mv usb.img.partial usb.img
