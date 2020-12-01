#!/usr/bin/env bash

shopt -s nullglob
set -ex

I2C_PCI_SYSFS="/sys/bus/pci/devices/0000:00:15.1"
I2C_SYSFS="$(echo "${I2C_PCI_SYSFS}/i2c_designware."*"/i2c-"*)"
I2C_DEV="/dev/$(basename "${I2C_SYSFS}")"

make -C eeprog-0.7.6-tear12
sudo ./eeprog-0.7.6-tear12/eeprog "${I2C_DEV}" 0x50 -r 0 -o eeprom.rom
