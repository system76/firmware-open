#!/usr/bin/env bash

# shellcheck disable=SC2034

SPIPI=${SPIPI:-"system76@spipi.local"}

if [ ! -d "models/${MODEL}" ]
then
  echo "model '${MODEL}' not found" >&2
  exit 1
fi
MODEL_DIR="$(realpath "models/${MODEL}")"

if [ ! -f "${MODEL_DIR}/chip.txt" ]
then
  echo "model '${MODEL}' does not have chip.txt" >&2
  exit 1
fi
CHIP="$(cat "${MODEL_DIR}/chip.txt")"
