use i2cdev::core::I2CDevice;
use i2cdev::linux::LinuxI2CDevice;

const IECS_CMD: u8 = 8;
const IECS_DATA: u8 = 9;
const MSG_OUT_RDATA: u8 = 18;
const CMD_AFRR: &'static [u8] = &[b'A', b'F', b'R', b'R'];

fn main() {
    let mut dev = LinuxI2CDevice::new("/dev/i2c-11", 0x40).unwrap();
    println!("Vendor: {:X?}", dev.smbus_read_block_data(0));
    println!("Device: {:X?}", dev.smbus_read_block_data(1));

    for offset in 0..=8 {
        dev.smbus_write_block_data(IECS_DATA, &[offset, 0, 0, 0]).unwrap();
        dev.smbus_write_block_data(IECS_CMD, CMD_AFRR).unwrap();

        loop {
            let data = dev.smbus_read_block_data(IECS_CMD).unwrap();
            println!("{:?}", data);
            if data.as_slice() != CMD_AFRR {
                break;
            }
        }

        println!("{:X}: {:X?}", offset, dev.smbus_read_block_data(MSG_OUT_RDATA));
    }
}
