/******************************************************************************
  Copyright [2015-2019] ADVANCED MICRO DEVICES, INC. All rights reserved.
 
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

#ifndef BL_SYSCALL_H_
#define BL_SYSCALL_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <bl_errorcodes.h>

#define SVC_EXIT                            0x00
#define SVC_MAP_USER_STACK                  0x01
#define SVC_LOAD_BINARY                     0x02
#define SVC_MAP_SMN_ON_DIE_NUM              0x03
#define SVC_MAP_SMN_ON_CURRENT_DIE          0x04
#define SVC_UNMAP_SMN                       0x05
#define SVC_DEBUG_PRINT                     0x06
#define SVC_MAP_SYSHUB                      0x07
#define SVC_UNMAP_SYSHUB                    0x08
#define SVC_READ_SYSHUB                     0x09
#define SVC_WRITE_SYSHUB                    0x0A
#define SVC_SHA256                          0x0B
#define SVC_MODEXP                          0x0C
#define SVC_RSAPSS_VERIFY                   0x0D
#define SVC_AES_ECB_ENCRYPT                 0x0E
#define SVC_SHA256_OTP                      0x0F
#define SVC_GET_MCM_INFO                    0x10
#define SVC_WAIT_FOR_MASTER_STATUS          0x11
#define SVC_SET_MASTER_STATUS               0x12
#define SVC_MASTER_BROACAST                 0x13
#define SVC_SLAVE_GET_BROACAST_DATA         0x14
#define SVC_SAVE_APOB_DATA                  0x15
#define SVC_SEARCH_BIOS_DIR                 0x16
#define SVC_GET_DATA_FROM_SLAVES            0x17
#define SVC_SEND_DATA_TO_MASTER             0x18
#define SVC_SET_DEBUG_STATE                 0x19
#define SVC_DEBUG_PRINT_EX                  0x1A
#define SVC_WAIT_10NS_MULTIPLE              0x1B
#define SVC_GET_BOOT_MODE                   0x1C
#define SVC_OTP_HMAC256_SIGN                0x1D
#define SVC_SPILOAD_VALIDATE_HMAC256_APOB   0x1E
#define SVC_GET_DEBUG_UNLOCK_INFO           0x1F
#define SVC_SET_DEBUG_UNLOCK_INFO           0x20
#define SVC_PROGRAM_UMC_KEYS                0x21
#define SVC_READ_SMBUS_BYTE                 0x22
#define SVC_SYNC_UNLOCK_INFO                0x23
#define SVC_MCM_SYNC_ON_DATA                0x24
#define SVC_MAP_SYSHUB_EX                   0x25
#define SVC_READ_SYSHUB_EX                  0x26
#define SVC_WRITE_SYSHUB_EX                 0x27
#define SVC_SEND_PSP_SMU_MSG                0x28
#define SVC_WRITE_SMBUS_BYTE                0x29
#define SVC_SET_PSP_SMU_RESERVED            0x2A
#define SVC_MCM_SYNCHRONIZATION_POINT       0x2B
#define SVC_GMI_NON_FUNCTIONAL              0x2C
#define SVC_LOAD_FW_IMAGE_BY_INSTANCE       0x2D
#define SVC_ECDSA_VERIFY                    0x2E
#define SVC_ECDSA_SIGN                      0x2F
#define SVC_GMI_NONCE_KEY_PROGRAM           0x30
#define SVC_SEV_MASTER_TO_SLAVE             0x31
#define SVC_SEV_PERSISTENT_WRITE            0x32
#define SVC_SEV_PERSISTENT_READ             0x33
#define SVC_SEV_PERSISTENT_ERASE            0x34
#define SVC_SEV_KEY_DERIVE                  0x35
#define SVC_AES_GENERIC                     0x36
#define SVC_CACHE_OPERATION                 0x37
#define SVC_SHA256_GENERIC                  0x38
#define SVC_TRNG                            0x39
#define SVC_SET_MIN_SEV_ASID                0x3A
#define SVC_GET_MIN_SEV_ASID                0x3B
#define SVC_GET_SEV_RESERVED_DRAM           0x3C
#define SVC_LOAD_BINARY_FROM_SUBTYPE        0x3D
#define SVC_GET_SECURE_DEBUG_STATUS         0x3E
#define SVC_GET_ROOT_KEY_HASH               0x3F
// Note: More room here
#define SVC_SLAVE_UNLOCK_REQUEST            0x40
#define SVC_ECC_PRIMITIVE                   0x41
#define SVC_GET_CUK                         0x42
#define SVC_SEARCH_BIOS_DIR_V2              0x43
#define SVC_GET_SECURE_GASKET_MODE          0x44
#define SVC_CCP_INFLATE_OUT                 0x47
#define SVC_GET_SMM_RANGE                   0x48
#define SVC_SET_WAFL_THRESHOLD_PARAMS       0x49
#define SVC_SET_PSP_DEBUG_MODE              0x4A
#define SVC_GET_MASTERDIE_SN                0x4B
#define SVC_SET_SYSHUB_WDTTIMER_INTERVAL    0x4C
#define SVC_LOAD_BINARY_BY_ATTRIB           0x4D
#define SVC_REMAP_MBAT_ENTRY                0x4E
#define SVC_SET_TWIX_THRESHOLD_PARAMS       0x4F
#define SVC_SET_8T_16T_MODE                 0x53
#define SVC_GET_8T_16T_MODE                 0x54
#define SVC_SHA                             0x55
#define SVC_GET_PSP_VERSION                 0x58
#define SVC_SET_BIXBY_DEVICE_INFO           0x59
#define SVC_READ_HARVEST_FUSE               0x5C

typedef enum SECURE_GASKET_MODE
{
    SECURE_GASKET_MODE_APPLY_EARLY,
    SECURE_GASKET_MODE_REVERT
} SECURE_GASKET_MODE;

/* ----------------------------------------------------------------
    SHA types same as ccp SHA type in crypto.h
*/
typedef enum SHA_TYPE_T
{
    SHA_TYPE_256,
    SHA_TYPE_384,
    SHA_TYPE_512,
} SHA_TYPE;

// All SHA operations supported. 
typedef enum SHA_OPERATION_MODE
{
    SHA,
    SHA_OTP,
    SHA_HMAC,
    SHA_GENERIC
} SHA_OPERATION_MODE;

// SHA Supported Data Structures
typedef struct SHA_GENERIC_DATA_T
{
    SHA_TYPE            SHAType;
    uint8_t*            Data;
    size_t              DataLen;
    uint32_t            DataMemType;
    uint8_t*            Digest;
    size_t              DigestLen;
    uint8_t*            IntermediateDigest;
    size_t              IntermediateMsgLen;
    uint32_t            Init;
    uint32_t            Eom;
} SHA_DATA;

typedef struct SHA_OTP_DATA_T
{
    SHA_TYPE            SHAType;
    uint8_t*            pHash;
}SHA_OTP_DATA;

typedef struct SHA_HMAC_DATA_T
{
    SHA_TYPE            SHAType;
    uint8_t             *pHmac; 
    uint32_t            DataSize;
    uint8_t             *pData;
}SHA_HMAC_DATA;

typedef union SHA_OPERATION_T
{
    SHA_DATA                 SHA;
    SHA_OTP_DATA             SHA_OTP;
    SHA_HMAC_DATA            SHA_HMAC;
}SHA_OPERATION;


