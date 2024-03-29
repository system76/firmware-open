/* SPDX-License-Identifier: GPL-2.0-only */

#include <mainboard/gpio.h>
#include <soc/gpio.h>

static const struct pad_config gpio_table[] = {
	PAD_CFG_NF(GPP_A0, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A1, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A2, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A3, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A4, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A5, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1),
	PAD_NC(GPP_A7, NONE),
	PAD_NC(GPP_A8, NONE),
	PAD_NC(GPP_A9, NONE),
	PAD_NC(GPP_A10, NONE),
	PAD_CFG_GPO(GPP_A11, 0, PLTRST),
	PAD_NC(GPP_A12, NONE),
	PAD_CFG_TERM_GPO(GPP_A13, 1, UP_20K, PLTRST),
	PAD_CFG_TERM_GPO(GPP_A14, 0, UP_20K, PLTRST),
	PAD_CFG_TERM_GPO(GPP_A15, 0, UP_20K, PLTRST),
	PAD_CFG_NF(GPP_A16, UP_20K, DEEP, NF1),
	_PAD_CFG_STRUCT(GPP_A17, 0x40100100, 0x0000),
	PAD_CFG_TERM_GPO(GPP_A18, 0, UP_20K, PLTRST),
	PAD_CFG_TERM_GPO(GPP_A19, 0, UP_20K, DEEP),
	PAD_CFG_TERM_GPO(GPP_A20, 0, NATIVE, DEEP),
	PAD_CFG_NF(GPP_A21, NATIVE, DEEP, NF1),
	_PAD_CFG_STRUCT(GPP_B0, 0x40100100, 0x0000),
	PAD_CFG_GPO(GPP_B1, 0, PLTRST),
	PAD_CFG_GPO(GPP_B2, 0, PLTRST),
	PAD_CFG_GPO(GPP_B3, 0, PLTRST),
	PAD_CFG_GPO(GPP_B4, 0, PLTRST),
	PAD_CFG_GPO(GPP_B5, 1, PLTRST),
	PAD_CFG_GPO(GPP_B6, 0, DEEP),
	PAD_CFG_GPO(GPP_B7, 1, DEEP),
	PAD_CFG_GPO(GPP_B8, 1, DEEP),
	PAD_CFG_GPI(GPP_B9, NONE, DEEP),
	PAD_CFG_GPI(GPP_B10, NONE, DEEP),
	PAD_CFG_NF(GPP_B11, NONE, DEEP, NF2),
	PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_B13, NONE, PLTRST, NF1),
	PAD_CFG_GPO(GPP_B14, 0, PLTRST),
	PAD_CFG_GPI(GPP_B15, NONE, DEEP),
	PAD_CFG_GPI(GPP_B16, NONE, DEEP),
	PAD_CFG_GPO(GPP_B17, 1, PLTRST),
	PAD_CFG_GPO(GPP_B18, 1, PLTRST),
	PAD_CFG_GPO(GPP_B19, 1, PLTRST),
	PAD_CFG_GPO(GPP_B20, 1, PLTRST),
	PAD_CFG_GPO(GPP_B21, 0, PLTRST),
	PAD_CFG_GPI(GPP_B22, NONE, DEEP),
	PAD_CFG_GPO(GPP_B23, 1, DEEP),
	PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C2, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_C3, 0, PLTRST),
	PAD_CFG_GPO(GPP_C4, 0, PLTRST),
	PAD_CFG_NF(GPP_C5, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_C6, UP_20K, DEEP, NF1),
	PAD_CFG_GPI(GPP_C7, NONE, DEEP),
	PAD_CFG_NF(GPP_C8, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C9, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_C10, 0, PLTRST),
	PAD_CFG_NF(GPP_C11, NONE, PWROK, NF1),
	PAD_CFG_NF(GPP_C12, NONE, PWROK, NF1),
	PAD_CFG_GPO(GPP_C13, 1, DEEP),
	PAD_CFG_NF(GPP_C14, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C15, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C16, NONE, DEEP, NF1),
	PAD_NC(GPP_C17, NONE),
	PAD_NC(GPP_C18, NONE),
	PAD_NC(GPP_C19, NONE),
	PAD_CFG_GPO(GPP_C20, 0, PLTRST),
	PAD_CFG_NF(GPP_C21, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C22, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_C23, 0, PLTRST),
	PAD_CFG_GPO(GPP_D0, 1, PLTRST),
	PAD_CFG_GPO(GPP_D1, 1, PLTRST),
	PAD_CFG_GPO(GPP_D2, 1, PLTRST),
	PAD_NC(GPP_D3, NONE),
	PAD_CFG_GPO(GPP_D4, 0, PLTRST),
	PAD_CFG_GPO(GPP_D5, 1, PLTRST),
	PAD_CFG_GPO(GPP_D6, 0, PLTRST),
	PAD_CFG_GPO(GPP_D7, 0, PLTRST),
	PAD_CFG_GPO(GPP_D8, 0, PLTRST),
	PAD_CFG_GPO(GPP_D9, 0, PLTRST),
	PAD_CFG_NF(GPP_D10, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D11, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_D12, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_D13, NATIVE, DEEP, NF1),
	PAD_CFG_GPO(GPP_D14, 0, PLTRST),
	PAD_CFG_GPO(GPP_D15, 0, PLTRST),
	PAD_CFG_GPO(GPP_D16, 0, DEEP),
	PAD_CFG_NF(GPP_D17, NONE, DEEP, NF1),
	PAD_NC(GPP_D18, NONE),
	PAD_CFG_NF(GPP_D19, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D20, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D21, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D22, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_D23, NATIVE, DEEP, NF1),
	PAD_CFG_GPO(GPP_E0, 0, PLTRST),
	_PAD_CFG_STRUCT(GPP_E1, 0x40100100, 0x1000),
	PAD_CFG_GPI(GPP_E2, NONE, DEEP),
	PAD_NC(GPP_E3, NONE),
	PAD_CFG_GPO(GPP_E4, 0, PLTRST),
	PAD_CFG_GPO(GPP_E5, 0, PLTRST),
	PAD_CFG_GPI(GPP_E6, NONE, DEEP),
	PAD_CFG_GPO(GPP_E7, 0, PLTRST),
	PAD_CFG_GPO(GPP_E8, 0, PLTRST),
	PAD_CFG_GPI(GPP_E9, NONE, DEEP),
	PAD_CFG_GPO(GPP_E10, 0, PLTRST),
	PAD_CFG_GPI(GPP_E11, NONE, DEEP),
	_PAD_CFG_STRUCT(GPP_E12, 0x84002200, 0x0000),
	_PAD_CFG_STRUCT(GPP_E13, 0x44002100, 0x0000),
	PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_E15, 0, PLTRST),
	PAD_CFG_NF(GPP_E16, NONE, DEEP, NF2),
	PAD_CFG_GPO(GPP_E17, 0, PLTRST),
	PAD_NC(GPP_E18, NONE),
	PAD_NC(GPP_E19, NONE),
	PAD_NC(GPP_E20, NONE),
	PAD_NC(GPP_E21, NONE),
	PAD_CFG_TERM_GPO(GPP_E22, 0, DN_20K, PLTRST),
	PAD_CFG_NF(GPP_F0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F1, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_F2, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F3, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_F4, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F5, NONE, DEEP, NF3),
	PAD_CFG_NF(GPP_F6, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F7, DN_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_F8, DN_20K, DEEP, NF1),
	PAD_CFG_GPI(GPP_F9, NONE, DEEP),
	PAD_NC(GPP_F10, NONE),
	PAD_CFG_GPO(GPP_F11, 0, PLTRST),
	_PAD_CFG_STRUCT(GPP_F12, 0x44002300, 0x0000),
	_PAD_CFG_STRUCT(GPP_F13, 0x44002300, 0x0000),
	PAD_CFG_GPO(GPP_F14, 0, PLTRST),
	PAD_CFG_GPO(GPP_F15, 0, PLTRST),
	PAD_CFG_GPO(GPP_F16, 0, PLTRST),
	PAD_CFG_GPO(GPP_F17, 0, PLTRST),
	PAD_CFG_GPO(GPP_F18, 0, DEEP),
	PAD_CFG_GPO(GPP_F19, 0, PLTRST),
	PAD_CFG_GPO(GPP_F20, 0, PLTRST),
	PAD_CFG_GPO(GPP_F21, 0, PLTRST),
	PAD_CFG_GPO(GPP_F22, 0, PLTRST),
	PAD_CFG_GPO(GPP_F23, 0, PLTRST),
	PAD_CFG_GPO(GPP_H0, 0, PLTRST),
	PAD_CFG_GPO(GPP_H1, 0, PLTRST),
	PAD_CFG_GPO(GPP_H2, 1, PLTRST),
	PAD_NC(GPP_H3, NONE),
	PAD_NC(GPP_H4, NONE),
	PAD_NC(GPP_H5, NONE),
	PAD_NC(GPP_H6, NONE),
	PAD_NC(GPP_H7, NONE),
	PAD_NC(GPP_H8, NONE),
	PAD_NC(GPP_H9, NONE),
	PAD_CFG_GPO(GPP_H10, 0, PLTRST),
	PAD_CFG_GPO(GPP_H11, 0, PLTRST),
	PAD_NC(GPP_H12, NONE),
	PAD_CFG_NF(GPP_H13, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_H14, 0, PLTRST),
	PAD_CFG_GPO(GPP_H15, 0, PLTRST),
	PAD_CFG_GPO(GPP_H16, 0, PLTRST),
	PAD_CFG_GPO(GPP_H17, 0, PLTRST),
	PAD_NC(GPP_H18, NONE),
	PAD_CFG_NF(GPP_H19, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_H20, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_H21, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_H22, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_S0, 0, PLTRST),
	PAD_CFG_GPO(GPP_S1, 0, PLTRST),
	PAD_CFG_GPO(GPP_S2, 0, PLTRST),
	PAD_CFG_GPO(GPP_S3, 0, PLTRST),
	PAD_CFG_GPO(GPP_S4, 0, PLTRST),
	PAD_CFG_GPO(GPP_S5, 0, PLTRST),
	PAD_CFG_NF(GPP_S6, NONE, DEEP, NF3),
	PAD_CFG_NF(GPP_S7, NONE, DEEP, NF3),
	PAD_CFG_NF(GPP_V0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_V1, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_V2, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_V3, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_V4, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_V5, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_V6, NATIVE, DEEP, NF1),
	PAD_CFG_GPI(GPP_V7, NATIVE, DEEP),
	PAD_CFG_NF(GPP_V8, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_V9, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_V10, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_V11, NONE, DEEP, NF1),
	PAD_NC(GPP_V12, NONE),
	PAD_CFG_NF(GPP_V13, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_V14, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_V15, NONE, PLTRST, NF1),
	PAD_CFG_GPO(GPP_V16, 0, PLTRST),
	PAD_CFG_GPO(GPP_V17, 0, PLTRST),
	PAD_NC(GPP_V18, NONE),
	PAD_CFG_NF(GPP_V19, NONE, DEEP, NF1),
	PAD_NC(GPP_V20, NONE),
	PAD_NC(GPP_V21, NONE),
	PAD_NC(GPP_V22, NONE),
	PAD_NC(GPP_V23, NONE),
};

void mainboard_configure_gpios(void)
{
	gpio_configure_pads(gpio_table, ARRAY_SIZE(gpio_table));
}
