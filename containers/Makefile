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

.PHONY: firmware-open
firmware-open:
	$(PODMAN) build \
		--tag system76/$@:$(CONTAINER_TAG) \
		--file Containerfile \
		$@
