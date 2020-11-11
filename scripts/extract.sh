#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-only

set -e

SCRIPT_DIR="$(dirname "$(readlink -f "$0")")"
TOOL_DIR="$SCRIPT_DIR/../tools"
UEFIEXTRACT_DIR="$TOOL_DIR/UEFITool/UEFIExtract"

# Make sure UEFITool submodule is checked out
if [ ! -d "$UEFIEXTRACT_DIR" ]
then
	pushd "$TOOL_DIR" >/dev/null
	git submodule update --init UEFITool
	popd >/dev/null
fi

# Make sure UEFIExtract is built
if [ ! -f "$UEFIEXTRACT_DIR/UEFIExtract" ]
then
    pushd "$UEFIEXTRACT_DIR" > /dev/null
    cmake -B . -G "Unix Makefiles" -DCMAKE_CXX_FLAGS="-Os" -DCMAKE_C_FLAGS="-Os"
    cmake --build .
    popd > /dev/null
fi

"$UEFIEXTRACT_DIR/UEFIExtract" "$@"
