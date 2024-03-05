#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-3.0-only

# Build the coreboot toolchains

# shellcheck disable=SC1091

set -e

. /etc/os-release
if [ "$ID" = "arch" ] || [[ "$ID_LIKE" =~ "arch" ]]; then
    sudo pacman -S --noconfirm \
        bison \
        bzip2 \
        ca-certificates \
        curl \
        flex \
        gcc \
        gcc-ada \
        make \
        nss \
        patch \
        tar \
        xz \
        zlib
elif [ "$ID" = "fedora" ] || [[ "$ID_LIKE" =~ "fedora" ]]; then
    sudo dnf install --assumeyes \
        bison \
        bzip2 \
        ca-certificates \
        curl \
        flex \
        gcc \
        gcc-c++ \
        gcc-gnat \
        make \
        nss-devel \
        patch \
        tar \
        xz \
        zlib-devel
elif [[ "$ID" =~ "opensuse" ]] || [[ "ID_LIKE" =~ "opensuse" ]]; then
  sudo zypper in -y \
    bzip2 \
    ca-certificates \
    flex \
    gcc \
    gcc-c++ \
    gcc-ada \
    make \
    mozilla-nss-devel \
    patch \
    tar \
    xz \
    zlib-devel
elif [ "$ID" = "ubuntu" ] || [[ "$ID_LIKE" =~ "debian" ]]; then
    sudo apt-get --quiet update
    sudo apt-get --quiet install --no-install-recommends --assume-yes \
        bison \
        bzip2 \
        ca-certificates \
        curl \
        flex \
        g++ \
        gcc \
        gnat \
        libnss3-dev \
        make \
        patch \
        tar \
        xz-utils \
        zlib1g-dev
else
    printf "\e[1;31munsupported host:\e[0m %s\n" "$ID"
    exit 1
fi

make -C coreboot CPUS="$(nproc)" crossgcc-i386
make -C coreboot CPUS="$(nproc)" crossgcc-x64
make -C coreboot gitconfig
