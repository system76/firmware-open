# Intel Management Engine

[Intel Management Engine][wiki] is a proprietary, mostly undocumented, firmware
system that provides many extraneous features that are generally not usable or
useful to our users, with multiple known vulnerabilities that compromise the
entire system.

The Intel ME is _required_ (since Nehalem, 2008), so cannot be removed. The
[me\_cleaner] project is able to remove non-essential components, but does not
support the ME version used on many of our systems. Instead, we [send a HECI
command][CB52800] to tell the Intel ME to disable runtime components during
early boot.

Most Intel-based machines from System76 come with the IME disabled.

## Configuring

The IME can be enabled or disabled via the coreboot CMOS option `me_state`.
The value can be set using coreboot's nvramtool.

```
make -C coreboot/util/nvramtool
sudo ./coreboot/util/nvramtool/nvramtool -w me_state={Enable,Disable}
```

A restart is required for the change to take effect. On the boot after changing
the value, the system will perform a global reset (power off again) to complete
the change and ensure the IME is operating in a valid state.

## Tiger Lake-U

Models using TGL-U processors default to having the IME enabled. TGL-U removes
support for S3 and requires S0ix. This requires all CPU, PCH, and PCIe devices
to have ACPI defined low power states. With S0ix, the CPU has numerous states
for low power, with the lowest being C10. In order to reach this C10 state, the
IME must report that it is in a low power state. Disabling the ME with the HAP
bit keeps the CPU in the C8 state. This nearly triples the power usage in S0ix
suspend, from around 1 watt to around 3 watts.


[wiki]: https://en.wikipedia.org/wiki/Intel_Management_Engine
[me\_cleaner]: https://github.com/corna/me_cleaner
[CB52800]: https://review.coreboot.org/c/coreboot/+/52800
