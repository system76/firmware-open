/******************************************************************************
  Copyright [2018 - 2019] ADVANCED MICRO DEVICES, INC. All rights reserved.
 
  AMD is granting You permission to use this software and documentation (if
  any) (collectively, the "Software") pursuant to the terms and conditions of
  the Software License Agreement included with the Software. If You do not have
  a copy of the Software License Agreement, contact Your AMD representative for
  a copy.
 
  You agree that You will not reverse engineer or decompile the Software, in
  whole or in part, except as allowed by applicable law.
 
  WARRANTY DISCLAIMER: THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND. AMD DISCLAIMS ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
  BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, QUALITY,
  FITNESS FOR A PARTICULAR PURPOSE, TITLE, NON-INFRINGEMENT AND WARRANTIES
  ARISING FROM CUSTOM OF TRADE OR COURSE OF USAGE WITH RESPECT TO THE SOFTWARE,
  INCLUDING WITHOUT LIMITATION, THAT THE SOFTWARE WILL RUN UNINTERRUPTED OR
  ERROR-FREE. THE ENTIRE RISK ASSOCIATED WITH THE USE OF THE SOFTWARE IS
  ASSUMED BY YOU. Some jurisdictions do not allow the exclusion of implied
  warranties, so the above exclusion may not apply to You, but only to the
  extent required by law.
 
  LIMITATION OF LIABILITY AND INDEMNIFICATION: TO THE EXTENT NOT PROHIBITED BY
  APPLICABLE LAW, AMD AND ITS LICENSORS WILL NOT, UNDER ANY CIRCUMSTANCES BE
  LIABLE TO YOU FOR ANY PUNITIVE, DIRECT, INCIDENTAL, INDIRECT, SPECIAL OR
  CONSEQUENTIAL DAMAGES ARISING FROM POSSESSION OR USE OF THE SOFTWARE OR
  OTHERWISE IN CONNECTION WITH ANY PROVISION OF THIS AGREEMENT EVEN IF AMD AND
  ITS LICENSORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. THIS
  INCLUDES, WITHOUT LIMITATION, DAMAGES DUE TO LOST OR MISAPPROPRIATED DATA,
  LOST PROFITS OR CONFIDENTIAL OR OTHER INFORMATION, FOR BUSINESS INTERRUPTION,
  FOR PERSONAL INJURY, FOR LOSS OF PRIVACY, FOR FAILURE TO MEET ANY DUTY
  INCLUDING OF GOOD FAITH OR REASONABLE CARE, FOR NEGLIGENCE AND FOR ANY OTHER
  PECUNIARY OR OTHER LOSS WHTSOEVER. In no event shall AMD's total liability to
  You for all damages, losses, and causes of action (whether in contract, tort
  (including negligence) or otherwise) exceed the amount of $50 USD. You agree
  to defend, indemnify and hold harmless AMD, its subsidiaries and affiliates
  and their respective licensors, directors, officers, employees, affiliates or
  agents from and against any and all loss, damage, liability and other
  expenses (including reasonable attorneys' fees), resulting from Your
  possession or use of the Software or violation of the terms and conditions of
  this Agreement.
 
  U.S. GOVERNMENT RESTRICTED RIGHTS: Notice to U.S. Government End Users. The
  Software and related documentation are "commercial items", as that term is
  defined at 48 C.F.R. Section 2.101, consisting of "commercial computer
  software" and "commercial computer software documentation", as such terms are
  used in 48 C.F.R. Section 12.212 and 48 C.F.R. Section 227.7202,
  respectively. Consistent with 48 C.F.R. Section 12.212 or 48 C.F.R. Sections
  227.7202-1 through 227.7202-4, as applicable, the commercial computer
  software and commercial computer software documentation are being licensed to
  U.S. Government end users: (a) only as commercial items, and (b) with only
  those rights as are granted to all other end users pursuant to the terms and
  conditions set forth in this Agreement. Unpublished rights are reserved under
  the copyright laws of the United States.
 
  EXPORT RESTRICTIONS:  You shall adhere to all applicable U.S. import/export
  laws and regulations, as well as the import/export control laws and
  regulations of other countries as applicable. You further agree You will not
  export, re-export, or transfer, directly or indirectly, any product,
  technical data, software or source code received from AMD under this license,
  or the direct product of such technical data or software to any country for
  which the United States or any other applicable government requires an export
  license or other governmental approval without first obtaining such licenses
  or approvals, or in violation of any applicable laws or regulations of the
  United States or the country where the technical data or software was
  obtained. You acknowledges the technical data and software received will not,
  in the absence of authorization from U.S. or local law and regulations as
  applicable, be used by or exported, re-exported or transferred to: (i) any
  sanctioned or embargoed country, or to nationals or residents of such
  countries; (ii) any restricted end-user as identified on any applicable
  government end-user list; or (iii) any party where the end-use involves
  nuclear, chemical/biological weapons, rocket systems, or unmanned air
  vehicles.  For the most current Country Group listings, or for additional
  information about the EAR or Your obligations under those regulations, please
  refer to the website of the U.S. Bureau of Industry and Security at
  http://www.bis.doc.gov/.
*****************************************************************************/