/*-----------------------------------------------------------------------------
    Mod Exp parameter structure as services can only pass in 4 parameters
*/
typedef struct MOD_EXP_PARAMS_T
{
    char                *pExponent;     // Exponent address
    unsigned int        ExpSize;        // Exponent size in bytes
    char                *pModulus;      // Modulus address
    unsigned int        ModulusSize;    // Modulus size in bytes
    char                *pMessage;      // Message address
    char                *pOuput;        // Output address; Must be big enough to hold the data of ModulusSize
} MOD_EXP_PARAMS;

/*-----------------------------------------------------------------------------
    RSA PSS parameter structure as services can only pass in 4 parameters
*/
typedef struct RSAPSS_VERIFY_PARAMS_T
{
    char                *pHash;         // Message digest to verify the RSA signature
    unsigned int        HashLen;        // hash length in bytes
    char                *pModulus;      // Modulus address
    unsigned int        ModulusSize;    // Modulus length in bytes
    char                *pExponent;     // Exponent address
    unsigned int        ExpSize;        // Exponent length in bytes
    char                *pSig;          // Signature to be verified, same size as ModulusSize
} RSAPSS_VERIFY_PARAMS;

/*-----------------------------------------------------------------------------
    AES ECB parameter structure as services can only pass in 4 parameters
*/
typedef struct AES_ECB_ENCRYPT_PARAMS_T
{
    unsigned int        Key;            // Key (either pointer to local memory or LSB number)
    unsigned int        KeyMemType;     // Key memory type
    unsigned int        KeySize;        // Key size in bytes; valid values 16, 24 and 32
    char                *pSrc;          // Source address, must be 16 byte aligned
    unsigned int        SrcMemType;     // Source memory type
    unsigned int        SrcLen;         // Source length, must be non-zero multiple of 16
    char                *pDest;         // Destinateion address, must be 16 byte aligned
    unsigned int        DestMemType;    // Destination memory type
} AES_ECB_ENCRYPT_PARAMS;


/*-----------------------------------------------------------------------------
 *     MCM configuration information to be returned to the caller.
 */
typedef struct MCM_INFO_T
{
    unsigned int        NumSockets;        // Number of sockets (BOOT_ROM_TABLE->Data.McmConfig.SocketNum)
    unsigned int        NumDies;           // Number of dies per socket (BOOT_ROM_TABLE->Data.McmConfig.DieNum)
    unsigned int        CurrentSocketId;   // Current Socket ID (BOOT_ROM_TABLE->Data.McmConfig.SocketId)
    unsigned int        CcdPresentBitMask; // Bit mask for CCD Present, 1:CCD Present, 0:CCD not present/Downcored
    // TODO: Fix the hardcoding to 8 CCDs
    uint8_t             CorePresentInCCDBitMask[8]; // Bit mask for cores present for each CCDs, 1:Core Present, 0: Core not present. [0:3] = CCX0 [7:4] = CCX1
    unsigned int        RecoveryMode;      // Recovery Mode Status
} MCM_INFO;

typedef struct TypeAttrib_t
{
    uint32_t Type : 8 ;             // Type of BIOS entry 0x60,0x61,0x62
    uint32_t RegionType : 8;         // 0 - non Secure, 1 - ARM TA1 , 2 - ARM TA2 , 3 - ARM TMZ, 4 - Reset
    uint32_t BiosResetImage : 1;    // Set for SEC or EL3 fw,
    uint32_t Copy : 1;                 // Set for copy
    uint32_t ReadOnly : 1;             // 0 - write, 1 - read only
    uint32_t CompressedZlib : 1;     // 0 - no compression, 1 - Zlib compressed
    uint32_t Instance : 4;          // Specify the instance of an entry
    uint32_t Reserved : 8;
} TypeAttrib;                        // Type & BIOS_FIRMWARE Attribute field

typedef uint8_t     BIOS_DIRECTORY_ENTRY_TYPE;
typedef TypeAttrib  BIOS_DIRECTORY_TYPE_ATTRIB;

typedef struct {
    BIOS_DIRECTORY_ENTRY_TYPE    EntryType;
    uint32_t                     *pDataSourceAddr; 
    uint64_t                     *pDataDestAddr; 
    uint32_t                     *pDataLength; 
    BIOS_DIRECTORY_TYPE_ATTRIB   *pAttrib; 
    uint8_t                      index;
}BIOS_DIR_SEARCH_PARMS;

typedef struct {
    uint32_t                    Size;               // Size of (BIOS_DIR_SEARCH_PARMS_v2)
    void                        **pSmnBiosDirBaseAddr; // SMN address mapped by PSP on gBiosBaseAddr
    BIOS_DIRECTORY_ENTRY_TYPE   EntryType;
    uint32_t                    *pDataSourceAddr; 
    uint64_t                    *pDataDestAddr; 
    uint32_t                    *pDataLength; 
    BIOS_DIRECTORY_TYPE_ATTRIB  *pAttrib; 
    uint8_t                     index;
}BIOS_DIR_SEARCH_PARMS_V2;

typedef enum _BIOS_DIRECTORY_ENTRY_TYPE {
    BIOS_PUBLIC_KEY                 = 0x05, // BIOS OEM public key, signed by AMD root private key
    BIOS_PUBLIC_LEAF_KEY            = 0x06, // BIOS OEM Signing Leaf Key signed by the OEM public key
    BIOS_RTM_SIGNATURE              = 0x07, // Signed hash of RTM volume concatenated with BIOS DIRECTORY
    BIOS_APCB_INFO                  = 0x60, // Agesa PSP Customization Block (APCB)
    BIOS_APOB_INFO                  = 0x61, // Agesa PSP Output Block (APOB) target location
    BIOS_FIRMWARE                   = 0x62, // BIOS Firmware volumes, also referred as RTM volume with reset flag
    BIOS_APOB_DATA                  = 0x63, // Agesa PSP Output Block data and HMAC
    BIOS_APPB_IMEM                  = 0x64, // Agesa PMU FW IMEM
    BIOS_APPB_DMEM                  = 0x65, // Agesa PMU FW DMEM
    BIOS_APCB_RO_INFO               = 0x68, // Agesa RO PSP Customization Block (APCB)
    BIOS_ABL_VGA                    = 0x6C, // Agesa loading VGA information
    BIOS_ABL_INSTANCE               = 0x6D, // Agesa loading VGA information
} BIOS_DIRECTORY_ENTRY_TYPE_E;

typedef enum _PSP_BOOT_MODE
{
    PSP_BOOT_MODE_S0 = 0x0,
    PSP_BOOT_MODE_S0i3_RESUME = 0x1,
    PSP_BOOT_MODE_S3_RESUME = 0x2,
    PSP_BOOT_MODE_S4 = 0x3,
    PSP_BOOT_MODE_S5_COLD = 0x4,
    PSP_BOOT_MODE_S5_WARM = 0x5,
} PSP_BOOT_MODE;

