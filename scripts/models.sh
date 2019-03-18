#!/usr/bin/env bash

set -e

cargo build --manifest-path "scripts/modeltool/Cargo.toml" --release

MODELTOOL="$(realpath "scripts/modeltool/target/release/modeltool")"

for dir in models/*/
do
    pushd "$dir" > /dev/null
    model="$(basename "$dir")"
    echo -e "\x1B[1m$model\x1B[0m"
    cp README.md.in README.md
    echo "## Firmware Versions" >> README.md
    "$MODELTOOL" . | tee -a README.md
    popd > /dev/null
done
