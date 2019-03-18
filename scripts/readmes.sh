#!/usr/bin/env bash

README_DIRS=(
    apps
    libs
    models
    tools
    .
)

set -e

cargo build --manifest-path "scripts/modeltool/Cargo.toml" --release

MODELTOOL="$(realpath "scripts/modeltool/target/release/modeltool")"

function readme_model {
    echo -e "\x1B[1m$1\x1B[0m" >&2

    pushd "$1" > /dev/null
        cp README.md.in README.md

        echo >> README.md
        echo "## Contents" >> README.md
        "$MODELTOOL" . >> README.md
    popd > /dev/null
}

for dir in models/*/
do
    readme_model "${dir%/}"
done

function readme_line {
    echo -e "  \x1B[1m$1\x1B[0m" >&2

    if [ -f "$1/README.md" ]
    then
        # Get first line, removing the trailing pounds and spaces
        description="$(head -n 1 "$1/README.md" | sed -e 's/^[#[:space:]]*//')"
    else
        # Use the directory name as the description
        description="$(basename "$1")"
    fi

    submodule="$(git submodule status "$1" 2> /dev/null | cut -d ' ' -f 3 || true)"
    if [ "$submodule" == "$dir" ]
    then
        # Link to submodule URL
        origin="$(git -C "$dir" remote get-url origin)"
        echo "- [$description]($origin)"
    else
        # Link to directory
        echo "- [$description](./$dir)"
    fi
}

function readme_dir {
    echo -e "\x1B[1m$1\x1B[0m" >&2

    pushd "$1" > /dev/null
        cp README.md.in README.md

        echo >> README.md
        echo "## Contents" >> README.md
        for dir in */
        do
            readme_line "${dir%/}" >> README.md
        done
    popd > /dev/null
}

for dir in "${README_DIRS[@]}"
do
    readme_dir "$dir"
done
