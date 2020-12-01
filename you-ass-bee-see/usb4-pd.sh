#!/usr/bin/env bash

set -ex

gcc -o eeprom eeprom.c
./eeprom -f usb4-pd.rom -r
