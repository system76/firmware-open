#!/usr/bin/env bash

set -eE

function msg {
  echo -e "\x1B[1m$*\x1B[0m" >&2
}

trap 'msg "\x1B[31mFailed to install dependencies!"' ERR

if which apt-get > /dev/null
then
  msg "Installing system build dependencies"
  sudo apt-get install \
    build-essential \
    bison \
    ccache \
    flex \
    git-lfs \
    gnat \
    mtools \
    nasm \
    python \
    python3-distutils \
    sdcc \
    uuid-dev \
    zlib1g-dev
else
  msg "Please add support for your distribution to:"
  msg "scripts/deps.sh"
  exit 1
fi

msg "Installing GIT LFS hooks"
git lfs install

msg "Downloading GIT LFS artifacts"
git lfs pull

msg "Installing Rust"
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs \
  | sh -s -- -y --default-toolchain nightly

msg "Loading Rust environment"
source ~/.cargo/env

msg "Installing pinned Rust toolchain"
rustup toolchain install "$(cat rust-toolchain)"

msg "Installing source for pinned Rust toolchain"
rustup component add --toolchain "$(cat rust-toolchain)" rust-src

if ! which cargo-xbuild > /dev/null
then
  msg "Installing cargo-xbuild"
  cargo +nightly install cargo-xbuild --version=0.5.29
fi

msg "\x1B[32mSuccessfully installed dependencies"
echo "Ready to run ./scripts/build.sh [model]" >&2
