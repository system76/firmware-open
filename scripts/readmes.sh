#!/usr/bin/env bash

README_DIRS=(
    apps
    models
    tools
)

set -e

cargo build --manifest-path "scripts/modeltool/Cargo.toml" --release

MODELTOOL="$(realpath "scripts/modeltool/target/release/modeltool")"

readme_model() {
    echo -e "\x1B[1m$1\x1B[0m" >&2

    pushd "$1" > /dev/null
        cp README.md.in README.md

        echo -e "\n## Contents\n" >> README.md
        "$MODELTOOL" . >> README.md
    popd > /dev/null
}

for dir in models/*/
do
    readme_model "${dir%/}"
done

readme_line() {
    echo -e "  \x1B[1m$1\x1B[0m" >&2

    name="$(basename "$1")"
    description=""

    readme="$(find "$1" -maxdepth 1 -iname README.md)"
    if [ -n "$readme" ]
    then
        # Get first line, removing the trailing pounds and spaces
        description=" - $(head -n 1 "$readme" | sed -e 's/^[#[:space:]]*//')"
    fi

    submodule="$(git submodule status "$1" 2> /dev/null | cut -d ' ' -f 3 || true)"
    if [ "$submodule" = "$1" ]
    then
        # Link to submodule URL
        origin="$(git -C "$1" remote get-url origin)"
        echo "- [$name]($origin)$description"
    else
        # Link to directory
        echo "- [$name](./$1)$description"
    fi
}

readme_dir() {
    echo -e "\x1B[1m$1\x1B[0m" >&2

    pushd "$1" > /dev/null
        cp README.md.in README.md

        echo -e "\n## Contents\n" >> README.md
        for dir in */
        do
            if ! git check-ignore --quiet "${dir}"
            then
                readme_line "${dir%/}" >> README.md
            fi
        done
    popd > /dev/null
}

for dir in "${README_DIRS[@]}"
do
    readme_dir "$dir"
done
