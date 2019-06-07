#!/usr/bin/env bash

set -e

while true
do
    /opt/intel/udkdebugger/bin/udk-gdb-server
    sleep 10
done
