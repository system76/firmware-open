// SPDX-License-Identifier: GPL-3.0-only
// SPDX-FileCopyrightText: 2026 System76, Inc.

use crate::cli::FlashArgs;
use std::path::Path;
use std::process;

pub fn stage_update(args: &FlashArgs) {
    let model = &args.model;
    println!("flash({})", model);

    let base_dir = std::env::var("BASEDIR").unwrap();

    //
    // Check `models/<model>` exists
    //
    if !Path::new("models").join(model).exists() {
        eprintln!("model '{}' not found", model);
        process::exit(1);
    }

    //
    // Check DMI product version matches `<model>`
    //
    let stdout = std::fs::read_to_string("/sys/class/dmi/id/product_version").unwrap();
    let dmi_model = stdout.trim();
    if dmi_model != *model {
        eprintln!("refusing to flash model '{}' to system '{}'", model, dmi_model);
        process::exit(1);
    }

    //
    // Rebuild firmware-update
    //

    let mut child = process::Command::new("make")
        .arg("--quiet")
        .arg("--directory")
        .arg("apps/firmware-update")
        .arg("clean")
        .spawn()
        .unwrap();
    let code = child.wait().unwrap();
    assert!(code.success());

    let mut child = process::Command::new("make")
        .arg("--quiet")
        .arg("--directory")
        .arg("apps/firmware-update")
        .arg("build/x86_64-unknown-uefi/boot.efi")
        .spawn()
        .unwrap();
    let code = child.wait().unwrap();
    assert!(code.success());

    //
    // Copy files to staging area
    //

    // Recreate directory layout
    let build = Path::new(crate::BUILD_DIR).join(model);
    let staging = build.join(base_dir);
    let _ = std::fs::remove_dir_all(&staging);
    std::fs::create_dir_all(&staging).unwrap();
    let firmware_dir = staging.join("firmware");
    std::fs::create_dir(&firmware_dir).unwrap();
    let res_dir = staging.join("res");
    std::fs::create_dir(&res_dir).unwrap();

    // Copy firmware-update tool
    std::fs::copy("apps/firmware-update/build/x86_64-unknown-uefi/boot.efi", staging.join("boot.efi")).unwrap();
    // Copy resources
    std::fs::copy("apps/firmware-update/res/firmware.nsh", res_dir.join("firmware.nsh")).unwrap();
    std::fs::copy("apps/firmware-update/res/shell.efi", res_dir.join("shell.efi")).unwrap();
    std::fs::copy("apps/firmware-update/res/splash.bmp", res_dir.join("splash.bmp")).unwrap();

    // Copy system firmware
    let firmware = Path::new("firmware.rom");
    if build.join(firmware).exists() {
        std::fs::copy(build.join(firmware), firmware_dir.join(firmware)).unwrap();
    }

    // Copy EC firmware
    let ec = Path::new("ec.rom");
    if build.join(ec).exists() {
        std::fs::copy(build.join(ec), firmware_dir.join(ec)).unwrap();
    }

    // Adding the staged firmware update to ESP requires root access
    // - Locate EFI system partition
    // - Sync files to ESP
    // - Add boot entry for firmware-update
    // - Set BootNext to firmware-update
}
