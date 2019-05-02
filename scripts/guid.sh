#!/usr/bin/env bash

while ! uuidgen | grep ^76; do true; done
