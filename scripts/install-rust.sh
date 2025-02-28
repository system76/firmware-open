#!/bin/sh
# SPDX-License-Identifier: GPL-3.0-only

# Install Rust via rustup, along with the pinned toolchain.

# shellcheck shell=dash
# shellcheck disable=SC1091

set -Ee

RUSTUP_NEW_INSTALL=0

# NOTE: rustup is used to allow multiple toolchain installations.
if ! command -v rustup >/dev/null 2>&1; then
    RUSTUP_NEW_INSTALL=1
    curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs \
        | sh -s -- -y --default-toolchain stable

    . "${HOME}/.cargo/env"
fi

rustup show active-toolchain || rustup toolchain install

if [ "$RUSTUP_NEW_INSTALL" = "1" ]; then
    printf "\e[33m>> rustup was just installed. Ensure cargo is on the PATH with:\e[0m\n"
    printf "    source ~/.cargo/env\n\n"
fi
