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

BUILD_DIR="build"

make -C ec BUILD="$BUILD_DIR" clean
make -C ec VERSION="${VERSION}" "${EC_ARGS[@]}" BUILD="$BUILD_DIR" -j "$(nproc)"
cp "ec/$BUILD_DIR/ec.rom" "$2"
