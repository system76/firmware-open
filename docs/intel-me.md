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

### Checking the state

coreboot will log some IME data to cbmem during startup. This can be used to
check if it is in the correct state.

```
make -C coreboot/util/cbmem
sudo ./coreboot/util/cbmem/cbmem -c
```

When disabled it will report:

```
ME: Current Working State       : 4
ME: Current Operation State     : 1
ME: Current Operation Mode      : 3
ME: Error Code                  : 2
```

When enabled it will report:

```
ME: Current Working State       : 5
ME: Current Operation State     : 1
ME: Current Operation Mode      : 0
ME: Error Code                  : 0
```

## S0ix

S0ix (Modern Standby, s2idle) requires all CPU, PCH, and PCIe devices to have
ACPI defined low power states. The CPU has numerous states for low power, with
the lowest being C10. In order to reach this C10 state, the CSME must report
that it is in a low power state.

Disabling the CSME with the HAP bit or HECI command keeps the CPU in the C8
state. This nearly triples the power usage in S0ix suspend, from around 1 watt
to around 3 watts.

TGL-U removed support for S3 and requires S0ix.


[wiki]: https://en.wikipedia.org/wiki/Intel_Management_Engine
[me\_cleaner]: https://github.com/corna/me_cleaner
[CB52800]: https://review.coreboot.org/c/coreboot/+/52800
