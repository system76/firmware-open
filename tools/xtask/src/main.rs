// SPDX-License-Identifier: GPL-3.0-only
// SPDX-FileCopyrightText: 2026 System76, Inc.

mod build;
mod cli;
mod flash;

use clap::Parser;
use cli::{Cli, Command};

pub const BUILD_DIR: &str = "build";

fn main() {
    let cli = Cli::parse();

    match &cli.command {
        Command::Build(args) => build::build(args),
        Command::Flash(args) => flash::stage_update(args),
    }
}
