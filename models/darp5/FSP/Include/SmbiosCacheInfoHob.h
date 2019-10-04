/** @file
  Header file for SMBIOS Cache Info HOB

 @copyright
  Copyright (c) 2015 - 2019, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

  System Management BIOS (SMBIOS) Reference Specification v3.1.0
  dated 2016-Nov-16 (DSP0134)
  http://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.1.0.pdf
**/

#ifndef _SMBIOS_CACHE_INFO_HOB_H_
#define _SMBIOS_CACHE_INFO_HOB_H_

#include <Uefi.h>
#include <Pi/PiHob.h>

#pragma pack(1)
///
/// SMBIOS Cache Info HOB Structure
///
typedef struct {
  UINT16     ProcessorSocketNumber;
  UINT16     NumberOfCacheLevels;         ///< Based on Number of Cache Types L1/L2/L3
  UINT8      SocketDesignationStrIndex;   ///< String Index in the string Buffer. Example "L1-CACHE"
  UINT16     CacheConfiguration;          ///< Format defined in SMBIOS Spec v3.1 Section7.8 Table36
  UINT16     MaxCacheSize;                ///< Format defined in SMBIOS Spec v3.1 Section7.8.1
  UINT16     InstalledSize;               ///< Format defined in SMBIOS Spec v3.1 Section7.8.1
  UINT16     SupportedSramType;           ///< Format defined in SMBIOS Spec v3.1 Section7.8.2
  UINT16     CurrentSramType;             ///< Format defined in SMBIOS Spec v3.1 Section7.8.2
  UINT8      CacheSpeed;                  ///< Cache Speed in nanoseconds. 0 if speed is unknown.
  UINT8      ErrorCorrectionType;         ///< ENUM Format defined in SMBIOS Spec v3.1 Section 7.8.3
  UINT8      SystemCacheType;             ///< ENUM Format defined in SMBIOS Spec v3.1 Section 7.8.4
  UINT8      Associativity;               ///< ENUM Format defined in SMBIOS Spec v3.1 Section 7.8.5
  //
  // Add for smbios 3.1.0
  //
  UINT32     MaximumCacheSize2;           ///< Format defined in SMBIOS Spec v3.1 Section7.8.1
  UINT32     InstalledSize2;              ///< Format defined in SMBIOS Spec v3.1 Section7.8.1
  /**
  String Buffer - each string terminated by NULL "0x00"
  String buffer terminated by double NULL "0x0000"
  **/
} SMBIOS_CACHE_INFO;
#pragma pack()

#endif // _SMBIOS_CACHE_INFO_HOB_H_
