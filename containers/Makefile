# SPDX-License-Identifier: GPL-3.0-only

# Disable built-in rules and variables
MAKEFLAGS += --no-builtin-rules --no-builtin-variables
.SUFFIXES:

# Default to silent builds
ifneq ($(VERBOSE),1)
MAKEFLAGS += --silent
.SILENT:
endif

PODMAN := $(shell command -v podman)

CONTAINER_TAG := latest

COREBOOT_REPO ?= https://github.com/coreboot/coreboot.git
COREBOOT_COMMIT ?= 24.08

.PHONY: firmware-open
firmware-open:
	$(PODMAN) build \
		--tag system76/$@:$(CONTAINER_TAG) \
		--build-arg COREBOOT_REPO=$(COREBOOT_REPO) \
		--build-arg COREBOOT_COMMIT=$(COREBOOT_COMMIT) \
		--file Containerfile \
		$@
