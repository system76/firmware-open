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
    bison \
    build-essential \
    ccache \
    cmake \
    curl \
    devmem2 \
    dosfstools \
    flashrom \
    flex \
    git-lfs \
    gnat \
    libncurses-dev \
    libudev-dev \
    msr-tools \
    mtools \
    nasm \
    parted \
    python-is-python3 \
    python2 \
    python3-distutils \
    uuid-dev \
    zlib1g-dev
elif [[ "${ID}" =~ "fedora" ]] || [[ "${ID_LIKE}" =~ "fedora" ]]; then
  sudo dnf group install c-development
  sudo dnf install \
    ccache \
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
    python-unversioned-command \
    python2 \
    python3 \
    systemd-devel \
    zlib-devel
elif [[ "${ID}" =~ "arch" ]] || [[ "${ID_LIKE}" =~ "arch" ]]; then
  sudo pacman -S \
    bison \
    ccache \
    cmake \
    curl \
    dosfstools \
    flashrom \
    flex \
    gcc-ada \
    git-lfs \
    msr-tools \
    mtools \
    nasm \
    ncurses \
    parted \
    patch \
    python \
    python-distutils-extra \
    python2 \
    systemd-libs
else
  msg "Unknown system ID: ${ID}"
  msg "Please add support for your distribution to: $0"
  exit 1
fi

msg "Installing GIT LFS hooks"
git lfs install

msg "Downloading GIT LFS artifacts"
git lfs pull

if [ "$(git remote get-url origin)" == "http://192.168.50.76:3000/system76/firmware-open.git" ]; then
  msg "Cloned from local repo. Modifying submodule locations"
  sed -i "s/https:\/\/github.com/http:\/\/192.168.50.76:3000/g" .gitmodules
  sed -i "s/https:\/\/gitlab.redox-os.org/http:\/\/192.168.50.76:3000/g" .gitmodules
  git submodule sync
fi

msg "Initializing submodules"
git submodule update --init --recursive --progress

msg "Installing coreboot commit hook"
curl -sSf https://review.coreboot.org/tools/hooks/commit-msg \
  -o .git/modules/coreboot/hooks/commit-msg && \
  chmod +x .git/modules/coreboot/hooks/commit-msg

RUSTUP_NEW_INSTALL=0
if which rustup &> /dev/null; then
  msg "Updating rustup"
  rustup self update
else
  RUSTUP_NEW_INSTALL=1
  msg "Installing Rust"
  curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs \
    | sh -s -- -y --default-toolchain none

  msg "Loading Rust environment"
  source "${HOME}/.cargo/env"
fi

msg "Installing pinned Rust toolchain and components"
rustup show

msg "Installing EC dependencies"
pushd ec
./scripts/deps.sh
popd

if [[ $RUSTUP_NEW_INSTALL = 1 ]]; then
    msg "\x1B[33m>> rustup was just installed. Ensure cargo is on the PATH with:"
    echo -e "    source ~/.cargo/env\n"
fi

msg "\x1B[32mSuccessfully installed dependencies"
echo "Ready to run ./scripts/build.sh [model]" >&2
