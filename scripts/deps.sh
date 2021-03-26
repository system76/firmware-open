#!/usr/bin/env bash

set -eE

function msg {
  echo -e "\x1B[1m$*\x1B[0m" >&2
}

trap 'msg "\x1B[31mFailed to install dependencies!"' ERR

source /etc/os-release


msg "Installing system build dependencies"
if [[ "${ID}" =~ "debian" ]] || [[ "${ID_LIKE}" =~ "debian" ]]; then
  sudo apt-get install \
    avr-libc \
    avrdude \
    bison \
    build-essential \
    ccache \
    cmake \
    curl \
    devmem2 \
    dosfstools \
    flashrom \
    flex \
    gcc-avr \
    git-lfs \
    gnat \
    libncurses-dev \
    libudev-dev \
    msr-tools \
    mtools \
    nasm \
    parted \
    python \
    python3-distutils \
    qt5-default \
    sdcc \
    uuid-dev \
    zlib1g-dev
elif [[ "${ID}" =~ "fedora" ]] || [[ "${ID_LIKE}" =~ "fedora" ]]; then
  sudo dnf group install c-development
  sudo dnf install \
    avr-gcc \
    avr-libc \
    avrdude \
    cmake \
    curl \
    dosfstools \
    flashrom \
    gcc-gnat \
    git-lfs \
    libuuid-devel \
    msr-tools \
    mtools \
    nasm \
    ncurses-devel \
    parted \
    patch \
    qt5-qtbase-devel \
    sdcc \
    systemd-devel \
    zlib-devel
elif [[ "${ID}" =~ "arch" ]] || [[ "${ID_LIKE}" =~ "arch" ]]; then
    sudo pacman -S \
    bison \
    cmake \
    curl \
    dosfstools \
    flex \
    mtools \
    parted \
    python \
    gcc-ada \
    avr-gcc \
    ncurses \
    libgudev \
    python-distutils-extra \
    avr-libc \
    avrdude \
    curl \
    dosfstools \
    flashrom \
    git-lfs \
    msr-tools \
    mtools \
    nasm \
    parted \
    patch \
    sdcc
else
  msg "Unknown system ID: ${ID}"
  msg "Please add support for your distribution to: $0"
  exit 1
fi

msg "Installing GIT LFS hooks"
git lfs install

msg "Downloading GIT LFS artifacts"
git lfs pull

msg "Initializing submodules"
git submodule update --init --recursive --progress

msg "Installing coreboot commit hook"
curl -sSf https://review.coreboot.org/tools/hooks/commit-msg \
  -o .git/modules/coreboot/hooks/commit-msg && \
  chmod +x .git/modules/coreboot/hooks/commit-msg

if ! which rustup &> /dev/null; then
  msg "Installing Rust"
  curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs \
    | sh -s -- -y --default-toolchain none

  msg "Loading Rust environment"
  source "${HOME}/.cargo/env"
fi

msg "Installing pinned Rust toolchain and components"
rustup show

msg "\x1B[32mSuccessfully installed dependencies"
echo "Ready to run ./scripts/build.sh [model]" >&2
