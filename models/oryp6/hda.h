/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2019 System76
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 */

#ifndef HDA_VERB_H
#define HDA_VERB_H

#include <device/azalia_device.h>

const u32 cim_verb_data[] = {
	/* Realtek, ALC1220 */
	0x10ec1220, /* Vendor ID */
	0x155850d3, /* Subsystem ID */
	12, /* Number of entries */
	AZALIA_SUBVENDOR(0, 0x155850d3),
	AZALIA_PIN_CFG(0, 0x12, 0x90a60130),
	AZALIA_PIN_CFG(0, 0x14, 0x0421101f),
	AZALIA_PIN_CFG(0, 0x15, 0x40000000),
	AZALIA_PIN_CFG(0, 0x16, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x17, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x18, 0x04a11040),
	AZALIA_PIN_CFG(0, 0x19, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x1a, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x1b, 0x90170110),
	AZALIA_PIN_CFG(0, 0x1d, 0x40b7952d),
	AZALIA_PIN_CFG(0, 0x1e, 0x04451150),
	/* Intel, KabylakeHDMI */
	0x8086280b, /* Vendor ID */
	0x80860101, /* Subsystem ID */
	4, /* Number of entries */
	AZALIA_SUBVENDOR(2, 0x80860101),
	AZALIA_PIN_CFG(2, 0x05, 0x18560010),
	AZALIA_PIN_CFG(2, 0x06, 0x18560010),
	AZALIA_PIN_CFG(2, 0x07, 0x18560010),
	/* Nvidia, GPU93HDMI/DP */
	0x10de0093, /* Vendor ID */
	0x155850d3, /* Subsystem ID */
	5, /* Number of entries */
	AZALIA_SUBVENDOR(0, 0x155850d3),
	AZALIA_PIN_CFG(0, 0x04, 0x185600f0),
	AZALIA_PIN_CFG(0, 0x05, 0x185600f0),
	AZALIA_PIN_CFG(0, 0x06, 0x185600f0),
	AZALIA_PIN_CFG(0, 0x07, 0x585600f0),
};

const u32 pc_beep_verbs[] = {};

AZALIA_ARRAY_SIZES;

#endif
