#!/usr/bin/env bash

SPIPI=${SPIPI:-"ubuntu@10.17.89.179"}

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
