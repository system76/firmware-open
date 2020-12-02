use i2cdev::core::I2CDevice;
use i2cdev::linux::LinuxI2CDevice;
use std::fs;

const IECS_CMD: u8 = 8;
const IECS_DATA: u8 = 9;
const MSG_OUT_RDATA: u8 = 18;

const CMD_AFRR: u32 = 0x52524641;
const CMD_AUTH: u32 = 0x48545541;
const CMD_BLKW: u32 = 0x574b4c42;
const CMD_BOPS: u32 = 0x53504f42;
const CMD_PCYC: u32 = 0x43594350;

fn read<I: I2CDevice>(dev: &mut I, reg: u8) -> Result<u32, I::Error> {
    let bytes = dev.smbus_read_block_data(reg)?;
    //TODO: return error on bytes.len() != 4
    Ok(
        bytes[0] as u32 |
        (bytes[1] as u32) << 8 |
        (bytes[2] as u32) << 16 |
        (bytes[3] as u32) << 24
    )
}

fn write<I: I2CDevice>(dev: &mut I, reg: u8, data: u32) -> Result<(), I::Error> {
    let bytes = [
        data as u8,
        (data >> 8) as u8,
        (data >> 16) as u8,
        (data >> 24) as u8,
    ];
    dev.smbus_write_block_data(reg, &bytes)
}


fn command<I: I2CDevice>(dev: &mut I, cmd: u32) -> Result<u32, I::Error> {
    write(dev, IECS_CMD, cmd)?;
    loop {
        let status = read(dev, IECS_CMD)?;
        if status != cmd {
            //TODO: perform error checking here
            return Ok(status);
        }
    }
}

fn main() {
    //TODO: force power and sleep 40ms

    let mut dev = LinuxI2CDevice::new("/dev/i2c-11", 0x40).unwrap();
    eprintln!("Vendor: {:X}", read(&mut dev, 0).unwrap());
    eprintln!("Device: {:X}", read(&mut dev, 1).unwrap());

    let image = fs::read("../models/galp5/usb4-retimer.rom").unwrap();

    for i in 2..=32 {
        println!("{}: {:X}", i, read(&mut dev, i).unwrap());
    }

    /*
    eprintln!("Set offset to 0");
    write(&mut dev, IECS_DATA, 0).unwrap();
    let status = command(&mut dev, CMD_BOPS).unwrap();
    if status != 0 {
        panic!("Failed to set offset: {:X}", status);
    }

    let mut i = 0;
    while i < image.len() {
        eprint!("\rWrite {}/{}", i, image.len());

        let start = i;
        let mut j = 0;
        while i < image.len() && j < 64 {
            let data = {
                image[i] as u32 |
                (image[i + 1] as u32) << 8 |
                (image[i + 2] as u32) << 16 |
                (image[i + 3] as u32) << 24
            };
            write(&mut dev, MSG_OUT_RDATA, data).unwrap();
            i += 4;
            j += 4;
        }

        let status = command(&mut dev, CMD_BLKW).unwrap();
        if status != 0 {
            panic!("Failed to write block at {:X}:{:X}: {:X}", start, i, status);
        }
    }
    eprintln!("\rWrite {}/{}", i, image.len());

    eprintln!("Authenticate");
    let status = command(&mut dev, CMD_AUTH).unwrap();
    if status != 0 {
        panic!("Failed to authenticate: {:X}", status);
    }

    eprintln!("Power cycle");
    let status = command(&mut dev, CMD_PCYC).unwrap();
    if status != 0 {
        panic!("Failed to power cycle: {:X}", status);
    }

    eprintln!("Successfully flashed retimer");
    */
}