//    TLB2_n settings for AWUSER and TLB3_n settings for ARUSER: 
//    USER[0] - ReqIO bit, 1'b1 for FCH MMIO address
//    USER[1] - Compat bit, 1'b1 for FCH access, 0 for everything else
//    USER[2] - ByPass_IOMMU bit, 1'b1 to always bypass IOMMU, 0 for IOMMU translation
typedef enum SYSHUB_TARGET_TYPE_E
{
    // Target Type                      // Address                // [2:0] =[ Bypass,Compat,ReqIO]
    AxUSER_PCIE_HT0             = 0x0,  // PCIe HT (Bypass=0)     // [2:0] =[ 0,0,0]
    AxUSER_DRAM_VIA_IOMMU       = 0x1,  // DRAM ACCESS via IOMMU  // [2:0] =[ 0,0,1]
    AxUSER_PCIE_HT1             = 0x2,  // PCIe HT  (Bypass=1)    // [2:0] =[ 0,1,0]            
    AxUSER_RSVD                 = 0x3,  // - NOT USED ,INVALID    // [2:0] =[ 0,1,1]
    AxUSER_DRAM_BYPASS_IOMMU    = 0x4,  // GENERAL DRAM           // [2:0] =[ 1,0,0]
    AxUSER_PCIE_MMIO            = 0x5,  // PCIe MMIO              // [2:0] =[ 1,0,1]
    AxUSER_FCH_HT_IO            = 0x6,  // FCH HT (port80)        // [2:0] =[ 1,1,0]
#if 0
    AxUSER_FCH_MMIO             = 0x7   // FCH MMIO               // [2:0] =[ 1,1,1]
#else
        // TODO(bwd): clean-up properly
    AxUSER_FCH_MMIO             = 0x6   // FCH MMIO               // [2:0] =[ 1,1,1]
#endif
    // HDM: TODO Bit ATid[5:3] - Address Translation ID, indication of which page table will be used
    // in IOMMU, (only valid when Bypass=1'b0, but we have 3 of those)
} SYSHUB_TARGET_TYPE;

typedef struct SYSHUB_RW_PARMS_EX_E
{
    unsigned int SyshubAddressLo;
    unsigned int SyshubAddressHi;
    unsigned int* pValue;
    unsigned int Size;
    SYSHUB_TARGET_TYPE TargetType;
} SYSHUB_RW_PARMS_EX;

typedef struct AES_GENERIC_E 
{
    uint8_t*            Iv;
    size_t              IvLength; 
    const uint8_t*      Key;
    size_t              KeyLength;
    uint32_t            KeyMemType;
    const uint8_t*      Src; 
    size_t              SrcLength;
    uint32_t            SrcMemType;
    const uint8_t*      Dest;
    size_t              DestLength;
    uint32_t            DestMemType;
    uint32_t            AesAlg;
    uint32_t            AesMode;
} AES_GENERIC;


// Master status bits [31:24] assigned as AGESA status bits. It is up to AGESA team
// to define individual bit values.
#define AGESA_MASTER_STATUS_BITS        0xFF000000

#define CLIENT_ID_AGESA                 0

/*-----------------------------------------------------------------------------
    Exit to the main Boot Loader. This does not return back to user application.

    Parameters:
        Status  -   either Ok or error code defined by AGESA
*/
__svc(SVC_EXIT) void Svc_Exit( unsigned int Status );


/*-----------------------------------------------------------------------------
    Maps buffer for stack usage.

    Parameters:
        StartAddr   -   start address of the stack buffer
        EndAddr     -   end of the stack buffer
        pStackVa    -   [out] mapped stack Virtual Address

    Return value: BL_OK or error code
*/
__svc(SVC_MAP_USER_STACK) unsigned int Svc_MapUserStack(    unsigned int    StartAddr,
                                                            unsigned int    EndAddr,
                                                            unsigned int*   pStackVa );

/*-----------------------------------------------------------------------------
    Maps buffer for stack usage.

    Parameters:
        PspDirType  -   type of PSP directory entry to load from
        pDest       -   memory address to load data to
        pDestSize   -   on input - max pDest size, on output - actual loaded size

    Return value: BL_OK or error code
*/
__svc(SVC_LOAD_BINARY) unsigned int Svc_LoadBinary( BIOS_DIRECTORY_ENTRY_TYPE_E    PspDirType,
                                                    void*           pDest,
                                                    unsigned int*   pDestSize );

/*
 * IMPORTANT NOTE: MUST Read for Rome (2P) configuration
 * -----------------------------------------------------
 *
 * For accessing SMN address space on 2P configuration, userspace application
 * must use the right SVC API, based on where the SMN address space belongs to.
 *
 * Please read below information carefully and chose the right API as needed -
 *
 * 1. Master PSP accessing Master Socket SMN address space
 *
 *    API tobe used:
 *      Svc_MapSmnOnCurrentDie(Address);
 *      Or
 *      Svc_MapSmnOnDieNum(Address, 0);
 *
 * 2. Master PSP accessing Slave Socket SMN address space
 *
 *    API tobe used: 
 *      Svc_MapSmnOnDieNum(Address, 1);
 *
 * 3. Slave PSP accessing Slave Socket SMN address space
 *
 *    API tobe used: 
 *      Svc_MapSmnOnCurrentDie(Address);
 *      Or
 *      Svc_MapSmnOnDieNum(Address, 1)
 *
 * 4. Slave PSP accessing Master Socket SMN address space
 *
 *    API tobe used: 
 *      Svc_MapSmnOnDieNum(Address, 0).
 *
 *
 * Now, for the address space of resources interfaced to Master Socket, for example
 * SPIROM connected to Master Socket FCH,
 *
 * 1. Access from Master Socket PSP
 *    Since resource (in this example, SPIROM) is local to Master socket, App can use
 *
 *    Svc_MapSmnOnCurrentDie(Address);
 *    Or
 *    Svc_MapSmnOnDieNum(Address, 0)
 *
 * 2. Access from Slave Socket PSP
 *    For Slave Socket it is remote access, so App must use,
 *
 *    Svc_MapSmnOnDieNum(Address, 0);
 *
 *
 * To keep common code between Master and Slave Socket, please use
 *
 *    Svc_MapSmnOnDieNum(Address, 0);
 *
 * */

/*-----------------------------------------------------------------------------
    Map SMN TLB for access to SMN address on specific die in MCM configuration.

    Parameters:
        SmnAddress  -   address in SMN address space
        DieNum      -   die number on which the SMN address is located

    Return value:
        on success  -   mapped address in AXI space
        on error    -   NULL
*/
__svc(SVC_MAP_SMN_ON_DIE_NUM) void* Svc_MapSmnOnDieNum( unsigned int    SmnAddress,
                                                        unsigned int    DieNum );

/*-----------------------------------------------------------------------------
    Map SMN TLB for access to SMN address on the current die.

    Parameters:
        SmnAddress  -   address in SMN address space

    Return value:
        on success  -   mapped address in AXI space
        on error    -   NULL
*/
__svc(SVC_MAP_SMN_ON_CURRENT_DIE) void* Svc_MapSmnOnCurrentDie( unsigned int SmnAddress );


/*-----------------------------------------------------------------------------
    Unmap SMN TLB for AXI address previously mapped using Svc_MapSmnOnDieNum()
    or Svc_MapSmnOnCurrentDie().

    Parameters:
        pAxiAddress -   address in AXI address space previously mapped
                        using Svc_MapSmnOnDieNum() or Svc_MapSmnOnCurrentDie()

    Return value: BL_OK or error code
*/
__svc(SVC_UNMAP_SMN) unsigned int Svc_UnmapSmn( void* pAxiAddress );


/*-----------------------------------------------------------------------------
    Enable or disable debug printing in simnow environment dynamically during runtime.

    Parameters:
        fEnable -   1 to enable debug print output, 0 to disable
*/
__svc(SVC_SET_DEBUG_STATE) void Svc_SetDebugState( uint32_t fEnable );


