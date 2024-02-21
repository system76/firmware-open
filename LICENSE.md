# License

System76 Open Firmware consists of multiple projects under different licenses.

The source components are made available under the following licenses:

| Component       | License             |
| ---------       | -------             |
| coreboot        | GPL-2.0-only        |
| edk2            | BSD-2-Clause-Patent |
| firmware-setup  | GPL-3.0-only        |
| ec              | GPL-3.0-only        |
| Intel CSME      | Proprietary         |
| Intel FSP       | Proprietary         |
| Intel microcode | Proprietary         |

## Binaries

### `ec.rom`

The license for the embedded controller firmware depends on the binary used.

- System76 EC firmware: GPL-3.0-only
- ODM-provided firmware: Proprietary

### `firmware.rom`

`firmware.rom` contains multiple projects under different licenses.

- coreboot: GPL-2.0-only
- edk2-based payload: GPL-3.0-only
- Intel binaries: Proprietary

#### Intel binaries

Intel provides binaries under a redistributable license, which may be
different per binary.

- `me.rom`: Intel CSME
- `Fsp.fd`: [Intel FSP](https://github.com/intel/fsp)
  - [`FSP_License.pdf`](https://github.com/intel/FSP/blob/master/FSP_License.pdf)
- `microcode.rom`: [Intel microcode](https://github.com/intel/Intel-Linux-Processor-Microcode-Data-Files)
  - [`license`](https://github.com/intel/Intel-Linux-Processor-Microcode-Data-Files/blob/main/license)
