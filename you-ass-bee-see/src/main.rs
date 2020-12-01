use i2cdev::linux::LinuxI2CDevice;

fn main() {
    let mut dev = LinuxI2CDevice::new("/dev/i2c-11", 0x40);
    println!("{:X?}", dev.smbus_read_block_data(0));
}