/*-----------------------------------------------------------------------------
    Print debug message into SimNow console. In emulation environment and on
    real silicon does not do anything.

    Parameters:
        pString -   null-terminated string
*/
__svc(SVC_DEBUG_PRINT) void Svc_DebugPrint( const char* pString );


/*-----------------------------------------------------------------------------
    Print 4 DWORD values in hex into SimNow console. In emulation environment and on
    real silicon does not do anything.

    Parameters:
        Dword0...Dword3 - 32-bit DWORD to print
*/
__svc(SVC_DEBUG_PRINT_EX) void Svc_DebugPrintEx( uint32_t Dword0, 
                                                 uint32_t Dword1,
                                                 uint32_t Dword2,
                                                 uint32_t Dword3);


/*-----------------------------------------------------------------------------
    Map SYSHUB TLB for access to SYSHUB address.

    Parameters:
        SyshubAddressLo -   low order 32 bit of address in SYSHUB address space
        SyshubAddressHi -   high order 32 bit of address in SYSHUB address space

    Return value:
        on success  -   mapped address in AXI space
        on error    -   NULL
*/
__svc(SVC_MAP_SYSHUB) void* Svc_MapSysHub( unsigned int SyshubAddressLo, unsigned int SyshubAddressHi );


/*-----------------------------------------------------------------------------
    Unmap SYSHUB TLB for AXI address previously mapped using Svc_MapSyshub().

    Parameters:
        pAxiAddress -   address in AXI address space previously mapped
                        using Svc_MapSyshub()

    Return value: BL_OK or error code
*/
__svc(SVC_UNMAP_SYSHUB) unsigned int Svc_UnmapSysHub( void* pAxiAddress );


/*-----------------------------------------------------------------------------
    Read 32-bit value from SYSHUB address.

    Parameters:
        SyshubAddressLo -   low order 32 bit of address in SYSHUB address space
        SyshubAddressHi -   high order 32 bit of address in SYSHUB address space
        pValue          -   location for the value to be written
        Size            -   size of the value in bytes; valid values: 1, 2 and 4

    Return value: BL_OK or error code
*/
__svc(SVC_READ_SYSHUB) unsigned int Svc_ReadSysHub( unsigned int    SyshubAddressLo,
                                                    unsigned int    SyshubAddressHi,
                                                    unsigned int*   pValue,
                                                    unsigned int    Size );

/*-----------------------------------------------------------------------------
    Write 32-bit value to SYSHUB address.

    Parameters:
        SyshubAddressLo -   low order 32 bit of address in SYSHUB address space
        SyshubAddressHi -   high order 32 bit of address in SYSHUB address space
        Value           -   value to be written
        Size            -   size of the value in bytes; valid values: 1, 2 and 4

    Return value: BL_OK or error code
*/
__svc(SVC_WRITE_SYSHUB) unsigned int Svc_WriteSysHub(   unsigned int SyshubAddressLo,
                                                        unsigned int SyshubAddressHi,
                                                        unsigned int Value,
                                                        unsigned int Size );

/*-----------------------------------------------------------------------------
    Calculate SHA256

    Parameters:
        pData           -   Address of the data to be hashed
        DataLen         -   Length of data to be hashed
        pHash           -   Hashed ouput

    Return value: BL_OK or error code
*/
__svc(SVC_SHA256) unsigned int Svc_SHA256(   char *         pData,
                                             unsigned int   DataLen,
                                             char *         pHash );

/*-----------------------------------------------------------------------------
    Calculate ModEx

    Parameters:
        pModExParams           -   ModExp parameters

    Return value: BL_OK or error code
*/
__svc(SVC_MODEXP) unsigned int Svc_MODEXP( MOD_EXP_PARAMS *pModExParams );

/*-----------------------------------------------------------------------------
    RSA PSS Verification of signature and data

    Parameters:
        RSAPSS_VERIFY_PARAMS           -   Pointer to RSA PSS parameters

    Return value: BL_OK or error code
*/
__svc(SVC_RSAPSS_VERIFY) unsigned int Svc_RSAPSSVerify( RSAPSS_VERIFY_PARAMS *pRSAPSSParams );

/*-----------------------------------------------------------------------------
    AES ECB Encrypt

    Parameters:
        AES_ECB_ENCRYPT_PARAMS           -   AES ECB Encrypt parameters

    Return value: BL_OK or error code
*/
__svc(SVC_AES_ECB_ENCRYPT) unsigned int Svc_AesEcbEncrypt( AES_ECB_ENCRYPT_PARAMS *pAesEcbEncryptParam );

/*-----------------------------------------------------------------------------
    Compute SHA256 hash of OTP Key slot 0

    Parameters:
        pHash           -   Hash output

    Return value: BL_OK or error code
*/
__svc(SVC_SHA256_OTP) unsigned int Svc_Sha256OTP( char *pHash );

/*-----------------------------------------------------------------------------
    Get MCM configuration info (number of dies/sockets etc.).

    Parameters:
        pMcmInfo    -   output buffer

    Return value: BL_OK or error code
*/
__svc(SVC_GET_MCM_INFO) unsigned int Svc_GetMcmInfo( void* pMcmInfo );

/*-----------------------------------------------------------------------------
    Set MasterStatusBit value in MP0_C2P_MSG_40 register on master die.

    This can only be called on master die.

    Note: MasterStatusBit should be one of the bits within XXX_MASTER_STATUS_BITS
          value defined for the specific client, i.e. AGESA_MASTER_STATUS_BITS.

    Parameters:
        ClientId        -   client ID
        MasterStatusBit -   which bit of the MasterStatus register to set

    Return value: BL_OK or error code
*/
__svc(SVC_SET_MASTER_STATUS) unsigned int Svc_McmSetMasterStatus( unsigned int ClientId, unsigned int MasterStatusBit );

/*-----------------------------------------------------------------------------
    Wait for Boot Loader on master die to set specific bit in the MasterStatus
    register.

    This can only be called on slave dies.

    Note: MasterStatusBit should be one of the bits within XXX_MASTER_STATUS_BITS
          value defined for the specific client, i.e. AGESA_MASTER_STATUS_BITS.

    Parameters:
        ClientId        -   client ID
        MasterStatusBit -   which bit of the MasterStatus register to wait for

    Return value: BL_OK or error code
*/
__svc(SVC_WAIT_FOR_MASTER_STATUS) unsigned int Svc_McmWaitForMasterStatus( unsigned int ClientId, unsigned int MasterStatusBit );

/*-----------------------------------------------------------------------------
    Broadcast data from global master to all slaves. Broadcast happens through
    8 32-bit registers, so input data is array of 32-bit values.

    This can only be called on master die.

    Parameters:
        ClientId        -   client ID
        MasterStatusBit -   master status to be set when broadcast data is ready
        pData           -   input data (array of 32-bit values)
        Num             -   number of 32-bit elements in the array; must not be 0

    Return value: BL_OK or error code
*/
__svc(SVC_MASTER_BROACAST) unsigned int Svc_McmBroadcastDataToSlaves(   unsigned int    ClientId,
                                                                        unsigned int    MasterStatusBit,
                                                                        unsigned int*   pData,
                                                                        unsigned int    Num );