#ifndef DIAG_MSGS_H_
#define DIAG_MSGS_H_

// Diagnostic messages.
//
// Note: these messages should be 8 bit, so max message is 0xFF.
//
#define DIAG_MSG_MAP_OS_DRAM_DONE                   0x01
#define DIAG_MSG_INIT_ENTERED                       0x02
#define DIAG_MSG_LOAD_SYS_DRV                       0x03
#define DIAG_MSG_LOAD_SYS_DRV_DONE                  0x04
#define DIAG_MSG_INIT_SYS_DRV_DONE                  0x05
#define DIAG_MSG_GFX_IF_INIT_DONE                   0x06
#define DIAG_MSG_AMD_TEE_INIT_DONE                  0x07

#define DIAG_MSG_SUSPEND_ENTER                      0x20
#define DIAG_MSG_SUSPEND_THREADS_IDLE               0x21
#define DIAG_MSG_SUSPEND_WFI_STATE                  0x22
#define DIAG_MSG_RESUME_DONE                        0x25
#define DIAG_MSG_SXINFO_CMD_DONE                    0x26
#define DIAG_MSG_SXINFO_MEMMAP_ERROR                0x27
#define DIAG_MSG_RESUME_ERROR                       0x30

#define DIAG_MSG_TPM_COMMAND_ENTER                  0x32
#define DIAG_MSG_TPM_COMMAND_EXIT                   0x33
#define DIAG_MSG_TPM_COMMAND_BUFFER_ERROR           0x34
#define DIAG_MSG_TPM_STATUS_RESET_REQUIRED          0x3A
#define DIAG_MSG_TPM_STATUS_ASSERT                  0x3B

#define DIAG_MSG_BIOS_COMMAND_ENTER                 0x40
#define DIAG_MSG_BIOS_COMMAND_RUN                   0x41
#define DIAG_MSG_BIOS_COMMAND_EXIT                  0x42
#define DIAG_MSG_BIOS_COMMAND_ERROR                 0x43

#define DIAG_MSG_SMM_COMMAND_ENTER                  0x44
#define DIAG_MSG_SMM_COMMAND_CHECK_SMM              0x45
#define DIAG_MSG_SMM_COMMAND_SMM_READY              0x46
#define DIAG_MSG_SMM_COMMAND_CHECK_RESP             0x47
#define DIAG_MSG_SMM_COMMAND_RESP                   0x48
#define DIAG_MSG_SMM_COMMAND_EXIT                   0x49
#define DIAG_MSG_SMM_COMMAND_RESP_ERROR             0x4A
#define DIAG_MSG_SMM_COMMAND_RQST_ERROR             0x4B

#define DIAG_MSG_SECUREUNLOCK_ASD_ERROR             0x4C

#define DIAG_MSG_PROM_AUTH_BAD_DEVICE               0x4D
#define DIAG_MSG_PROM_AUTH_MAP_FAILED               0x4E
#define DIAG_MSG_PROM_AUTHENTICATED                 0x4F
#define DIAG_MSG_PROM_AUTH_FAILED                   0x50
#define DIAG_MSG_PROM_AUTH_SKIPPED                  0x51
#define DIAG_MSG_PROM_AUTH_NOT_REQUIRED             0x52

#define DIAG_MSG_I2C_AUTH_MAP_FAILED                0x53
#define DIAG_MSG_KNOLL_AOAC_DONE                    0x54
#define DIAG_MSG_KNOLL_INIT_COMPLETE                0x55
#define DIAG_MSG_KNOLL_IDLE_FAIL                    0x56
#define DIAG_MSG_KNOLL_DEV_ID_INVALID               0x57
#define DIAG_MSG_KNOLL_MAC_COMPLETE                 0x58
#define DIAG_MSG_KNOLL_VERIFIED                     0x59
#define DIAG_MSG_KNOLL_NONCE_COMPLETE               0x5A

#define DIAG_MSG_RWM_ACCESS_ERROR	            0x5B

#define DIAG_MSG_PROM_BAD_SWITCH                    0x5C

#define DIAG_MSG_PROM_WRONG_ASIC_TYPE               0x5D

#define DIAG_MSG_BIXBY_AUTHENTICATED                0x5E

#endif // DIAG_MSGS_H_
