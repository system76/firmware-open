use coreboot_collector::sideband::Sideband;
use std::{
    fs,
    rc::Rc,
    process,
    thread,
    time
};

const IECS_CMD: u8 = 8;
const IECS_DATA: u8 = 9;
const MSG_OUT_RDATA: u8 = 18;

const CMD_AFRR: u32 = 0x52524641;
const CMD_AUTH: u32 = 0x48545541;
const CMD_BLKW: u32 = 0x574b4c42;
const CMD_BOPS: u32 = 0x53504f42;
const CMD_PCYC: u32 = 0x43594350;


#[repr(u64)]
pub enum GpioPadMode {
    Gpio = 0 << 10,
    Nf1 = 1 << 10,
    Nf2 = 2 << 10,
    Nf3 = 3 << 10,
    Nf4 = 4 << 10,
    Nf5 = 5 << 10,
    Nf6 = 6 << 10,
    Nf7 = 7 << 10,
}

pub struct Gpio {
    //TODO: this should probably be locked
    sideband: Rc<Sideband>,
    port: u8,
    pad: u8,
}

impl Gpio {
    const PAD_MODE: u64 = 0b111 << 10;
    const RX_DIS: u64 = 1 << 9;
    const TX_DIS: u64 = 1 << 8;
    const RX: u64 = 1 << 1;
    const TX: u64 = 1 << 0;

    pub fn new(sideband: Rc<Sideband>, port: u8, pad: u8) -> Self {
        Self { sideband, port, pad }
    }

    unsafe fn get_config(&self) -> u64 {
        self.sideband.gpio(self.port, self.pad)
    }

    unsafe fn set_config(&mut self, config: u64) {
        self.sideband.set_gpio(self.port, self.pad, config);
    }

    unsafe fn get_mask(&self, mask: u64) -> bool {
        self.get_config() & mask == mask
    }

    unsafe fn set_mask(&mut self, mask: u64, value: bool) {
        let mut config = self.get_config();
        if value {
            config |= mask;
        } else {
            config &= !mask;
        }
        self.set_config(config);
    }

    pub unsafe fn set_pad_mode(&mut self, mode: GpioPadMode) {
        let mut config = self.get_config();
        config &= !Self::PAD_MODE;
        config |= mode as u64;
        self.set_config(config);

    }

    pub unsafe fn enable_rx(&mut self, value: bool) {
        self.set_mask(Self::RX_DIS, !value);
    }

    pub unsafe fn enable_tx(&mut self, value: bool) {
        self.set_mask(Self::TX_DIS, !value);
    }

    pub unsafe fn get_rx(&self) -> bool {
        self.get_mask(Self::RX)
    }

    pub unsafe fn get_tx(&self) -> bool {
        self.get_mask(Self::TX)
    }

    pub unsafe fn set_tx(&mut self, value: bool) {
        self.set_mask(Self::TX, value);
    }
}

pub struct I2CBitbang {
    scl: Gpio,
    scl_config: u64,
    sda: Gpio,
    sda_config: u64,
}

impl I2CBitbang {
    pub unsafe fn new(mut scl: Gpio, mut sda: Gpio) -> Self {
        //TODO: will this transmit something invalid?

        let scl_config = scl.get_config();
        scl.enable_rx(true);
        scl.enable_tx(false);
        scl.set_tx(false);
        scl.set_pad_mode(GpioPadMode::Gpio);
        println!("SCL config set to 0x{:X}, was 0x{:X}", scl.get_config(), scl_config);

        let sda_config = sda.get_config();
        sda.enable_rx(true);
        sda.enable_tx(false);
        sda.set_tx(false);
        sda.set_pad_mode(GpioPadMode::Gpio);
        println!("SDA config set to 0x{:X}, was 0x{:X}", sda.get_config(), sda_config);

        Self { scl, scl_config, sda, sda_config, }
    }

    // Delay half half of period
    fn delay(&self) {
        // Hard coded to 5 us, which is half of the period 10 us for a frequency of 100 KHz
        thread::sleep(time::Duration::from_micros(5));
    }

    // Pull SCL low
    unsafe fn clr_scl(&mut self) {
        self.scl.enable_tx(true);
    }

    // Release SCL, bus pulls it high
    unsafe fn set_scl(&mut self) {
        self.scl.enable_tx(false);
    }

    // Pull SDA low
    unsafe fn clr_sda(&mut self) {
        self.sda.enable_tx(true);
    }

    // Release SDA, bus pulls it high
    unsafe fn set_sda(&mut self) {
        self.sda.enable_tx(false);
    }

    unsafe fn start(&mut self) {
        self.set_scl();
        self.set_sda();
        self.delay();
        self.clr_sda();
        self.delay();
        self.clr_scl();
        self.delay();
    }

    unsafe fn stop(&mut self) {
        self.clr_sda();
        self.delay();
        self.set_scl();
        self.delay();
        self.set_sda();
        self.delay();
    }

    unsafe fn write_bit(&mut self, bit: bool) {
        if bit {
            self.set_sda();
        } else {
            self.clr_sda();
        }
        self.delay();
        self.set_scl();
        self.delay();
        self.clr_scl();
    }

    unsafe fn read_bit(&mut self) -> bool {
        self.set_sda();
        self.delay();
        self.set_scl();
        self.delay();
        let bit = self.sda.get_rx();
        self.clr_scl();
        bit
    }

    unsafe fn write_byte(&mut self, byte: u8, start: bool) -> bool {
        if start {
            self.start();
        }
        for i in (0..8).rev() {
            self.write_bit(byte & (1 << i) != 0);
        }
        self.read_bit()
    }

    unsafe fn read_byte(&mut self, ack: bool) -> u8 {
        let mut byte = 0;
        for i in (0..8).rev() {
            if self.read_bit() {
                byte |= 1 << i;
            }
        }
        self.write_bit(!ack);
        byte
    }