/*-----------------------------------------------------------------------------
    Slave reads broadcast configuration data from master. Broadcast happens
    through 8 32-bit registers, so output data is array of 32-bit values.

    This can only be called on slave dies.

    Parameters:
        ClientId        -   client ID
        MasterStatusBit -   master status for slaves to wait before reading the data
        pOut            -   output data (array of 32-bit values); can be NULL if this
                            particular slave does not want to read any data (it still
                            has to acknowledge the read to master)
        Num             -   number of 32-bit elements in the array

    Return value: BL_OK or error code
*/
__svc(SVC_SLAVE_GET_BROACAST_DATA) unsigned int Svc_McmGetBroadcastDataFromMaster(
                                                                        unsigned int    ClientId,
                                                                        unsigned int    MasterStatusBit,
                                                                        unsigned int*   pOut,
                                                                        unsigned int    Num );

/*-----------------------------------------------------------------------------
    Save S3 data blob

    Parameters:
        pS3Data             -   Input S3 data blob
        S3DataSize          -   Size

    Return value: BL_OK or error code
*/
__svc(SVC_SAVE_APOB_DATA) unsigned int Svc_SaveApobData(void *pApobData, unsigned int ApobDataSize);

//-----------------------------------------------------------------------------
// Description      : Reads BIOS Directory into global buffer, and searches the directory for an entry
//
// Parameters       :
//
// Return Values    : BL_OK or error code
//
//-----------------------------------------------------------------------------
__svc(SVC_SEARCH_BIOS_DIR) uint32_t SVC_BIOSDirectorySearch(BIOS_DIR_SEARCH_PARMS* pParms);

//-----------------------------------------------------------------------------
// Description      : Reads BIOS Directory into global buffer, and searches the directory for an entry
//                  : Version 2 and will be used to replace SVC_SEARCH_BIOS_DIR
//
// Parameters       :
//
// Return Values    : BL_OK or error code
//
//-----------------------------------------------------------------------------
__svc(SVC_SEARCH_BIOS_DIR_V2) uint32_t SVC_BIOSDirectorySearchV2(BIOS_DIR_SEARCH_PARMS_V2* pParms);

/*-----------------------------------------------------------------------------
    Get data from one or more slave dies

    Parameters:
        ClientId         - Client Id
        pData             - Input/output pointer to place returned data
        pDataSize       - Input/output pointer to place return data block size (max 32Bytes)
        pSlaveId         - Input/output pointer to place returning ID of slave

    Return value: BL_OK, BL_ERR_MORE_DATA, or a BL error
*/
__svc(SVC_GET_DATA_FROM_SLAVES) uint32_t Svc_GetDataFromSlaves(uint32_t ClientId, uint32_t* pData,
                                                               uint32_t* pDataSize, uint32_t* pSlaveId );

/*-----------------------------------------------------------------------------
    Send data from slave to the local master

    Parameters:
        ClientId        - Client Id 
        pData           - Input pointer containing data to send (max 32Bytes)
        DataSize       - Input integer containing number of 32bit DWORDs to send
        Eod             - Input integer containing EoD signal when done sending blocks (0 or 1)

    Return value: BL_OK, or another BL error
*/
__svc(SVC_SEND_DATA_TO_MASTER) uint32_t Svc_SendDataToMaster(uint32_t ClientId, uint32_t* pData,
                                                             uint32_t DataSize, uint32_t Eod );

/*-----------------------------------------------------------------------------
    Waits in a blocking call for multiples of 10ns (100MHz timer) before returning

    Parameters:
        Multiple        - The number of multiples of 10ns to wait

    Return value: BL_OK, or BL_ERR_TIMER_PARAM_OVERFLOW
*/
__svc(SVC_WAIT_10NS_MULTIPLE) uint32_t Svc_Wait10nsMultiple(uint32_t Multiple);


//-----------------------------------------------------------------------------
//
// Description      :   Returns the current boot mode from the type PSP_BOOT_MODE found in
//                      bl_public.h.
//
// Inputs           :   pBootMode - Output parameter passed in R0
//
// Outputs          :   The boot mode in pBootMode.
//                      See Return Values.
// 
// Return Values    :   BL_OK
//                      BL_ERR_NULL_PTR
//                      Other BL_ERRORs lofted up from called functions
//
//-----------------------------------------------------------------------------
__svc(SVC_GET_BOOT_MODE) uint32_t Svc_GetBootMode(uint32_t *pBootMode);

//-----------------------------------------------------------------------------
//
// Description      :   Returns the parameter for debug unlock information 
//                      bl_public.h.
//
// Inputs           :   pData  - Address point to DebugUnlockInfo Structure.
//                      pKdsPubKey - a pointer to copy the KDS public key to
//                      KeyLen - the length of the key in bytes
//
// Outputs          :   NULL 
// 
// Return Values    :   BL_OK 
//                      Other BL_ERRORs lofted up from called functions
//
//-----------------------------------------------------------------------------
__svc(SVC_GET_DEBUG_UNLOCK_INFO) uint32_t Svc_GetDebugUnlockInfo(void *pData, void* pKdsPubKey, uint32_t KeyLen);

//-----------------------------------------------------------------------------
//
// Description      :   Send the request to slaves to perform the unlock with the provided information,
//                      while saving it back to BL gUnlockInfo structure
//
// Inputs           :   pData  - Address point to DebugUnlockInfo Structure.
//
// Outputs          :   NULL
//
// Return Values    :   BL_OK
//                      Other BL_ERRORs lofted up from called functions
//
//-----------------------------------------------------------------------------
__svc(SVC_SLAVE_UNLOCK_REQUEST) uint32_t Svc_SlaveUnlockRequest( void *pData);


//-----------------------------------------------------------------------------
//
// Description      :   Communicate the debug unlock information back to BL  
//                      bl_public.h.
//
// Inputs           :   pData  - Address point to DebugUnlockInfo Structure.
//
// Outputs          :   NULL 
// 
// Return Values    :   BL_OK 
//                      Other BL_ERRORs lofted up from called functions
//
//-----------------------------------------------------------------------------
__svc(SVC_SET_DEBUG_UNLOCK_INFO) uint32_t Svc_SetDebugUnlockInfo(void *pData);

// Description      : Each die should call this SVC call to PSP boot loader to sign 
//                      S3 data for each die. The master should call Svc_SaveAPOBData() 
//                      once each PSP die completed the signing of the HMAC data
//
// Parameters       : pHmac     [out] - Location in SRAM to copy HMAC to
//                    DataSize  [in]  - Size of data to HMAC
//                    pS3Data   [in]  - Data to HMAC
//
// Return values    : BL_OK or error code
//-----------------------------------------------------------------------------
__svc(SVC_OTP_HMAC256_SIGN) uint32_t Svc_OTPHmac256Sign (uint8_t *pHmac, uint32_t DataSize, uint8_t *pS3Data);

//-----------------------------------------------------------------------------
// Description      : Validates HMAC and loads S3 data. Each die should call 
//                      this during S3 resume to get the APOB data
//
// Parameters       : DataApobOffset [in]  - S3 DataInfo offset from APOB entry 0x63
//                    pDestAddr      [out] - SRAM location to be copied
//                    DataSize       [in]  - S3 DataSize in bytes to read
//                    HmacApobOffset [in]  - SpiOffset from APOB entry where HMAC is stored
//                                          Will read 32 bytes from offset value provided
//
// Return Values    : BL_OK or error code
//
//----------------------------------------------------------------------------
__svc(SVC_SPILOAD_VALIDATE_HMAC256_APOB) uint32_t Svc_LoadValidateAPOBHmac256(uint32_t DataApobOffset, uint8_t *pDestAddr, uint32_t DataSize, uint32_t HmacApobOffset);

