# Intel Management Engine

Intel-based machines by System76 come with the [Intel Management Engine][wiki]
disabled. It is a proprietary, mostly undocumented, system that provides many
extraneous features that are generally not usable or useful to our users, with
multiple known vulnerabilities that compromise the entire system.

The Intel ME is _required_ (since Nehalem, 2008), so cannot be removed. The
[me\_cleaner] project is able to remove non-essential components, but currently
does not support the ME version used on many of our systems. Instead, we [send
a HECI command][heci_disable] to tell the Intel ME to disable runtime
components during early boot.

## Tiger Lake-U

Models using TGL-U processors currently leave the IME enabled. TGL-U removes
support for S3 and requires S0ix. This requires all CPU, PCH, and PCIe devices
to have ACPI defined low power states. With S0ix, the CPU has numerous states
for low power, with the lowest being C10. In order to reach this C10 state, the
IME must report that it is in a low power state. Disabling the ME with the HAP
bit keeps the CPU in the C8 state. This nearly triples the power usage in S0ix
suspend, from around 1 watt to around 3 watts.

[wiki]: https://en.wikipedia.org/wiki/Intel_Management_Engine
[me\_cleaner]: https://github.com/corna/me_cleaner
[heci_disable]: https://github.com/system76/coreboot/blob/011439cb9196d6a71d394ead8c98dfd8ead325d4/src/soc/intel/cannonlake/me.c#L186
