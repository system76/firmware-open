#!/usr/bin/env bash

set -e

cargo build --release -p modeltool

readme_model() {
    echo -e "\x1B[1m$1\x1B[0m" >&2

    pushd "$1" > /dev/null
        cp README.md.in README.md

        echo -e "\n## Contents\n" >> README.md
        cargo run --release -q -p modeltool . >> README.md
    popd > /dev/null
}

for dir in models/*/
do
    readme_model "${dir%/}"
done
