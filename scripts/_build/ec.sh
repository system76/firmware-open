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

source "$1"
make -C ec VERSION="${VERSION}" "${EC_ARGS[@]}" clean
make -C ec VERSION="${VERSION}" "${EC_ARGS[@]}" -j "$(nproc)"
cp "ec/build/${BOARD}/${VERSION}/ec.rom" "$2"
