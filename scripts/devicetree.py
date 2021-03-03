#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-only

import os
import subprocess
import sys


def power_limits():
    pl1 = int(subprocess.check_output("cat /sys/class/powercap/intel-rapl:0/constraint_0_power_limit_uw", shell=True))
    pl2 = int(subprocess.check_output("cat /sys/class/powercap/intel-rapl:0/constraint_1_power_limit_uw", shell=True))
    # Convert from microwatts to watts
    return pl1 // 1_000_000, pl2 // 1_000_000

def thermal():
    subprocess.check_call("modprobe msr", shell=True)
    return int(subprocess.check_output("rdmsr --bitfield 31:24 --decimal 0x1A2", shell=True))

def pch_pm_slp():
    gen_pmcon_a = int(subprocess.check_output("devmem2 0xfe001020", shell=True).split()[-1], 16)
    pm_cfg = int(subprocess.check_output("devmem2 0xfe001818", shell=True).split()[-1], 16)

    s3min = (gen_pmcon_a >> 10) & 0b11
    s4min = (gen_pmcon_a >> 4) & 0b11
    susmin = (pm_cfg >> 18) & 0b11
    amin = (pm_cfg >> 16) & 0b11
    return s3min, s4min, susmin, amin

def lpc():
    dump = subprocess.check_output("lspci -s 1f.0 -xxx", shell=True).decode("utf-8")
    extract = []
    for l in dump.split('\n'):
        if l.startswith("80") or l.startswith("90"):
            extract += l.split()[1:]

    # Values are displayed in little endian
    gen1 = int("0x" + "".join(extract[7:3:-1]), 16)
    gen2 = int("0x" + "".join(extract[11:7:-1]), 16)
    gen3 = int("0x" + "".join(extract[15:11:-1]), 16)
    gen4 = int("0x" + "".join(extract[19:15:-1]), 16)
    return gen1, gen2, gen3, gen4


if __name__ == '__main__':
    if os.geteuid() != 0:
        sys.exit("Must run as root")

    pl1, pl2 = power_limits()
    print("""\t# Power limits
\tregister "power_limits_config" = "{{
\t\t.tdp_pl1_override = {},
\t\t.tdp_pl2_override = {},
\t}}"
""".format(pl1, pl2))

    s3min, s4min, susmin, amin = pch_pm_slp()
    print("""\t# Power
\tregister "PchPmSlpS3MinAssert" = "{}"
\tregister "PchPmSlpS4MinAssert" = "{}"
\tregister "PchPmSlpSusMinAssert" = "{}"
\tregister "PchPmSlpAMinAssert" = "{}"
""".format(s3min, s4min, susmin, amin))

    thermal = thermal()
    print("""\t# Thermal
\tregister "tcc_offset" = "{}"
""".format(thermal))

    gen1, gen2, gen3, gen4 = lpc()
    print("""\t\tdevice pci 1f.0 on\t# LPC Interface
\t\t\tregister "gen1_dec" = "{:#010x}"
\t\t\tregister "gen2_dec" = "{:#010x}"
\t\t\tregister "gen3_dec" = "{:#010x}"
\t\t\tregister "gen4_dec" = "{:#010x}"
\t\tend""".format(gen1, gen2, gen3, gen4))
