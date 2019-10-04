/** @file
  Header file for FSP Information HOB.

 @copyright
  Copyright (c) 2017 - 2019, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

@par Specification Reference:
**/

#ifndef _FSP_INFO_HOB_H_
#define _FSP_INFO_HOB_H_

extern EFI_GUID gFspInfoGuid;

#pragma pack (push, 1)

typedef struct {
UINT8              SiliconInitVersionMajor;
UINT8              SiliconInitVersionMinor;
UINT8              SiliconInitVersionRevision;
UINT8              SiliconInitVersionBuild;
UINT8              FspVersionRevision;
UINT8              FspVersionBuild;
UINT8              TimeStamp [12];
} FSP_INFO_HOB;

#pragma pack (pop)

#endif // _FSP_INFO_HOB_H_
