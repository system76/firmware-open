#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-3.0-only

# shellcheck disable=SC1091

set -eE

msg() {
  echo -e "\x1B[1m$*\x1B[0m" >&2
}

trap 'msg "\x1B[31mFailed to install dependencies!"' ERR

. /etc/os-release

msg "Installing system build dependencies"
if [[ "${ID}" =~ "debian" ]] || [[ "${ID_LIKE}" =~ "debian" ]]; then
  sudo apt-get --quiet update
  sudo apt-get --quiet install \
    --no-install-recommends \
    --assume-yes \
    build-essential \
    ccache \
    cmake \
    curl \
    dosfstools \
    flashrom \
    git-lfs \
    libncurses-dev \
    libudev-dev \
    mtools \
    parted \
    python-is-python3 \
    python3-distutils \
    uuid-dev \
    zlib1g-dev
elif [[ "${ID}" =~ "fedora" ]] || [[ "${ID_LIKE}" =~ "fedora" ]]; then
  sudo dnf group install c-development
  sudo dnf install \
    --assumeyes \
    ccache \
    cmake \
    curl \
    dosfstools \
    flashrom \
    git-lfs \
    libuuid-devel \
    mtools \
    ncurses-devel \
    parted \
    patch \
    python-unversioned-command \
    python3 \
    systemd-devel \
    zlib-devel
elif [[ "${ID}" =~ "arch" ]] || [[ "${ID_LIKE}" =~ "arch" ]]; then
  sudo pacman -S \
    --noconfirm \
    ccache \
    cmake \
    curl \
    dosfstools \
    flashrom \
    git-lfs \
    mtools \
    ncurses \
    parted \
    patch \
    python \
    python-distutils-extra \
    systemd-libs
else
  msg "Unknown system ID: ${ID}"
  msg "Please add support for your distribution to: $0"
  exit 1
fi

# Don't run on Jenkins
if [ -z "${CI}" ]; then
    msg "Installing GIT LFS hooks"
    git lfs install

    msg "Downloading GIT LFS artifacts"
    git lfs pull
fi

msg "Initializing submodules"
git submodule update --init --recursive --checkout --progress

msg "Building coreboot toolchains"
./scripts/coreboot-sdk.sh

msg "Installing Rust toolchain and components"
./scripts/install-rust.sh

msg "Installing EC dependencies"
pushd ec
./scripts/deps.sh
popd

msg "\x1B[32mSuccessfully installed dependencies"
echo "Ready to run ./scripts/build.sh [model]" >&2