//-----------------------------------------------------------------------------
//
// Description      :   Programs UMC keys -- generating them on S5, and restoring them from DRAM for S3.
//                      UMC keys must be shared between dies on S5 using DRAM as a shared mailbox,
//                      and restored from DRAM on S3.
//                      Therefore DRAM MUST be trained and PSP should be able to access PSP Secure Memory
//                      before AGESA calls Svc_ProgramUmcKeys().
//
// Inputs           :   Flags bitfields:
//                          Data Encryption Enable      (1 << 0)
//                          Force Encryption Enable     (1 << 1)
//                          Data Scramble Enable        (1 << 2)
//                          UMC Key 0 in Reset State    (1 << 3)
//                      AddrTweakEn - Bitmask to enable address-tweak.
//
// Outputs          :   See Return Values.
// 
// Return Values    :   BL_OK
//
//-----------------------------------------------------------------------------
__svc(SVC_PROGRAM_UMC_KEYS) uint32_t Svc_ProgramUmcKeys(uint32_t Flags, uint16_t AddrTweakEn);

/*-----------------------------------------------------------------------------
    Reads a byte from the slave specified with the command provided over SMBus

    Parameters:
        SlaveAddr[in]        - The 7bit slave address shifted left by 1bit (x2)
        Command[in]            - The 8bit device specific command
        pByteRead[out]        - A pointer to a char to hold the byte read

    Return value: BL_OK, or a BL_ERROR code
*/
__svc(SVC_READ_SMBUS_BYTE) uint32_t Svc_ReadSmbusByte(char SlaveAddr, char Command, char* pByteRead);

/*-----------------------------------------------------------------------------
    Writes a byte to the slave specified with the command provided over SMBus

    Parameters:
        SlaveAddr[in]        - The 7bit slave address shifted left by 1bit (x2)
        Command[in]            - The 8bit device specific command
        ByteRead[in]        - A byte to write to the specified address

    Return value: BL_OK, or a BL_ERROR code
*/
__svc(SVC_WRITE_SMBUS_BYTE) uint32_t Svc_WriteSmbusByte(char SlaveAddr, char Command, char ByteWrite);

/*-----------------------------------------------------------------------------
    For MCM master - broadcasts the unlock info information. For slaves - receives it

    Parameters:
        pUnlockInfo - a pointer to the DebugUnlockInfo structure

    Return value: BL_OK, or a BL_ERROR code
*/
__svc(SVC_SYNC_UNLOCK_INFO) uint32_t Svc_SyncUnlockInfo(void* pUnlockInfo);

/*-----------------------------------------------------------------------------
    For MCM master - gathering the 32 bit information from each slave and storing in the array pointed with `data`
    For MCM slaves - sending the 32-bit data pointed by `data` to the master

    Return value: BL_OK, or a BL_ERROR code
*/
__svc(SVC_MCM_SYNC_ON_DATA) uint32_t Svc_McmSyncOnData(uint32_t* data);


/*-----------------------------------------------------------------------------
    Map 64-bit SYSHUB target address for access via 32-bit AXI address  (Extended functionality).

    Parameters:
        SyshubAddressLo -   low order 32 bit of address in SYSHUB address space
        SyshubAddressHi -   high order 32 bit of address in SYSHUB address space
        TargetType - type of SYSHUB target
        

    Return value:
        on success  -   mapped address in AXI space
        on error    -   NULL
*/
__svc(SVC_MAP_SYSHUB_EX) void* Svc_MapSysHubEx(uint32_t SyshubAddressLo,
                                               uint32_t SyshubAddressHi,
                                               SYSHUB_TARGET_TYPE TargetType);

/*-----------------------------------------------------------------------------
    Read 32-bit value from SYSHUB address (Extended functionality).

    Parameters:
        SyshubAddressLo -   low order 32 bit of address in SYSHUB address space
        SyshubAddressHi -   high order 32 bit of address in SYSHUB address space
        pValue          -   destination pointer
        Size            -   size of read value in bytes; valid values: 1, 2 and 4
        TargetType - type of SYSHUB target

    Return value: BL_OK or error code
*/
__svc(SVC_READ_SYSHUB_EX) unsigned int Svc_ReadSysHubEx(SYSHUB_RW_PARMS_EX* pParms);

/*-----------------------------------------------------------------------------
    Write 32-bit value to SYSHUB address (Extended functionality).

    Parameters:
        SyshubAddressLo -   low order 32 bit of address in SYSHUB address space
        SyshubAddressHi -   high order 32 bit of address in SYSHUB address space
        pValue           -   source pointer
        Size            -   size of source value in bytes; valid values: 1, 2 and 4
        TargetType - type of SYSHUB target

    Return value: BL_OK or error code
*/
__svc(SVC_WRITE_SYSHUB_EX) unsigned int Svc_WriteSysHubEx(SYSHUB_RW_PARMS_EX* pParms);


/*-----------------------------------------------------------------------------
    Send an SMU/SMC message from PSP to SMU, and block until a response is received.

    Parameters:
        MsgId         - SMU2PSP message id to send (no error checking is done on validity)
        MsgArg         - DWORD containing message specific payload/arguments
        pMsgResp        - pointer to store response read/returned from SMU

    Return value: BL_OK or error code
*/
__svc(SVC_SEND_PSP_SMU_MSG) unsigned int Svc_SendPspSmuMsg(uint32_t MsgId, uint32_t MsgArg, uint32_t* pMsgResp);

/*-----------------------------------------------------------------------------
    Synchronizes master and slaves at a "barrier" point.

    Parameters:
        SyncPointFlag     - This flag must be used only once in a given boot sequence, and be unique from all
                            other flags. It is a bitmask of all of the flags slaves are expecting

    Return value: SyncPointFlag for master and the actual received status for the slaves
*/
__svc(SVC_MCM_SYNCHRONIZATION_POINT) uint32_t Svc_McmSynchronizationPoint(uint32_t SyncPointFlag);

//Remain here for compatibility with ABL calling convention.  The actual address is fixed inside PSP BL to avoid vulnerabilities exploitable by attacker
//Later to be removed completely together with ABL caller function.  Using dGPU memory as system memory was early ZP bringup timeframe, no such need now.
__svc(SVC_SET_PSP_SMU_RESERVED) uint32_t Svc_SetPspSmuReservedAddrs(uint32_t PspSecurePhysAddrLo,
                                                                    uint32_t PspSecurePhysAddrHi,
                                                                    uint32_t SmuReservedPhysAddrLo,
                                                                    uint32_t SmuReservedPhysAddrHi);

__svc(SVC_GMI_NON_FUNCTIONAL) uint32_t Svc_GmiNonFunctional(void);

/*-----------------------------------------------------------------------------
    Load a binary from the BIOS directory table by instance type. The binary should be signed, and can be
    compressed.

    Parameters:
        BiosDirType     - From entry header in BIOS directory table.
        pDest           - Pointer to where the binary should be loaded to.
        pDestSizeBytes  - Input/Output parameter: on input, max size. On output, size of binary loaded.
        InstanceType    - From entry header in BIOS directory table. An entry matching both BiosDirType and
                          InstanceType must be found in the BIOS directory table to load the bin.

    Return value: BL_OK or error code
*/
__svc(SVC_LOAD_FW_IMAGE_BY_INSTANCE) uint32_t
Svc_LoadBinaryByInstance(BIOS_DIRECTORY_ENTRY_TYPE_E    BiosDirType,
                         void                           *pDest,
                         uint32_t                       *pDestSizeBytes,
                         uint32_t                       InstanceType);