    pub unsafe fn smbus_block_write(&mut self, address: u8, command: u8, bytes: &[u8]) -> usize {
        // Only 32 bytes can be processed at a time
        if bytes.len() > 32 {
            return 0;
        }

        let mut count = 0;
        if self.write_byte(address << 1, true) {
            if self.write_byte(command, false) {
                if self.write_byte(bytes.len() as u8, false) {
                    for byte in bytes.iter() {
                        if self.write_byte(*byte, false) {
                            count += 1;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        self.stop();
        count
    }

    pub unsafe fn smbus_block_read(&mut self, address: u8, command: u8) -> Vec<u8> {
        //TODO: use static buffer?
        let mut bytes = Vec::new();
        if self.write_byte(address << 1, true) {
            if self.write_byte(command, false) {
                if self.write_byte(address << 1 | 1, true) {
                    let count = self.read_byte(true);
                    for _i in 0..count {
                        bytes.push(self.read_byte(true));
                    }
                }
            }
        }
        self.stop();
        bytes
    }
}

impl Drop for I2CBitbang {
    fn drop(&mut self) {
        unsafe {
            //TODO: will this transmit something invalid?

            println!("SCL config set to 0x{:X}, was 0x{:X}", self.scl_config, self.scl.get_config());
            self.scl.set_config(self.scl_config);

            println!("SDA config set to 0x{:X}, was 0x{:X}", self.sda_config, self.sda.get_config());
            self.sda.set_config(self.sda_config);
        }
    }
}

pub struct Retimer {
    i2c: I2CBitbang,
    address: u8,
}

impl Retimer {
    pub fn new(i2c: I2CBitbang, address: u8) -> Self {
        Self { i2c, address }
    }

    pub unsafe fn read(&mut self, reg: u8) -> Result<u32, String> {
        let bytes = self.i2c.smbus_block_read(self.address, reg);
        if bytes.len() == 4 {
            Ok(
                bytes[0] as u32 |
                (bytes[1] as u32) << 8 |
                (bytes[2] as u32) << 16 |
                (bytes[3] as u32) << 24
            )
        } else {
            Err(format!("Retimer::read: read {} bytes instead of 4", bytes.len()))
        }
    }

    pub unsafe fn write(&mut self, reg: u8, data: u32) -> Result<(), String> {
        let bytes = [
            data as u8,
            (data >> 8) as u8,
            (data >> 16) as u8,
            (data >> 24) as u8,
        ];
        let count = self.i2c.smbus_block_write(self.address, reg, &bytes);
        if count == 4 {
            Ok(())
        } else {
            Err(format!("Retimer::write: wrote {} bytes instead of 4", count))
        }
    }


    pub unsafe fn command(&mut self, cmd: u32) -> Result<(), String> {
        self.write(IECS_CMD, cmd)?;
        //TODO: is this the right number of retries?
        let retries = 1000;
        for _i in 0..retries {
            let status = self.read(IECS_CMD)?;
            if status != cmd {
                if status == 0 {
                    return Ok(());
                } else {
                    return Err(format!("Retimer::command: read 0x{:X} instead of 0", status));
                }
            }
        }
        Err(format!("Retimer::command: timed out after {} retries", retries))
    }
}

unsafe fn flash_retimer(retimer: &mut Retimer) -> Result<(), String> {
    eprintln!("Vendor: {:X}", retimer.read(0)?);
    eprintln!("Device: {:X}", retimer.read(1)?);

    /*
    let image = fs::read("../models/galp5/usb4-retimer.rom").unwrap();

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

    Ok(())
}

unsafe fn retimer_access(i2c: I2CBitbang) -> i32 {
    let mut retimer = Retimer::new(i2c, 0x40);
    match flash_retimer(&mut retimer) {
        Ok(()) => 0,
        Err(err) => {
            eprintln!("Failed to flash retimer: {}", err);
            1
        }
    }
}

unsafe fn i2c_access(sideband: Rc<Sideband>) -> i32 {
    let scl = Gpio::new(sideband.clone(), 0x6A, 0x26); // GPP_C19
    let sda = Gpio::new(sideband.clone(), 0x6A, 0x24); // GPP_C18
    let i2c = I2CBitbang::new(scl, sda);
    retimer_access(i2c)
}

unsafe fn i2c_enable(sideband: Rc<Sideband>) -> i32 {
    let mut rom_i2c_en = Gpio::new(sideband.clone(), 0x6A, 0x70); // GPP_E1

    println!("Set ROM_I2C_EN high");
    rom_i2c_en.set_tx(true);

    println!("Sleep 40 ms");
    thread::sleep(time::Duration::from_millis(40));

    let exit_status = i2c_access(sideband);

    eprintln!("Set ROM_I2C_EN low");
    rom_i2c_en.set_tx(false);

    exit_status
}

unsafe fn force_power(sideband: Rc<Sideband>) -> i32 {
    let mut force_power = Gpio::new(sideband.clone(), 0x6E, 0x82); // GPP_A23

    println!("Set FORCE_POWER high");
    force_power.set_tx(true);

    println!("Sleep 40 ms");
    thread::sleep(time::Duration::from_millis(40));

    let exit_status = i2c_enable(sideband);

    eprintln!("Set FORCE_POWER low");
    force_power.set_tx(false);

    exit_status
}

fn main() {
    //TODO: check model

    unsafe {
        let sideband = match Sideband::new(0xFD00_0000) {
            Ok(ok) => Rc::new(ok),
            Err(err) => {
                eprintln!("Failed to access sideband: {}", err);
                process::exit(1);
            }
        };

        process::exit(force_power(sideband));
    }
}
