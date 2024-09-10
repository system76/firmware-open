# shell.nix

# NOTE we need mkShellNoCC
# mkShell would add the regular gcc, which has no ada (gnat)
# https://github.com/NixOS/nixpkgs/issues/142943

with import <nixpkgs> { };
mkShellNoCC {
  buildInputs = [
    ccache
    gnat12 # gcc with ada
    #gnatboot # gnat1
    git
    git-lfs
    python3
    ncurses # make menuconfig
    m4 flex bison # Generate flashmap descriptor parser
    #clang
    zlib
    #acpica-tools # iasl
    pkg-config
    openssl
    rustup
    qemu # test the image
  ];
  shellHook = ''
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
