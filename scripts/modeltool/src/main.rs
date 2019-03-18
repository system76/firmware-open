use ecflash::{Ec, EcFile};
use intelflash::{Me, Rom};
use std::{env, fs, process};
use std::path::Path;

fn ec(path: &Path) {
    println!("- [EC]({})", path.display());
    match fs::read(path) {
        Ok(data) => {
            println!("  - Size: {} KB", data.len() / 1024);
            {
                let mut ec = EcFile::new(data);
                println!("  - Model: {}", ec.project());
                println!("  - Version: {}", ec.version());
            }
        },
        Err(err) => {
            println!("  - *Read Error: {}*", err);
        }
    }
}

fn fd(path: &Path) {
    println!("- [FD]({})", path.display());
    match fs::read(path) {
        Ok(data) => {
            println!("  - Size: {} KB", data.len() / 1024);
            match Rom::new(&data) {
                Ok(rom) => {
                    match rom.high_assurance_platform() {
                        Ok(hap) => {
                            println!("  - HAP: {}", hap);
                        },
                        Err(err) => {
                            println!("  - *HAP Error: {}*", err);
                        }
                    }
                },
                Err(err) => {
                    println!("  - *Parse Error: {}*", err);
                }
            }
        },
        Err(err) => {
            println!("  - *Read Error: {}*", err);
        }
    }
}

fn me(path: &Path) {
    println!("- [ME]({})", path.display());
    match fs::read(path) {
        Ok(data) => {
            println!("  - Size: {} KB", data.len() / 1024);
            match Me::new(&data) {
                Ok(me) => {
                    if let Some(version) = me.version() {
                        println!("  - Version: {}", version);
                    }
                },
                Err(err) => {
                    println!("  - *Parse Error: {}*", err);
                }
            }
        },
        Err(err) => {
            println!("  - *Read Error: {}*", err);
        }
    }
}

fn main() {
    let args: Vec<String> = env::args().skip(1).collect();
    if args.is_empty() {
        println!("modeltool [model directory]...");
        process::exit(1);
    }

    for arg in args {
        let path = Path::new(&arg);

        ec(&path.join("ec.rom"));
        fd(&path.join("fd.rom"));
        me(&path.join("me.rom"));
    }
}
