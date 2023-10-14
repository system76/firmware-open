#!/usr/bin/env bash

set -e

#awk '/Fsp S Configuration/,/^} FSP_S_CONFIG;/' coreboot/3rdparty/fsp/CometLakeFspBinPkg/CometLake1/Include/FspsUpd.h |
awk '/Fsp M Configuration/,/^} FSP_M_CONFIG;/' coreboot/3rdparty/fsp/CometLakeFspBinPkg/CometLake1/Include/FspmUpd.h |
tr -d $'\r' |
tr -s ' ' | 
grep '^ UINT' |
tr -d ';' |
cut -d ' ' -f3 |
while read line
do
    if [[ "$line" == "Reserved"* ]]
    then
        continue
    fi

    if [[ "$line" == "Unused"* ]]
    then
        continue
    fi

    if [[ "$line" == *'['*']' ]]
    then
        echo "// $line"
        var="$(echo "$line" | cut -d '[' -f1)"
        count="$(echo "$line" | cut -d '[' -f2 | cut -d ']' -f1)"
        for i in $(seq 0 "$count")
        do
            if [ "$i" != "$count" ]
            then
                echo "DISPLAY_UPD(${var[$i]});"
            fi
        done
    else
        echo "DISPLAY_UPD($line);"
    fi
done
