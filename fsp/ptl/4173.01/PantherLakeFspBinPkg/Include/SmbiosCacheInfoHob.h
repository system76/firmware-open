/** @file
  Header file for SMBIOS Cache Info HOB

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
