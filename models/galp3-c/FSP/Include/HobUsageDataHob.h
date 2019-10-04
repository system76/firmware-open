/** @file
  Definitions for Hob Usage data HOB

  @copyright
  Copyright (c) 2017 - 2019, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

@par Specification Reference:
**/

#ifndef _HOB_USAGE_DATA_HOB_H_
#define _HOB_USAGE_DATA_HOB_H_

extern EFI_GUID gHobUsageDataGuid;

#pragma pack (push, 1)

/**
  Hob Usage Data Hob

  <b>Revision 1:</b>
  - Initial version.
**/
typedef struct {
  EFI_PHYSICAL_ADDRESS EfiMemoryTop;
  EFI_PHYSICAL_ADDRESS EfiMemoryBottom;
  EFI_PHYSICAL_ADDRESS EfiFreeMemoryTop;
  EFI_PHYSICAL_ADDRESS EfiFreeMemoryBottom;
  UINTN                FreeMemory;
} HOB_USAGE_DATA_HOB;

#pragma pack (pop)

#endif // _HOB_USAGE_DATA_HOB_H_
