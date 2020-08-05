/******************************************************************************
  Copyright [2015 - 2019] ADVANCED MICRO DEVICES, INC. All rights reserved.
 
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

#ifndef BL_ERRORCODES_H_
#define BL_ERRORCODES_H_

// Bootloader Return Codes, Error only (0x00 through 0x9F)
typedef enum BL_RETCODE_T
{
    /// <PostCodePrefix> 0xEE000100
    
    BL_OK                               = 0x00, // General - Success
    BL_ERR_GENERIC                      = 0x01, // Generic Error Code
    BL_ERR_MEMORY                       = 0x02, // Generic Memory Error
    BL_ERR_BUFFER_OVERFLOW              = 0x03, // Buffer Overflow
    BL_ERR_INVALID_PARAMETER            = 0x04, // Invalid Parameter(s)
    BL_ERR_DATA_LENGTH                  = 0x05, // Invalid Data Length
    BL_ERR_DATA_ALIGNMENT               = 0x06, // Data Alignment Error
    BL_ERR_NULL_PTR                     = 0x07, // Null Pointer Error
    BL_ERR_FUNCTION_NOT_SUPPORTED       = 0x08, // Unsupported Function
    BL_ERR_INVALID_SERVICE_ID           = 0x09, // Invalid Service ID
    BL_ERR_INVALID_ADDRESS              = 0x0A, // Invalid Address
    BL_ERR_OUT_OF_RESOURCES             = 0x0B, // Out of Resource Error
    BL_ERR_TIMEOUT                      = 0x0C, // Timeout 
    BL_ERR_DATA_ABORT                   = 0x0D, // data abort exception
    BL_ERR_PREFETCH_ABORT               = 0x0E, // prefetch abort exception
    BL_ERR_BOUNDARY_CHECK               = 0x0F, // Out of Boundary Condition Reached
    BL_ERR_DATA_CORRUPTION              = 0x10, // Data corruption
    BL_ERR_INVALID_COMMAND              = 0x11, // Invalid command
    BL_ERR_INCORRECT_PACKAGE_TYPE       = 0x12, // The package type provided by BR is incorrect
    BL_ERR_GET_FW_HEADER                = 0x13, // Failed to retrieve FW header during FW validation
    BL_ERR_KEY_SIZE                     = 0x14, // Key size not supported
    BL_ERR_AGESA0                       = 0x15, // Agesa0 verification error
    BL_ERR_SMUFW                        = 0x16, // SMU FW verification error
    BL_ERR_OEMSIGNING                   = 0x17, // OEM SINGING KEY verification error
    BL_ERR_FWVALIDATION                 = 0x18, // Generic FW Validation error
    BL_ERR_CCP_RSA                      = 0x19, // RSA operation fail - bootloader
    BL_ERR_CCP_PASSTHR                  = 0x1A, // CCP Passthrough operation failed - internal status
    BL_ERR_CCP_AES                      = 0x1B, // AES operation fail
    BL_ERR_STATE_SAVE                   = 0x1C, // CCP state save failed
    BL_ERR_STATE_RESTORE                = 0x1D, // CCP state restore failed
    BL_ERR_SHA                          = 0x1E, // SHA256/384 operation fail - internal status
    BL_ERR_ZLIB                         = 0x1F, // ZLib Decompression operation fail
    BL_ERR_HMAC_SHA                     = 0x20, // HMAC-SHA256/384 operation fail - internal status
    BL_ERR_INVALID_BOOT_SOURCE          = 0x21, // Booted from boot source not recognized by PSP
    BL_ERR_DIR_ENTRY_NOT_FOUND          = 0x22, // PSP directory entry not found
    BL_ERR_SPIROM_WRITE_FAIL            = 0x23, // PSP failed to set the write enable latch
    BL_ERR_SPIROM_BUSY_TIMEOUT          = 0x24, // PSP timed out because spirom took too long
    BL_ERR_CANNOT_FIND_BIOS_DIR         = 0x25, // Cannot find BIOS directory
    BL_ERR_SPIROM_SIZE                  = 0x26, // SpiRom is not valid
    BL_ERR_SECURITY_STATE_DIFF          = 0x27, // slave die has different security state from master
    BL_ERR_SMI_INIT_ERROR               = 0x28, // SMI interface init failure
    BL_ERR_SMI_GENERIC                  = 0x29, // SMI interface generic error
    BL_ERR_INVALID_DIE_ID               = 0x2A, // invalid die ID executes MCM related function
    BL_ERR_INVALID_MCM_CONFIG           = 0x2B, // invalid MCM configuration table read from bootrom
    BL_ERR_DETECT_BOOT_MODE             = 0x2C, // Valid boot mode wasn't detected
    BL_ERR_NVSTORAGE_INIT_FAILURE       = 0x2D, // NVStorage init failure
    BL_ERR_NVSTORAGE_GENERIC            = 0x2E, // NVStorage generic error
    BL_ERR_MCM_MORE_DATA                = 0x2F, // MCM 'error' to indicate slave has more data to send
    BL_ERR_MCM_DATA_LENGTH              = 0x30, // MCM error if data size exceeds 32B
    BL_ERR_MCM_INVALID_ID               = 0x31, // Invalid client id for SVC MCM call
    BL_ERR_MCM_INVALID_STATE            = 0x32, // MCM slave status register contains bad bits
    BL_ERR_MCM_NO_SLAVES                = 0x33, // MCM call was made in a single die environment
    BL_ERR_PSP_SECURE_MAP               = 0x34, // PSP secure mapped to invalid segment (should be 0x400_0000)
    BL_ERR_NO_PHY_CORES_PRESENT         = 0x35, // No physical x86 cores were found on die 
    BL_ERR_SECURE_OS_INSUF_SRAM         = 0x36, // Insufficient space for secure OS (range of free SRAM to SVC stack base) 
    BL_ERR_UNSUP_SYSHUB_TARGET_TYPE     = 0x37, // SYSHUB mapping memory target type is not supported
    BL_ERR_UNMAP_PSP_SECURE_REGION      = 0x38, // Attempt to unmap permanently mapped TLB to PSP secure region
    BL_ERR_SMNMAP_FAILED                = 0x39, // Unable to map an SMN address to AXI space
    BL_ERR_SYSHUBMAP_FAILED             = 0x3A, // Unable to map a SYSHUB address to AXI space
    BL_ERR_CORECONFIG_COUNT_MISMATCH    = 0x3B, // The count of CCXs or cores provided by bootrom is not consistent
    BL_ERR_UNCOMP_IMAGE_SIZE_MISMATCH   = 0x3C, // Uncompressed image size doesn't match value in compressed header
    BL_ERR_UNSUPPORTED_COMP_OPTION      = 0x3D, // Compressed option used in case where not supported
    BL_ERR_FUSE_INFO                    = 0x3E, // Fuse info on all dies don't match
    BL_ERR_PSP_SMU_MSG_FAIL             = 0x3F, // PSP sent message to SMU; SMU reported an error
    BL_ERR_POST_X86_RELEASE_TEST_FAIL   = 0x40, // Function RunPostX86ReleaseUnitTests failed in memcmp()
    BL_ERR_PSP_SMU_INTERFACE            = 0x41, // Interface between PSP to SMU not available.
    BL_ERR_TIMER_PARAM_OVERFLOW         = 0x42, // Timer wait parameter too large
    BL_ERR_TEST_HARNESS_MODULE          = 0x43, // Test harness module reported an error
    BL_ERR_PMU_FW_KEY                   = 0x44, // The PMU FW Public key certificate loading or authentication fails
    BL_ERR_L3CT_BLOCK_WRITE_FAILED      = 0x45, // A write to an L3 register failed, as read-back did not match
    BL_ERR_WARM_MB_SRAMHMAC_FAIL        = 0x46, // Mini-BL, validation of the PSP SRAM image failed on HMAC
                                                // compare
    BL_ERR_MINI_BL_HMAC_UNIT_TEST_FAIL  = 0x47, // Mini-BL CCP HMAC Unit-test failed
    BL_ERR_JUMP_MINI_BL_STACK_OVERFLOW  = 0x48, // Potential stack corruption in jump to Mini BL
    BL_ERR_LOAD_VALIDATE_APOB           = 0x49, // Error in Validate and Loading AGESA APOB SVC call
    BL_ERR_DIAG_BL_FUSES                = 0x4A, // Correct fuse bits for DIAG_BL loading not set
    BL_ERR_UMC_NOT_INIT_BY_AGESA        = 0x4B, // The UmcProgramKeys() function was not called by AGESA
    BL_ERR_WHITE_LISTING                = 0x4C, // Unconditional unlock based on serial numbers failed
    BL_ERR_SYSHUBIF_REG_MISMATCH	= 0x4D, // Syshub register programming mismatch during readback
    BL_ERR_SECURE_FUSE_FAMILY_ID        = 0x4E, // Family ID in MP0_SFUSE_SEC[7:3] not correct
    BL_ERR_NOT_GLOBAL_MASTER            = 0x4F, // An operation was invoked that can only be performed by the GM
    BL_ERR_SMB_TIMEOUT_ACQR_HOST_SEMA   = 0x50, // Failed to acquire host controller semaphore to claim ownership of SMB
    BL_ERR_SMB_TIMEOUT_WAIT_HOST_IDLE   = 0x51, // Timed out waiting for host to complete pending transactions
    BL_ERR_SMB_TIMEOUT_WAIT_SLAVE_IDLE  = 0x52, // Timed out waiting for slave to complete pending transactions
    BL_ERR_SMB_HOST_BUSY                = 0x53, // Unable to kill current transaction on host, to force idle
    BL_ERR_SMB_DEVICE_ERROR             = 0x54, // One of: Illegal command, Unclaimed cycle, or Host time out
    BL_ERR_SMB_BUS_COLLISION            = 0x55, // An smbus transaction collision detected, operation restarted
    BL_ERR_SMB_TRANSACTION_FAILED       = 0x56, // Transaction failed to be started or processed by host, or not completed
    BL_ERR_SMB_UNSOLICITED_INTR_RX      = 0x57, // An unsolicited smbus interrupt was received
    BL_ERR_PSP_SMU_UNSUPPORTED_MSG      = 0x58, // An attempt to send an unsupported PSP-SMU message was made 
    BL_ERR_PSP_SMU_CORRUPTED_TXFR       = 0x59, // An error/data corruption detected on response from SMU for sent msg
    BL_ERR_MCM_STEADY_UNIT_TEST_FAILED  = 0x5A, // MCM Steady-state unit test failed
    BL_ERR_UNFUSED_PART                 = 0x5B, // CcxSecBisiEn not set in fuse RAM
    BL_ERR_UNIT_TEST_UNEXPECTED_RESULT  = 0x5C, // Received an unexpected result
    BL_ERR_OEM_LEAF_KEY_INVALID         = 0x5D, // OEM BIOS signing Sub-CA leaf key failed signature verification
    BL_ERR_OEM_LEAF_KEY_INVALID_USAGE   = 0x5E, // OEM BIOS signing Sub-CA leaf key usage flag violation
    BL_ERR_OEM_LEAF_KEY_MISSING         = 0x5F, // OEM BIOS signing Sub-CA leaf key is missing
    BL_ERR_FUSE_SMN_MAPPING_FAILED      = 0x62, // An error occured whilst attempting to SMN map a fuse register
    BL_ERR_FUSE_BURN_FAILED_SOC         = 0x63, // Fuse burn sequence/operation failed due to internal SOC error
    BL_ERR_FUSE_SENSE_TIMEOUT           = 0x64, // Fuse sense operation timed out
    BL_ERR_FUSE_BURN_FAILED_TIMEOUT     = 0x65, // Fuse burn sequence/operation timed out waiting for burn done
    BL_ERR_SECURE_OS_REVOKED            = 0x66, // Failure status indicating that the given SecureOS has been
                                                // revoked by the current PSP BL.
    BL_ERR_FUSE_FW_ID_REVOKED           = 0x67, // This PSP FW was revoked
    BL_ERR_PLATFORM_ID                  = 0x68, // The platform model/vendor id fuse is not matching the BIOS public key token
    BL_ERR_BIOS_KEY_REV_ID              = 0x69, // The BIOS OEM public key of the BIOS was revoked for this platform
    BL_ERR_PSP_LV2_HEADER_NOT_MATCH     = 0x6A, // PSP level 2 directory not match expected value.
    BL_ERR_BIOS_LV2_HEADER_NOT_MATCH    = 0x6B, // BIOS level 2 directory not match expected value.
    BL_ERR_RESET_IMAGE_NOT_FOUND        = 0x6C, // Reset image not found
    BL_ERR_CCP_INIT                     = 0x6D, // Generic error indicating the CCP HAL initialization failed
    BL_ERR_NVRAM_DRAM_FAIL              = 0x6E, // failure to copy NVRAM to DRAM.
    BL_ERR_INVALID_KEY_USAGE_FLAG       = 0x6F, // Invalid key usage flag
    BL_ERR_UNEXPECTED_FUSE_SET          = 0x70,
    BL_ERR_RSMU_SECURITY_VIOLATION      = 0x71, // RSMU signaled a security violation
    BL_ERR_WAFL_PCS_PROGRAMMING         = 0x72, // Error programming the WAFL PCS registers
    BL_ERR_WAFL_SET_THRESHOLD           = 0x73, // Error setting wafl PCS threshold value
    BL_ERR_LOAD_OEMTRUSTLET             = 0x74, // Error loading OEM trustlets
    BL_ERR_RECOVERY_MODE_SYNC           = 0x75, // Recovery mode accross all dies is not sync'd
    BL_ERR_WAFL_UNCORRECTABLE           = 0x76, // Uncorrectable WAFL error detected
    BL_ERR_MP1_FATAL                    = 0x77, // Fatal MP1 error detected
    BL_ERR_BIOS_RTM_SIG_MISSING         = 0x78, // Bootloader failed to find OEM signature
    BL_ERR_BIOS_COPY                    = 0x79, // Error copying BIOS to DRAM
    BL_ERR_BIOS_VALIDATION              = 0x7A, // Error validating BIOS image signature
    BL_ERR_OEM_KEY_INVALID              = 0x7B,
    BL_ERR_PLATFORM_BINDING             = 0x7C, // Platform Vendor ID and/or Model ID binding violation
    BL_ERR_BIOS_BOOT_FROM_SPI           = 0x7D, // Bootloader detects BIOS request boot from SPI-ROM, which is unsupported for PSB.
    BL_ERR_FUSE_ALREADY_BLOWN           = 0x7E, // Requested fuse is already blown, reblow will cause ASIC malfunction
    BL_ERR_FUSE_ERROR_BLOWNFUSE         = 0x7F, // Error with actual fusing operation
    BL_ERR_FUSE_INFO_P1                 = 0x80, // (Local Master PSP on P1 socket) Error reading fuse info
    BL_ERR_PLATFORM_BINDING_P1          = 0x81, // (Local Master PSP on P1 socket) Platform Vendor ID and/or Model ID binding violation
    BL_ERR_FUSE_ALREADY_BLOWN_P1        = 0x82, // (Local Master PSP on P1 socket) Requested fuse is already blown, reblow will cause ASIC malfunction
    BL_ERR_FUSE_ERROR_BLOWNFUSE_P1      = 0x83, // (Local Master PSP on P1 socket) Error with actual fusing operation
    BL_ERR_MCM_SS_CHECK_FAILED          = 0x84, // Security check failed (not all dies are in same security state)
    BL_ERR_FTPMSIZE_EXCEED_LIMIT        = 0x86, // fTPM binary size exceeds limit allocated in Private DRAM, need to increase the limit
    BL_ERR_FCH_PROGRAM_PM_LPC           = 0x87, // Failed in FCH programming
    BL_ERR_DISABLE_BOOT_TIMER           = 0x88, // Failed while disabling boot timer
    BL_ERR_MAP_SYSHUB_WITH_INLINE_AES   = 0x89, // Failure in mapping syshub with inline AES
    BL_ERR_BIXBY_DETECT_FAILED          = 0x8A, // Bixby not detected (Bixby may not be connected)
    BL_ERR_BIXBY_AUTH_FAILED            = 0x8B, // Bixby Authentication failed
    BL_ERR_TWIX_UNCORRECTABLE           = 0x8D, // Uncorrectable TWIX error detected
    BL_ERR_TWIX_PROGRAMMING             = 0x8E, // Error programming the TWIX PCS registers
    BL_ERR_TWIX_SET_THRESHOLD           = 0x8F, // Error setting TWIX PCS threshold value
    BL_ERR_DXIO_PHY_SRAM_FW_KEY         = 0x90, // The DXIO PHY SRAM Public key certificate loading or authentication fails
    BL_ERR_INVALID_BIXBY_DETECTED       = 0x91, // The Bixby device detected is not valid
    BL_ERR_FWTYPE_MISMATCH              = 0x92, // FW type mismatch between the requested FW type and the FW type embedded in the FW binary header
    BL_ERR_SVC_CALL_ADDR_VIOLATION      = 0x93, // SVC call input parameter address violation    
    BL_ERR_KNOLL_IDLE_FAIL              = 0x94, // Knoll failed to idle correctly after being reset
    BL_ERR_KNOLL_BAD_STATUS             = 0x95, // Bad status returned by I2CKnollCheck
    BL_ERR_NO_KNOLL                     = 0x96, // NACK to general call (no device on Knoll I2C bus)
    BL_ERR_I2C_KNOLL_NULL_PTR           = 0x97, // Null pointer passed to I2CKnollCheck
    BL_ERR_KNOLL_DEV_ID_INVALID         = 0x98, // Invalid device-ID found during Knoll authentication
    BL_ERR_KNOLL_KEY_DERIV              = 0x99, // Error during Knoll/Prom key derivation
    BL_ERR_CCP_NULL_PTR                 = 0x9A, // Null pointer passed to Crypto function
    BL_ERR_KNOLL_WRAP_CHECKSUM          = 0x9B, // Error in checksum from wrapped Knoll/Prom keys
    BL_ERR_KNOLL_INVALID_RESPONSE       = 0x9C, // Knoll returned an invalid response to a command
    BL_ERR_KNOLL_SEND_CMD_FAILED        = 0x9D, // Bootloader failed in Knoll Send Command function
    BL_ERR_KNOLL_TEST_FAILED            = 0x9E, // No Knoll device found by verifying MAC
    BL_ERR_POSTCODE_MAX_VALUE           = 0x9F  // The maximum allowable error post code
} BL_RETCODE;

// Bootloader Return Codes, Success only (0xA0 through 0xFF)
typedef enum BL_TRACECODE_T
{
    BL_SUCCESS_C_MAIN                   = 0xA0, // Bootloader successfully entered C Main
    BL_SUCCESS_P2PMBOX_INIT             = 0xA1, // Master initialized C2P / slave waited for master to init C2P
    BL_SUCCESS_DERIVE_HMAC_KEY          = 0xA2, // HMAC key successfully derived
    BL_SUCCESS_DETECT_BOOT_MODE         = 0xA3, // Master got Boot Mode and sent boot mode to all slaves
    BL_SUCCESS_SPI_INIT                 = 0xA4, // SpiRom successfully initialized
    BL_SUCCESS_COPY_BIOS_DIRECTORY      = 0xA5, // BIOS Directory successfully read from SPI to SRAM
    BL_SUCCESS_CHECK_EARLY_UNLOCK       = 0xA6, // Early unlock check  
    BL_SUCCESS_DERIVE_INLINE_AES_KEY    = 0xA7, // Inline Aes key successfully derived
    BL_SUCCESS_INLINE_AES_KEY_PROGRAM   = 0xA8, // Inline-AES key programming is done
    BL_SUCCESS_INLINE_AES_KEY_WRAPPER   = 0xA9, // Inline-AES key wrapper derivation is done
    BL_SUCCESS_IP_CONFIG                = 0xAA, // Bootloader successfully loaded HW IP configuration values
    BL_SUCCESS_MBAT_PROGRAMMING         = 0xAB, // Bootloader successfully programmed MBAT table
    BL_SUCCESS_LOAD_SMU                 = 0xAC, // Bootloader successfully loaded SMU FW
    BL_SUCCESS_TWIX_LINK_CHECK          = 0xAD, // TWIX link partner detection successfully done
    BL_SUCCESS_USER_MODE_TEST_HARNESS   = 0xAE, // User mode test harness completed successfully
    BL_SUCCESS_START_AGESA              = 0xAF, // Bootloader loaded Agesa0 from SpiRom
    BL_SUCCESS_FINISHED_AGESA           = 0xB0, // AGESA phase has completed
    BL_SUCCESS_POST_DRAM_TESTS          = 0xB1, // RunPostDramTrainingTests() completed successfully
    BL_SUCCESS_LOAD_SMU_FW_TO_DRAM      = 0xB2, // SMU FW Successfully loaded to SMU Secure DRAM
    BL_SUCCESS_PSP_SMU_SENT_ALL_CMDS    = 0xB3, // Sent all required boot time messages to SMU
    BL_SUCCESS_RUN_SECURITY_GASKET      = 0xB4, // Validated and ran Security Gasket binary
    BL_SUCCESS_UMC_SECURITY_INIT        = 0xB5, // UMC Keys generated and programmed
    BL_SUCCESS_STORE_WRAPPED_KEY        = 0xB6, // Inline AES key wrapper stored in DRAM
    BL_SUCCESS_VALIDATED_OEM_KEY        = 0xB7, // Completed FW Validation step
    BL_SUCCESS_VALIDATED_BIOS_RST       = 0xB8, // Completed FW Validation step
    BL_SUCCESS_LOADING_BIOS_COMPONENTS  = 0xB9, // BIOS copy from SPI to DRAM complete
    BL_SUCCESS_VALIDATED_BIOS           = 0xBA, // Completed FW Validation step
    BL_SUCCESS_BIOS_LOAD_COMPLETE       = 0xBB, // BIOS load process fully complete 
    BL_SUCCESS_RELEASE_X86              = 0xBC, // Bootloader successfully release x86
    BL_SUCCESS_NORMAL_UNLOCK            = 0xBD, // Early Secure Debug completed
    BL_SUCCESS_GET_VERSION_COMMAND      = 0xBE, // GetFWVersion command received from BIOS is completed
    BL_SUCCESS_SMI_INFO_COMMAND         = 0xBF, // SMIInfo command received from BIOS is completed
    BL_SUCCESS_ENTER_WARM_BOOT          = 0xC0, // Successfully entered WarmBootResume()
    BL_SUCCESS_PCIE_LINK_TRAINED        = 0xC1, // The PCIE Link between Matisse and Bixby is trained
    BL_ERR_PCIE_LINK_NOT_TRAINED        = 0xC2, // The PCIE link between Matisse and Bixby is not trained (This may mean that Bixby is not connected)
    BL_SUCCESS_BIXBY_DETECTED           = 0xC3, // Successfully detected the Bixby device is connected
    BL_SUCCESS_BIXBY_BOOTROM_READY      = 0xC4, // Bixby Bootrom has unlocked the Bixby MP1 SRAM for Matisse to download Image
    BL_SUCCESS_BIXBY_IMAGE_DOWNLOAD     = 0xC5, // Successfully downloaded Bixby Image into Bixby MP1 SRAM
    BL_SUCCESS_INTERRUPT_SENT_TO_BIXBY  = 0xC6, // Interrupt sent to Bixby Bootrom, by setting MP0_C2PMSG32 to 0x1
    BL_SUCCESS_SAVE_UMC_STATE           = 0xC7, // Save the UMC State successfully for S3 suspend
    BL_SUCCESS_IN_BL_ENTRY              = 0xC8, // Updated only PSPFW Status when BL entered
    BL_SUCCESS_FCH_PROGRAM_PM_LPC       = 0xC9, // Updated only PSPFW Status when FCH programmed
    BL_SUCCESS_DISABLE_BOOT_TIMER       = 0xCA, // Updated only PSPFW Status when boottimer disabled
    BL_SUCCESS_MAP_SYSHUB_INLINE_AES    = 0xCB, // Updated only PSPFW Status when derived and programmed syshub inline AES
    BL_SUCCESS_VMG_KDF_TEST_PASS        = 0xCC, // VMG SP800-108 KDF-CTR HMAC unit test passed
    BL_SUCCESS_VMG_LAUNCH_TEST_START    = 0xCD, // VMG LAUNCH_* test started
    BL_SUCCESS_VMG_LAUNCH_TEST_PASS     = 0xCE, // VMG LAUNCH_* test passed
    BL_SUCCESS_MP1_RESET_COMPLETE       = 0xCF, // MP1 has been taken out of reset, and executing SMUFW
    BL_SUCCESS_PSP_SMU_RESERVED_PROG    = 0xD0, // PSP and SMU Reserved Addresses correct
    BL_SUCCESS_SSP_STEADY_STATE         = 0xD1, // Reached Naples steady-state WFI loop
    BL_SUCCESS_KNOLL_INIT_COMPLETE      = 0xD2, // Knoll device successfully initialized
    BL_SUCCESS_KNOLL_NONCE_COMPLETE     = 0xD3, // 32-byte RandOut successfully returned from Knoll
    BL_SUCCESS_KNOLL_MAC_COMPLETE       = 0xD4, // 32-byte MAC successfully received from Knoll.
    BL_SUCCESS_KNOLL_VERIFIED           = 0xD5, // Knoll device verified successfully
    BL_SUCCESS_KNOLL_AOAC_DONE          = 0xD6, // Done enabling power for Knoll
    BL_RECOVERY_TRUSTLET_VALIDATE_FAIL  = 0xD7, // Enter recovery mode due to trustlet validation fail.
    BL_RECOVERY_OS_VALIDATE_FAIL        = 0xD8, // Enter recovery mode due to OS validation fail.
    BL_RECOVERY_OEM_PUBLIC_KEY_FAIL     = 0xD9, // Enter recovery mode due to OEM public key not found.
    BL_RECOVERY_HEADER_CORRUPTION       = 0xDA, // Enter recovery mode with header corruption
    BL_ERR_SECURE_UNLOCK_FAIL           = 0xDB, // We should not treat this error as blocking
#ifdef BUILD_OEM
    BL_SUCCESS_COLD_LOAD_OEMTRUSTKEY    = 0xDC, // Bootloader successfully loaded OEM Truslet Key
    BL_SUCCESS_COLD_VERIFY_OEMTRUSTKEY  = 0xDD, // Bootloader successfully hashed the OEM Truslet Key
    BL_SUCCESS_COLD_LOAD_OEMTA          = 0xDE, // Bootloader successfully loaded OEM Truslet Key
#endif
    BL_SUCCESS_BIXBY_BL_READY           = 0xE0, // The Bixby Bootloader entered steady state successfully
    BL_SUCCESS_BIXBY_AUTHENTICATION     = 0xE1, // The Bixby Is Successfully Authenticated.
    BL_SUCCESS_MP1_SRAM_LOAD            = 0xE4, // MP1 firmware load to SRAM success
    BL_SUCCESS_MP1_SRAM_READ            = 0xE5, // Bootloader read the MP1 SRAM successfully
    BL_SUCCESS_MP1_RESET_DONE           = 0xE6, // Bootloader successfully reset MP1
    BL_SUCCESS_MP5_ROM_READY            = 0xE9, // MP5 Boot ROM code ready
    BL_SUCCESS_MP5_ASSERT_RESET         = 0xEA, // Bootloader successfully asserted MP5 reset
    BL_SUCCESS_MP5_SRAM_LOAD            = 0xEB, // MP5 load to SRAM success
    BL_SUCCESS_MP5_RESET_VECTOR_SEL     = 0xEC, // Bootloader successfully set MP5 reset vector to SRAM
    BL_SUCCESS_MP5_DEASSERT_RESET       = 0xED, // Bootloader successfully de-asserted MP5 reset
    BL_SUCCESS_MP5_FW_READY             = 0xEE, // MP5 firmware is running and ready
    BL_SUCCESS_S3_IMAGE_LOAD_DONE       = 0xEF, // Loading of S3 image done successfully
    BL_SUCCESS_2K4K_KEY_VERIFY          = 0xF0, // Bootloader successfully verify signed image using 4K/2K key
    BL_SUCCESS_MULTI_SOCKET_BOOT        = 0xF1, // Bootloader identified as running on SP32P or multi-socket boot
    BL_SUCCESS_SECURITY_POLICY_CHECK    = 0xF2, // Security Policy check successful (only in secure boot)
    BL_SUCCESS_SS3                      = 0xF4, // Bootloader successfully loaded SS3
    BL_SUCCESS_FTPM                     = 0xF5, // Bootloader successfully loaded fTPM
    BL_SUCCESS_SYS_DRV                  = 0xF6, // Bootloader successfully loaded sys_drv
    BL_SUCCESS_SOS                      = 0xF7, // Bootloader successfully loaded secure OS
    BL_SUCCESS_RESUMED_SOS              = 0xF8, // Bootloader successfully verified PSP SRAM on S3 resume
    BL_SUCCESS_CONTROL_TO_SOS           = 0xF9, // Bootloader about to transfer control to secureOS
    BL_SUCCESS_BIXBY_ABL_FW_EXECUTION   = 0xFA, // Bixby ABL successfully completed execution
    BL_SUCCESS_BIXBY_MP1_FW_DOWNLOAD    = 0xFB, // Successfully downloaded MP1 f/w into Bixby MP1 SRAM
    BL_SUCCESS_SEC_POLICY               = 0xFC, // Indicates security policy loaded in DRAM from SPI-ROM
    BL_SUCCESS_BOOT_DONE                = 0xFF  // Bootloader sequence finished
} BL_TRACECODE;

#endif // BL_ERRORCODES_H_
