/** @file
  Header file for SMBIOS Processor Info HOB

 @copyright
  Copyright (c) 2015 - 2019, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

  System Management BIOS (SMBIOS) Reference Specification v3.1.0
  dated 2016-Nov-16 (DSP0134)
  http://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.1.0.pdf
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
