// SPDX-License-Identifier: GPL-3.0-only
// SPDX-FileCopyrightText: 2026 System76, Inc.

use crate::cli::BuildArgs;
use std::path::Path;
use std::process;
use std::io::{BufRead, BufReader};

const CFG_COMMENT_CHAR: char = '#';

fn build_edk2(model: &str) {
    let cores = std::thread::available_parallelism().unwrap().get();

    let config_file = Path::new("models").join(model).join("edk2.config");
    let configs = std::fs::read_to_string(config_file).unwrap();

    println!("edk2({})", model);
    for cfg in configs.lines() {
        if !cfg.starts_with(CFG_COMMENT_CHAR) {
            println!("  - {}", cfg);
        }
    }

    // Build BaseTools
    let child = process::Command::new("make")
        .env("PYTHON_COMMAND", "python3")
        .current_dir("edk2")
        .arg("--quiet")
        .arg("--directory")
        .arg("BaseTools")
        .arg(format!("--jobs={}", cores))
        .stdout(process::Stdio::piped())
        .spawn()
        .unwrap();
    let stdout = child.stdout.unwrap();
    let reader = BufReader::new(stdout);
    reader
        .lines()
        .map_while(Result::ok)
        .for_each(|line| println!("{}", line));

    let mut child = process::Command::new("bash")
        .env("PYTHON_COMMAND", "python3")
        .current_dir("edk2")
        .arg("-c")
        .arg(". edksetup.sh --reconfig")
        .spawn()
        .unwrap();
    let code = child.wait().unwrap();
    assert!(code.success());
    // XXX: No way to get env vars?

    // build -a IA32 -a X64 -b <BUILD_TYPE> -t <TOOLCHAIN> -p <PACKAGE> [args...]
    // cp UEFIPAYLOAD.fd
}

fn build_coreboot(model: &str) {
    let config_file = Path::new("models").join(model).join("coreboot.config");
    let configs = std::fs::read_to_string(config_file).unwrap();

    println!("coreboot({})", model);
    for cfg in configs.lines() {
        if !cfg.starts_with(CFG_COMMENT_CHAR) {
            println!("  - {}", cfg);
        }
    }
}

fn build_ec(model: &str) {
    let config_file = Path::new("models").join(model).join("ec.config");
    let configs = std::fs::read_to_string(config_file).unwrap();

    println!("ec({})", model);
    let mut args = vec![];
    for cfg in configs.lines() {
        if !cfg.starts_with(CFG_COMMENT_CHAR) {
            args.push(cfg);
        }
    }

    // Clean
    let mut child = process::Command::new("make")
        .arg("--directory")
        .arg("ec")
        .arg("clean")
        .arg("BUILD=build")
        .spawn()
        .unwrap();
    let code = child.wait().unwrap();
    assert!(code.success());

    // Build with output
    let child = process::Command::new("make")
        .arg("--directory")
        .arg("ec")
        .args(args)
        .arg("BUILD=build")
        .stdout(process::Stdio::piped())
        .spawn()
        .unwrap();
    let stdout = child.stdout.unwrap();
    let reader = BufReader::new(stdout);
    reader
        .lines()
        .map_while(Result::ok)
        .for_each(|line| println!("{}", line));

    let build = Path::new(crate::BUILD_DIR).join(model);
    std::fs::copy("ec/build/ec.rom", build.join("ec.rom")).unwrap();
}

fn version() -> String {
    let output = process::Command::new("git")
        .arg("show")
        .arg("--format=\"%cd\"")
        .arg("--date=format:%Y-%m-%d")
        .arg("--no-patch")
        .arg("--no-show-signature")
        .output()
        .unwrap();
    assert!(output.status.success());
    let date = std::str::from_utf8(&output.stdout).unwrap().replace('"', "");
    let date = date.trim();

    let output = process::Command::new("git")
        .arg("describe")
        .arg("--always")
        .arg("--dirty")
        .arg("--abbrev=7")
        .output()
        .unwrap();
    assert!(output.status.success());
    let rev = std::str::from_utf8(&output.stdout).unwrap().replace('"', "");
    let rev = rev.trim();

    format!("{}_{}", date, rev)
}

pub fn build(args: &BuildArgs) {
    let model = &args.model;

    //
    // Check `models/<model>` exists
    //
    if !Path::new("models").join(model).exists() {
        eprintln!("model '{}' not found", model);
        process::exit(1);
    }

    //
    // Construct the version string
    //
    let version = version();
    println!("Building '{}' for '{}'", version, model);

    //
    // Create the build directory
    //
    let build_dir = Path::new(crate::BUILD_DIR).join(model);
    std::fs::create_dir_all(build_dir).unwrap();
    let model_dir = Path::new("models").join(model);

    build_edk2(model);
    //build_coreboot(model);

    if !model_dir.join("ec.rom").exists() && model_dir.join("ec.config").exists() {
        build_ec(model);
    }
}
