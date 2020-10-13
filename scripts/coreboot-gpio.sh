#!/usr/bin/env bash

set -e

if [ ! -e "$1" ]
then
    echo "$0 [coreboot-collector output]"
    exit 1
fi

cat <<"EOF"
/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef MAINBOARD_GPIO_H
#define MAINBOARD_GPIO_H

#include <soc/gpe.h>
#include <soc/gpio.h>

#ifndef __ACPI__

/* Pad configuration in ramstage. */
static const struct pad_config gpio_table[] = {
EOF

grep ^GP "$1" | \
cut -d ' ' -f1,3,4 | \
sort -V | \
while read line
do
    parts=()
    for part in $line
    do
        parts+=("$part")
    done
    parts[1]="$(printf '0x%08x' "$((${parts[1]} & 0xfffffffd))")"
    parts[2]="$(printf '0x%04x' "$((${parts[2]} & 0x00003c00))")"

    case "${parts[1]}" in
        0x0???????)
            reset="PWROK" # RSMRST?
            ;;
        0x4???????)
            reset="DEEP"
            ;;
        0x8???????)
            reset="PLTRST"
            ;;
        *)
            reset="TODO_${parts[1]}"
            ;;
    esac

    case "${parts[2]}" in
        0x0000)
            term="NONE"
            ;;
        0x1000)
            term="DN_20K"
            ;;
        0x3000)
            term="UP_20K"
            ;;
        0x3c00)
            term="NATIVE"
            ;;
        *)
            term="TODO_${parts[2]}"
            ;;
    esac

    case "${parts[1]}" in
        0x?4000000 | 0x?4000200)
            echo -e "\t\tPAD_CFG_TERM_GPO(${parts[0]}, 0, ${term}, ${reset}),"
            ;;
        0x?4000001 | 0x?4000201)
            echo -e "\t\tPAD_CFG_TERM_GPO(${parts[0]}, 1, ${term}, ${reset}),"
            ;;
        0x?4000100)
            echo -e "\t\tPAD_CFG_GPI(${parts[0]}, ${term}, ${reset}),"
            ;;
        0x44000300)
            echo -e "\t\tPAD_NC(${parts[0]}, ${term}),"
            ;;
        0x?4000400 | 0x?4000500 | 0x?4000600 | 0x?4000700)
            echo -e "\t\tPAD_CFG_NF(${parts[0]}, ${term}, ${reset}, NF1),"
            ;;
        0x?4000800 | 0x?4000900 | 0x?4000a00 | 0x?4000b00)
            echo -e "\t\tPAD_CFG_NF(${parts[0]}, ${term}, ${reset}, NF2),"
            ;;
        0x?4000c00 | 0x?4000d00 | 0x?4000e00 | 0x?4000f00)
            echo -e "\t\tPAD_CFG_NF(${parts[0]}, ${term}, ${reset}, NF3),"
            ;;
        *)
            echo -e "\t\t_PAD_CFG_STRUCT(${parts[0]}, ${parts[1]}, ${parts[2]}),"
            ;;
    esac
done

cat <<"EOF"
};

#endif

#endif
EOF
