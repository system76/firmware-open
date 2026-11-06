/** @file
  Header file for SMBIOS Processor Info HOB

  @copyright
  INTEL CONFIDENTIAL
  Copyright (C) 2015 Intel Corporation.

  This software and the related documents are Intel copyrighted materials,
  and your use of them is governed by the express license under which they
  were provided to you ("License"). Unless the License provides otherwise,
  you may not use, modify, copy, publish, distribute, disclose or transmit
  this software or the related documents without Intel's prior written
  permission.

  This software and the related documents are provided as is, with no
  express or implied warranties, other than those that are expressly stated
  in the License.

@par Specification
**/

#ifndef _SMBIOS_PROCESSOR_INFO_HOB_H_
#define _SMBIOS_PROCESSOR_INFO_HOB_H_

#include <Uefi.h>
#include <Pi/PiHob.h>

#pragma pack(1)
///
/// SMBIOS Processor Info HOB Structure
///
typedef struct {
  UINT16     TotalNumberOfSockets;
  UINT16     CurrentSocketNumber;
  UINT8      ProcessorType;                 ///< ENUM defined in SMBIOS Spec v3.1 Section 7.5.1
  /** This info is used for both ProcessorFamily and ProcessorFamily2 fields
      See ENUM defined in SMBIOS Spec v3.1 Section 7.5.2
  **/
  UINT16     ProcessorFamily;
  UINT8      ProcessorManufacturerStrIndex; ///< Index of the String in the String Buffer
  UINT64     ProcessorId;                   ///< ENUM defined in SMBIOS Spec v3.1 Section 7.5.3
  UINT8      ProcessorVersionStrIndex;      ///< Index of the String in the String Buffer
  UINT8      Voltage;                       ///< Format defined in SMBIOS Spec v3.1 Section 7.5.4
  UINT16     ExternalClockInMHz;            ///< External Clock Frequency. Set to 0 if unknown.
  UINT16     MaxSpeedInMHz;                 ///< Snapshot of Max processor speed during boot
  UINT16     CurrentSpeedInMHz;             ///< Snapshot of current processor speed during boot
  UINT8      Status;                        ///< Format defined in the SMBIOS Spec v3.1 Table 21
  UINT8      ProcessorUpgrade;              ///< ENUM defined in SMBIOS Spec v3.1 Section 7.5.5
  /** This info is used for both CoreCount & CoreCount2 fields
      See detailed description in SMBIOS Spec v3.1 Section 7.5.6
  **/
  UINT16     CoreCount;
  /** This info is used for both CoreEnabled & CoreEnabled2 fields
      See detailed description in SMBIOS Spec v3.1 Section 7.5.7
  **/
  UINT16     EnabledCoreCount;
  /** This info is used for both ThreadCount & ThreadCount2 fields
      See detailed description in SMBIOS Spec v3.1 Section 7.5.8
  **/
  UINT16     ThreadCount;
  UINT16     ProcessorCharacteristics;      ///< Format defined in SMBIOS Spec v3.1 Section 7.5.9
  /**
  String Buffer - each string terminated by NULL "0x00"
  String buffer terminated by double NULL "0x0000"
  **/
} SMBIOS_PROCESSOR_INFO;
#pragma pack()

#endif // _SMBIOS_PROCESSOR_INFO_HOB_H_
