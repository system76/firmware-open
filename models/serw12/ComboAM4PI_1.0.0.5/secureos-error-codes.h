// PSP prefix 0xEF for PSP Secure OS, avoids conflict with PSP BootLoader (which has 0xEE)
// FW_STATUS will have Bit #31 set which is used as indication that this value is written by Secure OS.

// Diagnostic messages.
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

#define DIAG_MSG_RWM_ACCESS_ERROR					0x5B

#define DIAG_MSG_PROM_BAD_SWITCH                    0x5C

#define DIAG_MSG_PROM_WRONG_ASIC_TYPE               0x5D