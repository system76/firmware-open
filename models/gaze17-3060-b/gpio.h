/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef MAINBOARD_GPIO_H
#define MAINBOARD_GPIO_H

#include <soc/gpe.h>
#include <soc/gpio.h>

#ifndef __ACPI__

/* Pad configuration in ramstage. */
static const struct pad_config gpio_table[] = {
	PAD_CFG_NF(GPD0, UP_20K, PWROK, NF1),
	PAD_CFG_NF(GPD1, NATIVE, PWROK, NF1),
	PAD_CFG_NF(GPD2, NATIVE, PWROK, NF1),
	PAD_CFG_NF(GPD3, UP_20K, PWROK, NF1),
	PAD_CFG_NF(GPD4, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD5, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD6, NONE, PWROK, NF1),
	PAD_CFG_GPO(GPD7, 0, DEEP),
	PAD_CFG_NF(GPD8, NONE, PWROK, NF1),
	PAD_CFG_GPO(GPD9, 0, PWROK),
	PAD_CFG_NF(GPD10, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD11, NONE, PWROK, NF1),
	PAD_CFG_NF(GPP_A0, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A1, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A2, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A3, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A4, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A5, UP_20K, DEEP, NF1),
	PAD_CFG_GPO(GPP_A6, 0, DEEP),
	PAD_CFG_GPO(GPP_A7, 0, DEEP),
	PAD_CFG_GPO(GPP_A8, 0, DEEP),
	PAD_CFG_NF(GPP_A9, DN_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A10, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_A11, 0, DEEP),
	PAD_CFG_NF(GPP_A12, UP_20K, DEEP, NF1),
	PAD_CFG_GPO(GPP_A13, 1, PLTRST),
	PAD_CFG_GPO(GPP_A14, 1, DEEP),
	_PAD_CFG_STRUCT(GPP_A15, 0x46880100, 0x0000),
	PAD_CFG_NF(GPP_A16, NONE, DEEP, NF1),
	_PAD_CFG_STRUCT(GPP_A17, 0x80100100, 0x0000),
	_PAD_CFG_STRUCT(GPP_A18, 0x46880100, 0x0000),
	PAD_CFG_GPI(GPP_A19, NONE, DEEP),
	PAD_CFG_GPI(GPP_A20, NONE, PLTRST),
	PAD_CFG_GPO(GPP_A21, 0, DEEP),
	PAD_CFG_GPO(GPP_A22, 0, DEEP),
	PAD_CFG_GPO(GPP_A23, 0, DEEP),
	PAD_CFG_NF(GPP_B0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_B1, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_B2, 1, DEEP),
	PAD_CFG_GPI(GPP_B3, NONE, DEEP),
	PAD_CFG_GPI(GPP_B4, NONE, DEEP),
	PAD_CFG_GPO(GPP_B5, 0, DEEP),
	PAD_CFG_GPO(GPP_B6, 0, DEEP),
	PAD_CFG_GPO(GPP_B7, 0, DEEP),
	PAD_CFG_GPO(GPP_B8, 0, DEEP),
	PAD_CFG_GPO(GPP_B9, 0, DEEP),
	PAD_CFG_GPO(GPP_B10, 0, DEEP),
	PAD_CFG_NF(GPP_B11, NONE, PWROK, NF1),
	PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
	_PAD_CFG_STRUCT(GPP_B14, 0x44001100, 0x0000),
	PAD_CFG_GPO(GPP_B15, 0, DEEP),
	PAD_CFG_GPO(GPP_B16, 0, DEEP),
	PAD_CFG_GPO(GPP_B17, 0, DEEP),
	PAD_CFG_GPO(GPP_B18, 0, DEEP),
	PAD_CFG_GPO(GPP_B19, 0, DEEP),
	PAD_CFG_GPO(GPP_B20, 0, DEEP),
	PAD_CFG_GPO(GPP_B21, 0, DEEP),
	PAD_CFG_GPO(GPP_B22, 0, DEEP),
	PAD_CFG_GPO(GPP_B23, 0, DEEP),
	PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_C2, 1, PLTRST),
	PAD_CFG_NF(GPP_C3, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C4, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_C5, 0, DEEP),
	PAD_CFG_NF(GPP_C6, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C7, NONE, DEEP, NF1),
	PAD_NC(GPP_C8, NONE),
	PAD_NC(GPP_C9, NONE),
	PAD_NC(GPP_C10, NONE),
	PAD_NC(GPP_C11, NONE),
	PAD_NC(GPP_C12, NONE),
	PAD_NC(GPP_C13, NONE),
	PAD_NC(GPP_C14, NONE),
	PAD_NC(GPP_C15, NONE),
	PAD_NC(GPP_C16, NONE),
	PAD_NC(GPP_C17, NONE),
	PAD_NC(GPP_C18, NONE),
	PAD_NC(GPP_C19, NONE),
	PAD_NC(GPP_C20, NONE),
	PAD_NC(GPP_C21, NONE),
	PAD_NC(GPP_C22, NONE),
	PAD_NC(GPP_C23, NONE),
	PAD_CFG_GPO(GPP_D0, 1, DEEP),
	PAD_CFG_GPI(GPP_D1, NONE, DEEP),
	PAD_CFG_GPO(GPP_D2, 0, DEEP),
	PAD_CFG_GPO(GPP_D3, 0, DEEP),
	PAD_CFG_GPI(GPP_D4, NONE, DEEP),
	PAD_CFG_NF(GPP_D5, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D6, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D7, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D8, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_D9, 0, DEEP),
	PAD_CFG_GPO(GPP_D10, 0, DEEP),
	PAD_CFG_GPO(GPP_D11, 0, DEEP),
	PAD_CFG_GPI(GPP_D12, NATIVE, DEEP),
	PAD_CFG_GPI(GPP_D13, NONE, DEEP),
	PAD_CFG_GPO(GPP_D14, 1, PLTRST),
	PAD_CFG_GPO(GPP_D15, 0, DEEP),
	PAD_CFG_GPO(GPP_D16, 0, DEEP),
	PAD_CFG_GPO(GPP_D17, 0, DEEP),
	PAD_CFG_GPO(GPP_D18, 0, DEEP),
	PAD_CFG_GPO(GPP_D19, 0, DEEP),
	PAD_CFG_GPI(GPP_E0, NONE, DEEP),
	_PAD_CFG_STRUCT(GPP_E1, 0x40100100, 0x3000),
	PAD_CFG_GPI(GPP_E2, NONE, DEEP),
	PAD_CFG_GPO(GPP_E3, 1, PLTRST),
	PAD_CFG_GPO(GPP_E4, 0, PLTRST),
	PAD_CFG_GPO(GPP_E5, 0, DEEP),
	PAD_CFG_GPO(GPP_E6, 0, DEEP),
	PAD_CFG_GPI(GPP_E7, NONE, DEEP),
	PAD_CFG_GPO(GPP_E8, 0, DEEP),
	PAD_CFG_NF(GPP_E9, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_E10, 0, DEEP),
	PAD_CFG_GPI(GPP_E11, NONE, DEEP),
	PAD_CFG_GPO(GPP_E12, 0, DEEP),
	PAD_CFG_GPI(GPP_E13, NONE, DEEP),
	PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_E15, 0, DEEP),
	PAD_CFG_GPO(GPP_E16, 0, DEEP),
	PAD_CFG_GPI(GPP_E17, NONE, DEEP),
	PAD_NC(GPP_E18, NATIVE),
	PAD_NC(GPP_E19, NATIVE),
	PAD_CFG_GPO(GPP_E20, 0, DEEP),
	PAD_CFG_GPO(GPP_E21, 0, DEEP),
	PAD_CFG_GPO(GPP_E22, 0, DEEP),
	PAD_CFG_GPO(GPP_E23, 0, DEEP),
	PAD_CFG_NF(GPP_F0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F1, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_F2, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F3, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_F4, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F5, NONE, DEEP, NF2),
	PAD_CFG_NF(GPP_F6, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_F7, 1, DEEP),
	PAD_CFG_GPO(GPP_F8, 0, DEEP),
	PAD_CFG_GPO(GPP_F9, 0, DEEP),
	PAD_CFG_GPO(GPP_F10, 0, DEEP),
	PAD_CFG_GPO(GPP_F11, 0, DEEP),
	PAD_CFG_GPI(GPP_F12, NONE, PLTRST),
	PAD_CFG_GPI(GPP_F13, NONE, PLTRST),
	PAD_CFG_GPO(GPP_F14, 0, DEEP),
	PAD_CFG_GPO(GPP_F15, 0, DEEP),
	PAD_CFG_GPI(GPP_F16, NONE, PLTRST),
	PAD_CFG_GPO(GPP_F17, 0, DEEP),
	PAD_CFG_GPO(GPP_F18, 0, DEEP),
	PAD_CFG_NF(GPP_F19, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_F20, 1, PLTRST),
	PAD_CFG_GPO(GPP_F21, 0, DEEP),
	PAD_CFG_GPO(GPP_F22, 0, DEEP),
	PAD_CFG_GPO(GPP_F23, 0, DEEP),
	PAD_CFG_GPO(GPP_H0, 0, DEEP),
	PAD_CFG_GPO(GPP_H1, 0, DEEP),
	PAD_CFG_GPO(GPP_H2, 0, DEEP),
	PAD_CFG_GPI(GPP_H3, NONE, DEEP),
	PAD_CFG_NF(GPP_H4, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_H5, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_H6, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_H7, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_H8, 0, DEEP),
	PAD_CFG_GPO(GPP_H9, 0, DEEP),
	PAD_CFG_GPI(GPP_H10, NONE, DEEP),
	PAD_CFG_GPI(GPP_H11, NONE, DEEP),
	PAD_CFG_GPO(GPP_H12, 0, DEEP),
	PAD_CFG_GPI(GPP_H13, NONE, DEEP),
	PAD_CFG_GPO(GPP_H14, 0, DEEP),
	PAD_CFG_GPO(GPP_H15, 0, DEEP),
	PAD_CFG_GPO(GPP_H16, 0, DEEP),
	PAD_CFG_GPO(GPP_H17, 0, DEEP),
	PAD_CFG_NF(GPP_H18, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_H19, 0, DEEP),
	PAD_CFG_GPI(GPP_H20, NONE, DEEP),
	PAD_CFG_GPI(GPP_H21, NONE, DEEP),
	PAD_CFG_GPO(GPP_H22, 0, DEEP),
	PAD_CFG_NF(GPP_H23, NONE, DEEP, NF2),
	PAD_CFG_NF(GPP_R0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_R1, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_R2, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_R3, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_R4, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_R5, 0, DEEP),
	PAD_CFG_GPO(GPP_R6, 0, DEEP),
	PAD_CFG_GPO(GPP_R7, 0, DEEP),
	PAD_CFG_GPO(GPP_S0, 0, DEEP),
	PAD_CFG_GPO(GPP_S1, 0, DEEP),
	PAD_CFG_GPO(GPP_S2, 0, DEEP),
	PAD_CFG_GPO(GPP_S3, 0, DEEP),
	PAD_CFG_GPO(GPP_S4, 0, DEEP),
	PAD_CFG_GPO(GPP_S5, 0, DEEP),
	PAD_CFG_GPO(GPP_S6, 0, DEEP),
	PAD_CFG_GPO(GPP_S7, 0, DEEP),
	PAD_CFG_GPO(GPP_T2, 0, DEEP),
	PAD_CFG_GPO(GPP_T3, 0, DEEP),
};

#endif

#endif
