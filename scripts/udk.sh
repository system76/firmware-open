#!/usr/bin/env bash

set -e

trap "trap - SIGTERM && kill -- -$$" SIGINT SIGTERM EXIT

echo "## Launching UDK ##"
./scripts/udk-server.sh &

while true
do
    if lsof -Pi :20715 -sTCP:LISTEN -t >/dev/null
    then
        break
    fi
    sleep 1
done

echo "## Launching NC ##"
./scripts/udk-output.sh &

while true
do
    if lsof -Pi :1234 -sTCP:LISTEN -t >/dev/null
    then
        break
    fi
    sleep 1
done

echo "## Launching GDB ##"
./scripts/udk-debug.gdb
