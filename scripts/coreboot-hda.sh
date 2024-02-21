#!/usr/bin/env bash

set -e

if [ ! -e "$1" ]
then
    echo "$0 [coreboot-collector output]"
    exit 1
fi

cat <<"EOF"
/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/azalia_device.h>

const u32 cim_verb_data[] = {
EOF

grep "^hdaudio" "$1" | \
while read line
do
    data="$(sed -n "/^$line/,/^hdaudio/p" "$1" | grep -v "^hdaudio" | tr -d " ")"
    index="$(cut -d 'D' -f2 <<< "$line")"
    vendor_name="$(grep "^vendor_name:" <<< "$data" | cut -d ':' -f2)"
    chip_name="$(grep "^chip_name:" <<< "$data" | cut -d ':' -f2)"
    vendor_id="$(grep "^vendor_id:" <<< "$data" | cut -d ':' -f2)"
    subsystem_id="$(grep "^subsystem_id:" <<< "$data" | cut -d ':' -f2)"

    widgets="$(grep "^0x" <<< "$data")"

    echo -e "\t/* $vendor_name, $chip_name */"
    echo -e "\t$vendor_id, /* Vendor ID */"
    echo -e "\t$subsystem_id, /* Subsystem ID */"
    echo -e "\t$(($(wc -l <<<"$widgets") + 2)), /* Number of entries */"

    echo -e "\tAZALIA_SUBVENDOR($index, $subsystem_id),"
    echo -e "\tAZALIA_RESET(1),"

    cat <<< "$widgets" | \
    while read line
    do
        nid="$(cut -d ':' -f1 <<< "$line")"
        pin_cfg="$(cut -d ':' -f2 <<< "$line")"
        echo -e "\tAZALIA_PIN_CFG($index, $nid, $pin_cfg),"
    done
done

cat <<"EOF"
};

const u32 pc_beep_verbs[] = {};

AZALIA_ARRAY_SIZES;
EOF
