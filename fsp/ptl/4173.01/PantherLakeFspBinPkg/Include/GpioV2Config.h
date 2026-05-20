/** @file
  Header file for GpioConfig structure used by GPIO library.

  @copyright
  INTEL CONFIDENTIAL
  Copyright (C) 2021 Intel Corporation.

  This software and the related documents are Intel copyrighted materials,
  and your use of them is governed by the express license under which they
  were provided to you ("License"). Unless the License provides otherwise,
  you may not use, modify, copy, publish, distribute, disclose or transmit
  this software or the related documents without Intel's prior written
  permission.

  This software and the related documents are provided as is, with no
  express or implied warranties, other than those that are expressly stated
  in the License.

@par Specification Reference:
**/
#ifndef _GPIOV2_CONFIG_H_
#define _GPIOV2_CONFIG_H_

#include <GpioV2Pad.h>

#pragma pack(push, 1)

/**
  GPIO configuration structure used for pin programming.
  Structure contains fields that can be used to configure pad.
**/
typedef struct {
  /**
  Pad Mode
  Pad can be set as GPIO or one of its native functions.
  When in native mode setting Direction (except Inversion), OutputState,
  InterruptConfig, Host Software Pad Ownership and OutputStateLock are unnecessary.
  Refer to definition of GPIOV2_PAD_MODE.
  Refer to EDS for each native mode according to the pad.
  **/
  UINT32 PadMode       : 5;
  /**
  Host Software Pad Ownership
  Set pad to ACPI mode or GPIO Driver Mode.
  Refer to definition of GPIOV2_HOSTSW_OWN.
  **/
  UINT32 HostOwn     : 2;
  /**
  GPIO Direction
  Can choose between In, In with inversion, Out, both In and Out, both In with inversion and out or disabling both.
  Refer to definition of GPIOV2_DIRECTION for supported settings.
  **/
  UINT32 Direction      : 6;
  /**
  Output State
  Set Pad output value.
  Refer to definition of GPIOV2_PAD_STATE for supported settings.
  This setting takes place when output is enabled.
  **/
  UINT32 OutputState         : 2;
  /**
  GPIO Interrupt Configuration
  Set Pad to cause one of interrupts (IOxAPIC/SCI/SMI/NMI).
  This setting is applicable only if GPIO is in GpioMode with input enabled.
  Refer to definition of GPIOV2_INT_CONFIG for supported settings.
  **/
  UINT32 InterruptConfig     : 9;
  /**
  GPIO Reset Configuration.
  This setting controls Pad Reset Configuration.
  Refer to definition of GPIOV2_RESET_CONFIG for supported settings.
  **/
  UINT32 ResetConfig        : 8;
  /**
  GPIO Electrical Configuration
  This setting controls pads termination.
  Refer to definition of GPIOV2_TERMINATION_CONFIG for supported settings.
  **/
  UINT32 TerminationConfig   : 9;
  /**
  GPIO Lock Configuration
  This setting controls pads lock.
  Refer to definition of GPIOV2_PAD_LOCK for supported settings.
  **/
  UINT32 LockConfig         : 2;
  /**
  GPIO Lock Output State
  This setting controls pads lock.
  Refer to definition of GPIOV2_PAD_LOCK for supported settings.
  **/
  UINT32 LockTx         : 2;
  /**
  Additional GPIO configuration
  Refer to definition of GPIOV2_OTHER_CONFIG for supported settings.
  **/
  UINT32 OtherSettings      : 9;

  /**
  Virtual GPIO eSPI Chip Select configuration
  This setting selects between CS0 and CS1.
  Refer to definition of VGPIO_CS_CONFIG for supported settings.
  **/
  UINT32 VgpioCs            : 2;

  UINT32 RsvdBits           : 9;    ///< Reserved bits for future extension
} GPIOV2_CONFIG;

#pragma pack(pop)

typedef struct {
  GPIOV2_PAD           GpioPad;
  GPIOV2_CONFIG        GpioConfig;
} GPIOV2_INIT_CONFIG;

#endif //_GPIO_CONFIG_H_
