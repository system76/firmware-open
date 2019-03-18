#!/usr/bin/env bash

READMES=(
    "apps Applications"
    "libs Libraries"
    "models Models"
    "tools Tools"
)

function recursive_readme {
    pushd "$1" > /dev/null
    echo -e "\x1B[1m$1\x1B[0m"
    echo "# $2" > README.md
    for readme in */README.md
    do
        # Get first line, removing the trailing pounds and spaces
        description="$(head -n 1 "$readme" | sed -e 's/^[#[:space:]]*//')"
        # Get submodule, if applicable
        dir="$(dirname "$readme")"
        submodule="$(git submodule status "$dir" | cut -d ' ' -f 3)"
        if [ "$submodule" == "$dir" ]
        then
            origin="$(git -C "$dir" remote get-url origin)"
            echo "- [$description]($origin)" >> README.md
        else
            echo "- [$description](./$readme)" >> README.md
        fi
    done
    popd > /dev/null
}

for readme in "${READMES[@]}"
do
    recursive_readme $readme
done
