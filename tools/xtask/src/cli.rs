// SPDX-License-Identifier: GPL-3.0-only
// SPDX-FileCopyrightText: 2026 System76, Inc.

use clap::{Args, Parser, Subcommand};

#[derive(Debug, Args)]
pub struct BuildArgs {
    pub model: String,
}

#[derive(clap::ValueEnum, Debug, Clone, Copy, PartialEq, Eq)]
pub enum FlashMethod {
    /// Flash internally using UEFI application
    Uefi,
    /// Flash externally using CH341A programmer
    Ch341a,
    /// Flash externally using a SPI-Pi setup
    SpiPi,
}

#[derive(Debug, Args)]
pub struct FlashArgs {
    pub model: String,
    #[clap(value_enum, default_value_t=FlashMethod::Uefi)]
    pub method: FlashMethod,
}

#[derive(Debug, Subcommand)]
pub enum Command {
    /// Build firmware for the target
    Build(BuildArgs),
    /// Flash firmware to the target
    Flash(FlashArgs),
}

#[derive(Debug, Parser)]
pub struct Cli {
    #[clap(subcommand)]
    pub command: Command,
}