/*-----------------------------------------------------------------------------
 *  Load a binary from the BIOS directory table by its attributes word.
 *  The binary should be signed unless it is of the excepted types, and can be
 *  compressed.
 *
 *  Parameters:
 *      AttribWord      - is the 32-bit long bit-coded attributes word
 *      AttribMask      - is the mask with 1s in the places corresponding to the attributes to be searched
 *      pDest           - Pointer to where the binary should be loaded to.
 *      pDestSizeBytes  - Input/Output parameter: on input, max size. On output, size of binary loaded.
 *
 *  Return value: BL_OK or error code
 *                                                     */
__svc(SVC_LOAD_BINARY_BY_ATTRIB)    uint32_t
Svc_LoadBinaryByAttrib(uint32_t AttribWord,
                       uint32_t AttribMask,
                       void     *pDest,
                       uint32_t *pDestSizeBytes);

/*-----------------------------------------------------------------------------
    P-256 only and expects message pre-hashed, due to mbedTLS use-case.

    Parameters:
        pIsSigVerified  - Pointer to bool -- true if signature is valid, false if not
        pPublicPointQ   - Pointer to public point Q on P-256 curve. Should be in format X || Y, where || is
                          concatenation, and X and Y are in little endian.
        pMsgHash        - Pointer to H(m) (see ECDSA spec).
        pSignature      - Pointer to signature in format r || s, where r and s are in little endian.

*/
__svc(SVC_ECDSA_VERIFY) uint32_t
Svc_EcdsaVerify(bool *pIsSigVerified, void *pPublicPointQ, uint8_t *pMsgHash, void *pSignature);

/*-----------------------------------------------------------------------------
    P-256 only and expects message pre-hashed, due to mbedTLS use-case.

    Parameters:
        pEcdsaSig   - Pointer to signature, which will be output in format r || s, where r and s are in little
                      endian.
        pPrivate_d  - Pointer to signing key's private scalar d, in little endian.
        pMsgHash    - Pointer to H(m) (see ECDSA spec).

*/
__svc(SVC_ECDSA_SIGN) uint32_t
Svc_EcdsaSign(void *pEcdsaSig, void *pPrivate_d, uint8_t *pMsgHash);

/*-----------------------------------------------------------------------------
    Programs GMI and xGMI keys, according to parameters, and enables encryption.
    Three out of six CAKEs on each die are programmed for GMI, and one CAKE on each die is programmed for
    xGMI.

    Parameters:
        IsGmiEncrypted - True -> Ciphertext GMI transactions, False -> Plaintext GMI transactions
        IsXGmiEncrypted - True -> Ciphertext xGMI transactions, False -> Plaintext xGMI transactions

*/
__svc(SVC_GMI_NONCE_KEY_PROGRAM) uint32_t
Svc_GmiXGmiLinkKeyProgram(bool IsGmiEncrypted, bool IsXGmiEncrypted);

/*-----------------------------------------------------------------------------
    SEV master die send command to slave die, and wait until response.

    Parameters:
        targetDie == 0, the command is sent to each die and wait until all responded.
        targetDie != 0, the command is sent to specific die and wait until response. 
*/
__svc(SVC_SEV_MASTER_TO_SLAVE) uint32_t
Svc_SevMasterToSlave(uint32_t targetDie, void *pCmdBuf, uint32_t bufSize);

/*-----------------------------------------------------------------------------
   Functions to access SEV persistent data which is saved to non-volatile storage in SPI-ROM. 

   This interface provide a thin and simple layer implementation for SEV to save/retrieve its persistent data,
   - the confidentiality and integrity of the data is handled by SEV app itself. 
   - the management of the data is also handled by SEV app itself. 

 */
__svc(SVC_SEV_PERSISTENT_WRITE) uint32_t
Svc_SevPersistentWrite(void *pBuf, uint32_t InputSize);

__svc(SVC_SEV_PERSISTENT_READ) uint32_t
Svc_SevPersistentRead(void *pBuf, uint32_t bufSize);

__svc(SVC_SEV_PERSISTENT_ERASE) uint32_t
Svc_SevPersistentErase(uint32_t NumOfBlocks);

/*-----------------------------------------------------------------------------
   Leverage the Implemention in SVC code for the KDF in Counter Mode defined in section 5.1 of NIST
   SP 800-108.
   
 */
__svc(SVC_SEV_KEY_DERIVE) uint32_t
Svc_SevKeyDerive(void* pParams);

/*-----------------------------------------------------------------------------
   Function to do generic AES opeartion
   
 */
__svc(SVC_AES_GENERIC) uint32_t
Svc_AesGeneric(void* pParams);

/*-----------------------------------------------------------------------------
   Function to do cache opeartion
   
 */
__svc(SVC_CACHE_OPERATION) uint32_t
Svc_CacheOperation(uint32_t Operation, uint32_t CacheType, uint32_t VirtAddr, uint32_t Size);

/*-----------------------------------------------------------------------------
   Function to do generic SHA-256 opeartion
   
 */
__svc(SVC_SHA256_GENERIC) uint32_t
Svc_Sha256Generic(void* pParams);

/*-----------------------------------------------------------------------------
   Function to generate random number
   
   pOut        -  Destination pointer to copy random data
   Size        -  Size of Random number desired in Bytes
 */
__svc(SVC_TRNG) uint32_t
Svc_Trng(uint8_t* pOut, uint32_t Size);

/*-----------------------------------------------------------------------------
   Function to do ECC primitive operation
   
 */
__svc(SVC_ECC_PRIMITIVE) uint32_t
Svc_EccPrimitive(void* pParams);

/*-----------------------------------------------------------------------------
   Function to retrieve the chip-unique ECC key from the LSB

 */
__svc(SVC_GET_CUK) BL_RETCODE
Svc_GetCUK(uint8_t *buffer, size_t *size);

/*-----------------------------------------------------------------------------
   Function to retrieve the requested mode for security gasket function
 */
__svc(SVC_GET_SECURE_GASKET_MODE) BL_RETCODE
Svc_GetSecureGasketMode(SECURE_GASKET_MODE *pMode);

/*-----------------------------------------------------------------------------
   Function to inflate data from local SRAM to DRAM using CCP ZLib

 */
__svc(SVC_CCP_INFLATE_OUT) BL_RETCODE
Svc_CcpInflateOut(uint32_t x86_addr_lo, uint32_t x86_addr_hi, uint32_t psp_addr, size_t size);

/*-----------------------------------------------------------------------------
   Retrieve the base address and length of the SMM region

 */
__svc(SVC_GET_SMM_RANGE) void
Svc_GetSmmRange(uint64_t *base, uint64_t *length);

/*-----------------------------------------------------------------------------
   This to be called by ABL in order to set the WAFL threshold parameters
   Fclk is a uint32_t and represents a frequency in MHz.
   PerfBound is a uint32_t and represents an acceptable percent of performance loss in units of 0.00001%.  A value of 0 means CRC disabled.

 */
__svc(SVC_SET_WAFL_THRESHOLD_PARAMS) void
Svc_SetWaflThresholdParams(uint32_t Fclk, uint32_t PerfBound);

/*-----------------------------------------------------------------------------
   This to be called by ABL in order to set the Twix threshold parameters
   Fclk is a uint32_t and represents a frequency in MHz.
   PerfBound is a uint32_t and represents an acceptable percent of performance loss in units of 0.00001%.  A value of 0 means CRC disabled.

 */
__svc(SVC_SET_TWIX_THRESHOLD_PARAMS) void
Svc_SetTwixThresholdParams(uint32_t Fclk, uint32_t PerfBound);

