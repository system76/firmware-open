## @file
#  Platform description for DynamicEx PCDs, defined in FSP Package
#  and shared with Board Package.
#
#  @copyright
#  INTEL CONFIDENTIAL
#  Copyright (C) 2018 Intel Corporation.
#
#  This software and the related documents are Intel copyrighted materials,
#  and your use of them is governed by the express license under which they
#  were provided to you ("License"). Unless the License provides otherwise,
#  you may not use, modify, copy, publish, distribute, disclose or transmit
#  this software or the related documents without Intel's prior written
#  permission.
#
#  This software and the related documents are provided as is, with no
#  express or implied warranties, other than those that are expressly stated
#  in the License.
#
# @par Specification
##

[PcdsDynamicExDefault]

  ## Specifies max supported number of Logical Processors.
  # @Prompt Configure max supported number of Logical Processorss
  gUefiCpuPkgTokenSpaceGuid.PcdCpuMaxLogicalProcessorNumber|16

  gSiPkgTokenSpaceGuid.PcdSiPciExpressBaseAddress|0xE0000000
  gSiPkgTokenSpaceGuid.PcdPciExpressRegionLength|0x10000000

  ## Specifies the base address of the first microcode Patch in the microcode Region.
  # @Prompt Microcode Region base address.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuMicrocodePatchAddress|0x0

  ## Specifies the size of the microcode Region.
  # @Prompt Microcode Region size.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuMicrocodePatchRegionSize|0x0

  ## Specifies the AP wait loop state during POST phase.
  #  The value is defined as below.
  #  1: Place AP in the Hlt-Loop state.
  #  2: Place AP in the Mwait-Loop state.
  #  3: Place AP in the Run-Loop state.
  # @Prompt The AP wait loop state.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuApLoopMode|2

  ## Specifies the AP target C-state for Mwait during POST phase.
  #  The default value 0 means C1 state.
  #  The value is defined as below.<BR><BR>
  # @Prompt The specified AP target C-state for Mwait.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuApTargetCstate|0

  #
  # Enable ACPI S3 support in FSP by default
  #
  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiS3Enable|1

  ## Contains the pointer to a CPU S3 data buffer of structure ACPI_CPU_DATA.
  # @Prompt The pointer to a CPU S3 data buffer.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuS3DataAddress|0x00

  ## As input, specifies user's desired settings for enabling/disabling processor features.
  ## As output, specifies actual settings for processor features, each bit corresponding to a specific feature.
  # @Prompt As input, specifies user's desired processor feature settings. As output, specifies actual processor feature settings.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuFeaturesSetting|{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

  ## Contains the size of memory required when CPU processor trace is enabled.<BR><BR>
  #  Processor trace is enabled through set BIT44(CPU_FEATURE_PROC_TRACE) in PcdCpuFeaturesSetting.<BR><BR>
  # @Prompt The memory size used for processor trace if processor trace is enabled.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuProcTraceMemSize|0x0

  ## Contains the processor trace output scheme when CPU processor trace is enabled.<BR><BR>
  #  Processor trace is enabled through set BIT44(CPU_FEATURE_PROC_TRACE) in PcdCpuFeaturesSetting.<BR><BR>
  # @Prompt The processor trace output scheme used when processor trace is enabled.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuProcTraceOutputScheme|0x0

  ## Indicates processor feature capabilities, each bit corresponding to a specific feature.
  # @Prompt Processor feature capabilities.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuFeaturesCapability|{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

  # Set SEV-ES defaults
  gEfiMdeModulePkgTokenSpaceGuid.PcdGhcbBase|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdGhcbSize|0
  gUefiCpuPkgTokenSpaceGuid.PcdSevEsIsEnabled|0

  ## This dynamic PCD hold an address to point to private data structure used in DxeS3BootScriptLib library
  #  instance which records the S3 boot script table start address, length, etc. To introduce this PCD is
  #  only for DxeS3BootScriptLib instance implementation purpose. The platform developer should make sure the
  #  default value is set to Zero. And the PCD is assumed ONLY to be accessed in DxeS3BootScriptLib Library.
  # @Prompt S3 Boot Script Table Private Data pointer.
  gEfiMdeModulePkgTokenSpaceGuid.PcdS3BootScriptTablePrivateDataPtr|0

  ## This dynamic PCD hold an address to point to private data structure SMM copy used in DxeS3BootScriptLib library
  #  instance which records the S3 boot script table start address, length, etc. To introduce this PCD is
  #  only for DxeS3BootScriptLib instance implementation purpose. The platform developer should make sure the
  #  default value is set to Zero. And the PCD is assumed ONLY to be accessed in DxeS3BootScriptLib Library.
  # @Prompt S3 Boot Script Table Private Smm Data pointer.
  # @ValidList  0x80000001 | 0x0
  gEfiMdeModulePkgTokenSpaceGuid.PcdS3BootScriptTablePrivateSmmDataPtr|0

  ## Indicates if the PCIe Resizable BAR Capability Supported or NOT.
  gEfiMdeModulePkgTokenSpaceGuid.PcdPcieResizableBarSupport|FALSE