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
    avr-libc \
    avrdude \
    build-essential \
    bison \
    ccache \
    curl \
    dosfstools \
    flashrom \
    flex \
    gcc-avr \
    git-lfs \
    gnat \
    libncurses-dev \
    mtools \
    nasm \
    parted \
    python \
    python3-distutils \
    sdcc \
    uuid-dev \
    zlib1g-dev
elif which dnf > /dev/null
then
  msg "Installing system build dependencies"
  sudo dnf group install c-development
  sudo dnf install \
    avr-gcc \
    avr-libc \
    avrdude \
    curl \
    dosfstools \
    flashrom \
    gcc-gnat \
    git-lfs \
    libuuid-devel \
    mtools \
    nasm \
    ncurses-devel \
    parted \
    patch \
    sdcc \
    zlib-devel
else
  msg "Please add support for your distribution to:"
  msg "scripts/deps.sh"
  exit 1
fi

msg "Installing GIT LFS hooks"
git lfs install

msg "Downloading GIT LFS artifacts"
git lfs pull

msg "Initializing submodules"
git submodule update --init --recursive

msg "Installing coreboot commit hook"
curl -sSf https://review.coreboot.org/tools/hooks/commit-msg \
  -o .git/modules/coreboot/hooks/commit-msg && \
  chmod +x .git/modules/coreboot/hooks/commit-msg

msg "Installing Rust"
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs \
  | sh -s -- -y --default-toolchain nightly

msg "Loading Rust environment"
source ~/.cargo/env

msg "Installing pinned Rust toolchain"
rustup toolchain install "$(cat rust-toolchain)"

msg "Installing source for pinned Rust toolchain"
rustup component add --toolchain "$(cat rust-toolchain)" rust-src

msg "\x1B[32mSuccessfully installed dependencies"
echo "Ready to run ./scripts/build.sh [model]" >&2
