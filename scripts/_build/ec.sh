#!/usr/bin/env bash

set -e

if [ -z "$1" -o ! -e "$1" -o -z "$2" ]
then
    echo "$0 <config> <output>" >&2
    exit 1
fi

source "$1"
make -C ec clean
make -C ec BOARD=${BOARD} VERSION=${VERSION} -j $(nproc)
cp "ec/build/${BOARD}/${VERSION}/ec.rom" "$2"
