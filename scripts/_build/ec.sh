#!/usr/bin/env bash

set -e

if [ -z "$1" -o ! -e "$1" -o -z "$2" ]
then
    echo "$0 <config> <output>" >&2
    exit 1
fi

EC_ARGS=()
while read line; do
    if [[ "$line" != "#"* ]]; then
        EC_ARGS+=("$line")
    fi
done < "$1"

make -C ec clean
make -C ec VERSION="${VERSION}" "${EC_ARGS[@]}" BUILD=build -j "$(nproc)"
cp "ec/build/ec.rom" "$2"
