# SPDX-License-Identifier: GPL-3.0-only

# Disable built-in rules and variables
MAKEFLAGS += -rR

PODMAN := $(shell command -v podman)

CONTAINER_TAG := latest

COREBOOT_REPO := https://github.com/coreboot/coreboot.git
COREBOOT_COMMIT := 24.02

SDCC_REPO := https://svn.code.sf.net/p/sdcc/code
SDCC_REV := 14648
SDCC_VERSION := 4.4.0

RUST_TOOLCHAIN := nightly-2023-09-07

.PHONY: firmware-open
firmware-open:
	$(PODMAN) build \
		--tag system76/$@:$(CONTAINER_TAG) \
		--build-arg=COREBOOT_REPO="$(COREBOOT_REPO)" \
		--build-arg=COREBOOT_COMMIT="$(COREBOOT_COMMIT)" \
		--build-arg=SDCC_REPO="$(SDCC_REPO)" \
		--build-arg=SDCC_REV="$(SDCC_REV)" \
		--build-arg=SDCC_VERSION="$(SDCC_VERSION)" \
		--build-arg=RUST_TOOLCHAIN="$(RUST_TOOLCHAIN)" \
		--file Containerfile \
		$@
