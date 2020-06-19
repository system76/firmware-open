#!/usr/bin/env bash

set -e

PATH="$PATH:/usr/sbin"

rm -rf build/pxestick
mkdir -p build/pxestick

make -C tools/ipxe/src bin-x86_64-efi/axge.efi -j "$(nproc)"
cp tools/ipxe/src/bin-x86_64-efi/axge.efi build/pxestick/ipxe.efi

cd build/pxestick

dd if=/dev/zero of=usb.img.partial bs=512 count=2048
mkfs.vfat usb.img.partial
mmd -i usb.img.partial efi
mmd -i usb.img.partial efi/boot
mcopy -i usb.img.partial ipxe.efi ::efi/boot/bootx64.efi
mv usb.img.partial usb.img

if [ -b "$1" ]
then
    sudo popsicle -u usb.img "$1"
fi
