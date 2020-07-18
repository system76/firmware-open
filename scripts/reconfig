#!/usr/bin/env bash

set -e

rm -rf build
for config in models/*/coreboot.config
do
    model="$(basename "$(dirname "$config")")"
    echo -e "\e[1m$model\e[0m"
    make -C coreboot distclean
    cp -v "$config" coreboot/.config
    make -C coreboot oldconfig
    cp -v coreboot/.config "$config"
done

echo -e "\e[1mReconfig complete, please commit changes\e[0m"