/* This should be called by ABL to set the MIN_SEV_ASID value*/
__svc(SVC_SET_MIN_SEV_ASID) void
Svc_SetMinSevAsid(uint32_t MinSevAsid);

/*
 * This should be called by SEV to get the MIN_SEV_ASID value.
 * Will return 0xFFFFFFFF if no Svc_SetMinSevAsid was called previously
 */
__svc(SVC_GET_MIN_SEV_ASID) uint32_t
Svc_GetMinSevAsid(void);

/*
 * This should be called by SEV to get address of the reserved DRAM region
 * The caller would pass the size of the requested region (currently used only for sanity check)
 * Will return NULL on failure
 */
__svc(SVC_GET_SEV_RESERVED_DRAM) void*
Svc_GetSevReservedDram(uint32_t Size);

/*
 * DebugMode = 
 *              0 - Release mode (CF9 Reset)
 *              1 - Full Debug mode.
 *
 */
__svc(SVC_SET_PSP_DEBUG_MODE) uint32_t 
Svc_SetPSPDebugMode(uint32_t DebugMode);

/*
* This should be called in order to set SYSHUB watchdog timer timeout configuration. 
* Parameters:
* nbioInstId = NBIO instance to which this interval should be applied. (There are total 4 NBIO instances in SSP)
*              Pass 0xFFFF_FFFF to set all available instances of NBIO with the specified interval configuration.
* msec       = Interval time for timeout in msec. 
*              Minimum timer value = 1ms. Max timer value =85850 msec.
*              set 0 msec = To disable the timer. This will reset the SYSHUB MP error detection register 
* 
*  Return value: BL_OK or error code 
*/
__svc(SVC_SET_SYSHUB_WDTTIMER_INTERVAL) BL_RETCODE 
Svc_SetSysHubWdtTimerInterval(unsigned int nbioInstId, unsigned int msec);

/*
 * Copy no more than 'size' bytes of the fused hash of the AMD root key to
 * 'hash'.
 *
 * Returns BL_OK on success or BL_ERR_INVALID_PARAMETER on failure.
 */
__svc(SVC_GET_ROOT_KEY_HASH) BL_RETCODE
Svc_GetRootKeyHash(uint8_t *hash, size_t size);

/*
 * Service call used by ABL to get the secure state
 */
__svc(SVC_GET_SECURE_DEBUG_STATUS) uint32_t
Svc_GetSecureDebugUnlockStatus(void);

//-----------------------------------------------------------------------------
//
// Description      :   Remaps the MBAT entry, by resetting it to NULL entry or
//                      by setting it to default value as per PPR document
//
// Inputs           :   MbatIndexNum  - Index number of MBAT entry, as per PPR document
//                      Set - 0 : To reset (Entry will be deleted, means set to NULL value)
//                            1 : To Set (Entry will be updated with default value from PPR)
//
// Outputs          :   NULL 
// 
// Return Values    :   BL_OK 
//                      Other BL_ERRORs lofted up from called functions
//
//-----------------------------------------------------------------------------
__svc(SVC_REMAP_MBAT_ENTRY) uint32_t Svc_RemapMbatEntry(uint32_t MbatIndexNum, uint32_t Set);


//-----------------------------------------------------------------------------
//
// Description      :   Sets the 8T/16T encryption mode from the type SEV_MODE
//                      sev.h.
//
// Inputs           :   SevMode - Input parameter passed in R0
//
// Outputs          :   See Return Values.
// 
// Return Values    :   BL_OK
//                      BL_ERR_INVALID_PARAMETER
//                      Other BL_ERRORs lofted up from called functions
//
//-----------------------------------------------------------------------------
__svc(SVC_SET_8T_16T_MODE) BL_RETCODE Svc_Set8T16TMode(uint32_t SevMode);

//-----------------------------------------------------------------------------
//
// Description      :   Returns the current 8T/16T encryption mode from the type SEV_MODE found in
//                      sev.h.
//
// Inputs           :   pSevMode - Output parameter passed in R0
//
// Outputs          :   The Sev mode in pSevMode.
//                      See Return Values.
// 
// Return Values    :   
//
//-----------------------------------------------------------------------------
__svc(SVC_GET_8T_16T_MODE) BL_RETCODE Svc_Get8T16TMode(uint32_t *pSevMode);

/*-----------------------------------------------------------------------------
 * Load FW Sub Type from SPIROM into memory
 *
 * Parameters:
 *   PspDirType  -   type of PSP directory entry to load from
 *   FWSubType   -   Sub Type to be loaded in memory
 *   pDest       -   memory address to load data to
 *   pDestSize   -   on input - max pDest size, on output - actual loaded size
 *
 * Return value: BL_OK or error code
 *                                             */
__svc(SVC_LOAD_BINARY_FROM_SUBTYPE) unsigned int
Svc_LoadBinaryFromSubtype( BIOS_DIRECTORY_ENTRY_TYPE_E PspDirType,
                           unsigned int                FWSubType,
                           void*                       pDest,
                           unsigned int*               pDestSize );

/*
* Generic SHA call for SHA, SHA_OTP, SHA_HMAC
*/
__svc(SVC_SHA) BL_RETCODE Svc_SHA(SHA_OPERATION *pSHAOp, SHA_OPERATION_MODE SHAMode);

//-----------------------------------------------------------------------------
//
// Description      :   Returns the PSP BL version
//
// Inputs           :   None
//
// Outputs          :   pPspVersion - Version of the PSP BL
//                               
//
// Return Values    :   BL_OK                        - The command is completed successfully
//
//-----------------------------------------------------------------------------
__svc(SVC_GET_PSP_VERSION) BL_RETCODE Svc_GetPspVersion(uint32_t* pPspVersion);

//-----------------------------------------------------------------------------
//
// Description      :   Sets the Bixby Bus Device and Function number
//
// Parameters       :
//    BusNum                   - BixBy Bus Number (one of 0x0, 0x20, 0x40, 0x60)
//    DevNum                   - BixBy Device Number (one of 1, 2, 3 or 4)
//    FuncNum                  - BixBy Function Number (one of 1, 2, 3, 4, 5, 6, 7)
//
// Outputs          :   See Return Values
//
// Return Values    :
//    BL_OK                    - Command Successfully
//    BL_ERR_INVALID_PARAMETER - Command Failure
//
//-----------------------------------------------------------------------------
__svc(SVC_SET_BIXBY_DEVICE_INFO) BL_RETCODE Svc_SetBixbyInfo(uint32_t BusNum,
                                                             uint32_t DevNum,
                                                             uint32_t FuncNum);

//-----------------------------------------------------------------------------
//
// Description      :   Reads the harvest fuse ram bit sequence
//
// Inputs           :   StartBit - the bit number in the fuse RAM. Should be multiple of 32
//                      NumBits  - total number of bits to read. will be rounded up to 32-bit boundary.
//
// Outputs          :   pOutBuff - Pointer to buffer that stores fuse bits information
//
//
// Return Values    :   BL_OK                        - The command is completed successfully
//                      BL_ERR_INVALID_PARAMETER     - The input parameters StartBit/Numbits is/are incorrect
//
//-----------------------------------------------------------------------------
__svc(SVC_READ_HARVEST_FUSE) BL_RETCODE Svc_ReadHarvestFuseBits(uint32_t *pOutBuff, uint32_t StartBit, uint32_t NumBits);

#endif /* BL_SYSCALL_H_ */
