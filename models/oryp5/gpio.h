/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef MAINBOARD_GPIO_H
#define MAINBOARD_GPIO_H

#include <soc/gpe.h>
#include <soc/gpio.h>

#ifndef __ACPI__

/* Pad configuration in ramstage. */
static const struct pad_config gpio_table[] = {
		PAD_CFG_NF(GPD0, NONE, DEEP, NF1),
		PAD_CFG_NF(GPD1, NATIVE, DEEP, NF1),
		PAD_CFG_GPI(GPD2, NATIVE, PWROK),
		PAD_CFG_NF(GPD3, UP_20K, DEEP, NF1),
		PAD_CFG_NF(GPD4, NONE, DEEP, NF1),
		PAD_CFG_NF(GPD5, NONE, DEEP, NF1),
		PAD_CFG_NF(GPD6, UP_20K, PWROK, NF1),
		PAD_CFG_GPI(GPD7, UP_20K, PWROK),
		PAD_CFG_NF(GPD8, NONE, DEEP, NF1),
		PAD_CFG_GPI(GPD9, UP_20K, PWROK),
		PAD_CFG_NF(GPD10, UP_20K, PWROK, NF1),
		PAD_CFG_TERM_GPO(GPD11, 1, NONE, DEEP),
		PAD_CFG_NF(GPP_A0, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_A1, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_A2, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_A3, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_A4, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_A5, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_A7, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_A8, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_A9, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_A10, NONE, DEEP, NF1),
		_PAD_CFG_STRUCT(GPP_A11, 0x80100100, 0x0000),
		PAD_CFG_GPI(GPP_A12, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_A13, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_A14, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_A15, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_A16, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_A17, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_A18, UP_20K, DEEP),
		PAD_CFG_TERM_GPO(GPP_A19, 1, NONE, DEEP),
		PAD_CFG_GPI(GPP_A20, NONE, DEEP),
		PAD_CFG_GPI(GPP_A21, UP_20K, DEEP),
		PAD_CFG_TERM_GPO(GPP_A22, 1, NONE, DEEP),
		PAD_CFG_TERM_GPO(GPP_A23, 1, NONE, DEEP),
		PAD_CFG_GPI(GPP_B0, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_B1, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_B2, UP_20K, DEEP),
		PAD_CFG_TERM_GPO(GPP_B3, 1, NONE, DEEP),
		PAD_CFG_TERM_GPO(GPP_B4, 1, NONE, DEEP),
		PAD_CFG_GPI(GPP_B5, UP_20K, PLTRST),
		PAD_CFG_GPI(GPP_B6, UP_20K, PLTRST),
		PAD_CFG_TERM_GPO(GPP_B7, 1, NONE, PLTRST),
		PAD_CFG_TERM_GPO(GPP_B8, 1, NONE, PLTRST),
		PAD_CFG_GPI(GPP_B9, UP_20K, PLTRST),
		PAD_CFG_TERM_GPO(GPP_B10, 0, NONE, PLTRST),
		PAD_CFG_GPI(GPP_B11, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_B12, UP_20K, DEEP),
		PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_B14, NONE, DEEP, NF1),
		PAD_CFG_GPI(GPP_B15, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_B16, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_B17, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_B18, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_B19, UP_20K, DEEP),
		_PAD_CFG_STRUCT(GPP_B20, 0x42040100, 0x0000),
		PAD_CFG_GPI(GPP_B21, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_B22, UP_20K, DEEP),
		_PAD_CFG_STRUCT(GPP_B23, 0x80880100, 0x3000),
		PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1),
		PAD_CFG_GPI(GPP_C2, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_C3, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_C4, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_C5, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_C6, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_C7, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_C8, NONE, DEEP),
		PAD_CFG_GPI(GPP_C9, DN_20K, DEEP),
		PAD_CFG_GPI(GPP_C10, DN_20K, DEEP),
		PAD_CFG_GPI(GPP_C11, DN_20K, DEEP),
		PAD_CFG_GPI(GPP_C12, NONE, DEEP),
		PAD_CFG_TERM_GPO(GPP_C13, 1, NONE, DEEP),
		PAD_CFG_TERM_GPO(GPP_C14, 1, NONE, DEEP),
		PAD_CFG_TERM_GPO(GPP_C15, 1, NONE, DEEP),
		PAD_CFG_NF(GPP_C16, NONE, PLTRST, NF1),
		PAD_CFG_NF(GPP_C17, NONE, PLTRST, NF1),
		PAD_CFG_NF(GPP_C18, NONE, PLTRST, NF1),
		PAD_CFG_NF(GPP_C19, NONE, PLTRST, NF1),
		PAD_CFG_NF(GPP_C20, UP_20K, DEEP, NF1),
		PAD_CFG_NF(GPP_C21, UP_20K, DEEP, NF1),
		PAD_CFG_NF(GPP_C22, UP_20K, DEEP, NF1),
		PAD_CFG_NF(GPP_C23, UP_20K, DEEP, NF1),
		PAD_CFG_GPI(GPP_D0, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D1, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D2, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D3, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D4, UP_20K, DEEP),
		PAD_CFG_NF(GPP_D5, NONE, DEEP, NF3),
		PAD_CFG_NF(GPP_D6, NONE, DEEP, NF3),
		PAD_CFG_GPI(GPP_D7, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D8, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D9, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D10, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D11, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D12, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D13, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D14, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D15, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D16, UP_20K, DEEP),
		PAD_CFG_NF(GPP_D17, UP_20K, DEEP, NF1),
		PAD_CFG_NF(GPP_D18, UP_20K, DEEP, NF1),
		PAD_CFG_NF(GPP_D19, UP_20K, DEEP, NF1),
		PAD_CFG_NF(GPP_D20, UP_20K, DEEP, NF1),
		PAD_CFG_GPI(GPP_D21, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D22, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_D23, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_E0, UP_20K, DEEP),
		PAD_CFG_NF(GPP_E1, NONE, DEEP, NF1),
		PAD_CFG_GPI(GPP_E2, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_E3, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_E4, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_E5, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_E6, UP_20K, DEEP),
		_PAD_CFG_STRUCT(GPP_E7, 0x80100100, 0x0000),
		PAD_CFG_NF(GPP_E8, NONE, DEEP, NF1),
		PAD_CFG_GPI(GPP_E9, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_E10, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_E11, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_E12, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F0, UP_20K, DEEP),
		PAD_CFG_NF(GPP_F1, NONE, DEEP, NF1),
		PAD_CFG_GPI(GPP_F2, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F3, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F4, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F5, UP_20K, DEEP),
		PAD_CFG_NF(GPP_F6, NONE, DEEP, NF1),
		PAD_CFG_GPI(GPP_F7, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F8, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F9, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F10, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F11, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F12, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F13, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F14, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F15, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F16, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F17, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_F18, UP_20K, DEEP),
		PAD_CFG_NF(GPP_F19, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_F20, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_F21, NONE, DEEP, NF1),
		PAD_CFG_TERM_GPO(GPP_F22, 1, NONE, DEEP),
		PAD_CFG_TERM_GPO(GPP_F23, 1, NONE, DEEP),
		PAD_CFG_GPI(GPP_G0, UP_20K, DEEP),
		PAD_NC(GPP_G1, NONE),
		PAD_CFG_GPI(GPP_G2, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_G3, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_G4, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_G5, UP_20K, DEEP),
		_PAD_CFG_STRUCT(GPP_G6, 0x40880100, 0x0000),
		PAD_CFG_GPI(GPP_G7, UP_20K, DEEP),
		PAD_CFG_TERM_GPO(GPP_H0, 0, NONE, PLTRST),
		PAD_CFG_TERM_GPO(GPP_H1, 0, NONE, PLTRST),
		PAD_CFG_NF(GPP_H2, NONE, DEEP, NF1),
		PAD_CFG_TERM_GPO(GPP_H3, 0, NONE, PLTRST),
		PAD_CFG_TERM_GPO(GPP_H4, 0, NONE, PLTRST),
		PAD_CFG_NF(GPP_H5, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_H6, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_H7, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_H8, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_H9, NONE, DEEP, NF1),
		PAD_CFG_GPI(GPP_H10, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_H11, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_H12, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_H13, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_H14, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_H15, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_H16, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_H17, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_H18, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_H19, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_H20, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_H21, DN_20K, DEEP),
		PAD_CFG_GPI(GPP_H22, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_H23, UP_20K, DEEP),
		_PAD_CFG_STRUCT(GPP_I0, 0x46880100, 0x0000),
		_PAD_CFG_STRUCT(GPP_I1, 0x46880100, 0x0000),
		_PAD_CFG_STRUCT(GPP_I2, 0x46880100, 0x0000),
		PAD_CFG_GPI(GPP_I3, UP_20K, DEEP),
		PAD_CFG_NF(GPP_I4, NONE, DEEP, NF1),
		PAD_CFG_GPI(GPP_I5, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_I6, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_I7, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_I8, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_I9, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_I10, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_I11, UP_20K, DEEP),
		PAD_CFG_TERM_GPO(GPP_I12, 1, NONE, DEEP),
		PAD_CFG_GPI(GPP_I13, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_I14, UP_20K, DEEP),
		PAD_CFG_NF(GPP_J0, NONE, DEEP, NF1),
		PAD_CFG_TERM_GPO(GPP_J1, 1, NONE, DEEP),
		PAD_CFG_GPI(GPP_J2, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_J3, UP_20K, DEEP),
		PAD_CFG_NF(GPP_J4, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_J5, UP_20K, DEEP, NF1),
		PAD_CFG_NF(GPP_J6, NONE, DEEP, NF1),
		PAD_CFG_NF(GPP_J7, UP_20K, DEEP, NF1),
		PAD_CFG_GPI(GPP_J8, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_J9, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_J10, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_J11, UP_20K, DEEP),
		PAD_NC(GPP_K0, NONE),
		PAD_CFG_GPI(GPP_K1, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K2, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K3, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K4, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K5, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K6, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K7, UP_20K, DEEP),
		PAD_CFG_TERM_GPO(GPP_K8, 1, NONE, DEEP),
		PAD_CFG_TERM_GPO(GPP_K9, 1, NONE, DEEP),
		PAD_CFG_GPI(GPP_K10, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K11, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K12, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K13, UP_20K, DEEP),
		PAD_CFG_TERM_GPO(GPP_K14, 0, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K15, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K16, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K17, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K18, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K19, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K20, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K21, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K22, UP_20K, DEEP),
		PAD_CFG_GPI(GPP_K23, UP_20K, DEEP),
};

#endif

#endif
