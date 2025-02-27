#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-3.0-only

# shellcheck disable=SC1091

set -eE

. /etc/os-release
if [[ "${ID}" =~ "debian" ]] || [[ "${ID_LIKE}" =~ "debian" ]]; then
    sudo apt-get --quiet update
    sudo apt-get --quiet install --no-install-recommends --assume-yes \
        bison \
        build-essential \
        bzip2 \
        ca-certificates \
        ccache \
        cmake \
        curl \
        dosfstools \
        flashrom \
        flex \
        g++ \
        gcc \
        git-lfs \
        gnat \
        libncurses-dev \
        libnss3-dev \
        libssl-dev \
        libudev-dev \
        make \
        mtools \
        parted \
        patch \
        pkgconf \
        python-is-python3 \
        tar \
        uuid-dev \
        xz-utils \
        zlib1g-dev
elif [[ "${ID}" =~ "fedora" ]] || [[ "${ID_LIKE}" =~ "fedora" ]]; then
    sudo dnf group install c-development
    sudo dnf install --assumeyes \
        bison \
        bzip2 \
        ca-certificates \
        ccache \
        cmake \
        curl \
        dosfstools \
        flashrom \
        flex \
        gcc \
        gcc-c++ \
        gcc-gnat \
        git-lfs \
        libuuid-devel \
        make \
        mtools \
        ncurses-devel \
        nss-devel \
        openssl-devel \
        parted \
        patch \
        python-unversioned-command \
        python3 \
        rustup \
        systemd-devel \
        tar \
        xz \
        zlib-devel
elif [[ "${ID}" =~ "arch" ]] || [[ "${ID_LIKE}" =~ "arch" ]]; then
    sudo pacman -S --noconfirm \
        bison \
        bzip2 \
        ca-certificates \
        ccache \
        cmake \
        curl \
        dosfstools \
        flashrom \
        flex \
        gcc \
        gcc-ada \
        git-lfs \
        make \
        mtools \
        ncurses \
        nss \
        parted \
        patch \
        python \
        rustup \
        systemd-libs \
        tar \
        xz \
        zlib
else
    echo "unsupported host: ${ID}"
    exit 1
fi
