#!/bin/sh
# SPDX-License-Identifier: GPL-3.0-only

# Install Rust via rustup, along with the pinned toolchain.

# shellcheck shell=dash
# shellcheck disable=SC1091

set -Ee

if ! command -v rustup >/dev/null 2>&1; then
    if command -v rustup-init >/dev/null 2>&1; then
        rustup-init -y \
            --default-toolchain stable \
            --profile minimal \
            --no-update-default-toolchain
    else
        curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs \
            | sh -s -- -y --default-toolchain stable
    fi

    . "${HOME}/.cargo/env"
fi

rustup show active-toolchain || rustup toolchain install
