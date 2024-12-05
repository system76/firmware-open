/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/azalia_device.h>

const u32 cim_verb_data[] = {
	/* Nvidia, GPU9fHDMI/DP */
	0x10de009f, /* Vendor ID */
	0x155850f2, /* Subsystem ID */
	4, /* Number of entries */
	AZALIA_SUBVENDOR(0, 0x155850f2),
	AZALIA_PIN_CFG(0, 0x04, 0x185600f0),
	AZALIA_PIN_CFG(0, 0x05, 0x185600f0),
	AZALIA_PIN_CFG(0, 0x06, 0x185600f0),
	/* ATI, R6xxHDMI */
	0x1002aa01, /* Vendor ID */
	0xaa0100, /* Subsystem ID */
	7, /* Number of entries */
	AZALIA_SUBVENDOR(0, 0xaa0100),
	AZALIA_PIN_CFG(0, 0x03, 0x185600f0),
	AZALIA_PIN_CFG(0, 0x05, 0x185600f0),
	AZALIA_PIN_CFG(0, 0x07, 0x585600f0),
	AZALIA_PIN_CFG(0, 0x09, 0x585600f0),
	AZALIA_PIN_CFG(0, 0x0b, 0x585600f0),
	AZALIA_PIN_CFG(0, 0x0d, 0x585600f0),
	/* Realtek, ALC293 */
	0x10ec0293, /* Vendor ID */
	0x155850f2, /* Subsystem ID */
	12, /* Number of entries */
	AZALIA_SUBVENDOR(0, 0x155850f2),
	AZALIA_PIN_CFG(0, 0x12, 0x90a60130),
	AZALIA_PIN_CFG(0, 0x13, 0x40000000),
	AZALIA_PIN_CFG(0, 0x14, 0x90170110),
	AZALIA_PIN_CFG(0, 0x15, 0x02211020),
	AZALIA_PIN_CFG(0, 0x16, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x18, 0x02a11040),
	AZALIA_PIN_CFG(0, 0x19, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x1a, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x1b, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x1d, 0x41738205),
	AZALIA_PIN_CFG(0, 0x1e, 0x411111f0),
};

const u32 pc_beep_verbs[] = {};

AZALIA_ARRAY_SIZES;
