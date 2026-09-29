# shell.nix

# NOTE we need mkShellNoCC
# mkShell would add the regular gcc, which has no ada (gnat)
# https://github.com/NixOS/nixpkgs/issues/142943

with import <nixpkgs> { };
mkShellNoCC {
  buildInputs = [
    ccache
    cmake
    curl
    flashrom
    git
    git-lfs
    gmp
    gnat12 # gcc with ada
    hidapi
    libossp_uuid
    m4 flex bison # Generate flashmap descriptor parser
    mpfr
    ncurses # make menuconfig
    nss
    openssl
    pkg-config
    python3
    qemu # test the image
    rustup
    util-linux
    zlib
  ];
  shellHook = ''
    # Set variables for libraries
    export LD_LIBRARY_PATH=${gmp}/lib:${mpfr}/lib:${zlib}/lib

    # TODO remove?
    NIX_LDFLAGS="$NIX_LDFLAGS -lncurses"

    # Setup Git repo
    git lfs install
    git lfs pull
    git submodule update --init --recursive --checkout --progress

    # coreboot sdk
    make -C coreboot CPUS="$(nproc)" crossgcc-i386
    make -C coreboot CPUS="$(nproc)" crossgcc-x64
    make -C coreboot gitconfig
  '';
}
