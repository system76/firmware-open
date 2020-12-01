use i2cdev::core::I2CDevice;
use i2cdev::linux::LinuxI2CDevice;

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
        println!("Status: {:X}", status);
        if status != cmd {
            //TODO: perform error checking here
            return Ok(status);
        }
    }
}

fn main() {
    let mut dev = LinuxI2CDevice::new("/dev/i2c-11", 0x40).unwrap();
    println!("Vendor: {:X}", read(&mut dev, 0).unwrap());
    println!("Device: {:X}", read(&mut dev, 1).unwrap());

    for offset in 0..=8 {
        write(&mut dev, IECS_DATA, offset).unwrap();
        let status = command(&mut dev, CMD_AFRR).unwrap();
        if status == 0 {
            let data = read(&mut dev, MSG_OUT_RDATA).unwrap();
            println!("{:X}: {:X}", offset, data);
        } else {
            println!("{:X}: Error {:X}", offset, status);
        }
    }
}
