/***************************************************************************
    copyright            : (C) by 2003-2004 Stefano Barbato
    email                : stefano@codesink.org

    Copyright (C) 2011 by Kris Rusocki <kszysiu@gmail.com>
    - support for user-defined write cycle time

    $Id: 24cXX.c,v 1.5 2004/02/29 11:05:28 tat Exp $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/fs.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include "24cXX.h"

static int i2c_write_1b(struct eeprom *e, __u8 buf)
{
	int r;
	// we must simulate a plain I2C byte write with SMBus functions
	r = i2c_smbus_write_byte(e->fd, buf);
	if(r < 0)
		fprintf(stderr, "Error i2c_write_1b: %s\n", strerror(errno));
	usleep(10);
	return r;
}

static int i2c_write_2b(struct eeprom *e, __u8 buf[2])
{
	int r;
	// we must simulate a plain I2C byte write with SMBus functions
	r = i2c_smbus_write_byte_data(e->fd, buf[0], buf[1]);
	if(r < 0)
		fprintf(stderr, "Error i2c_write_2b: %s\n", strerror(errno));
	usleep(10);
	return r;
}

static int i2c_write_3b(struct eeprom *e, __u8 buf[3])
{
	int r;
	// we must simulate a plain I2C byte write with SMBus functions
	// the __u16 data field will be byte swapped by the SMBus protocol
	r = i2c_smbus_write_word_data(e->fd, buf[0], buf[2] << 8 | buf[1]);
	if(r < 0)
		fprintf(stderr, "Error i2c_write_3b: %s\n", strerror(errno));
	usleep(10);
	return r;
}


#define CHECK_I2C_FUNC( var, label ) \
	do { 	if(0 == (var & label)) { \
		fprintf(stderr, "\nError: " \
			#label " function is required. Program halted.\n\n"); \
		exit(1); } \
	} while(0);

int eeprom_open(char *dev_fqn, int addr, int type, int write_cycle_time, struct eeprom* e)
{
    unsigned long funcs;
	int fd, r;
	e->fd = e->addr = 0;
	e->dev = 0;
	
	fd = open(dev_fqn, O_RDWR);
	if(fd <= 0)
	{
		fprintf(stderr, "Error eeprom_open: %s\n", strerror(errno));
		return -1;
	}

	// get funcs list
	if((r = ioctl(fd, I2C_FUNCS, &funcs) < 0))
	{
		fprintf(stderr, "Error eeprom_open: %s\n", strerror(errno));
		return -1;
	}

	
	// check for req funcs
	CHECK_I2C_FUNC( funcs, I2C_FUNC_SMBUS_READ_BYTE );
	CHECK_I2C_FUNC( funcs, I2C_FUNC_SMBUS_WRITE_BYTE );
	CHECK_I2C_FUNC( funcs, I2C_FUNC_SMBUS_READ_BYTE_DATA );
	CHECK_I2C_FUNC( funcs, I2C_FUNC_SMBUS_WRITE_BYTE_DATA );
	CHECK_I2C_FUNC( funcs, I2C_FUNC_SMBUS_READ_WORD_DATA );
	CHECK_I2C_FUNC( funcs, I2C_FUNC_SMBUS_WRITE_WORD_DATA );

	// set working device
	if( ( r = ioctl(fd, I2C_SLAVE, addr)) < 0)
	{
		fprintf(stderr, "Error eeprom_open: %s\n", strerror(errno));
		return -1;
	}
	e->fd = fd;
	e->addr = addr;
	e->dev = dev_fqn;
	e->type = type;
	e->write_cycle_time = write_cycle_time;
	return 0;
}

int eeprom_close(struct eeprom *e)
{
	close(e->fd);
	e->fd = -1;
	e->dev = 0;
	e->type = EEPROM_TYPE_UNKNOWN;
	return 0;
}

#if 0
int eeprom_24c32_write_byte(struct eeprom *e, __u16 mem_addr, __u8 data)
{
	__u8 buf[3] = { (mem_addr >> 8) & 0x00ff, mem_addr & 0x00ff, data };
	return i2c_write_3b(e, buf);
}


int eeprom_24c32_read_current_byte(struct eeprom* e)
{
	ioctl(e->fd, BLKFLSBUF); // clear kernel read buffer
	return i2c_smbus_read_byte(e->fd);
}

int eeprom_24c32_read_byte(struct eeprom* e, __u16 mem_addr)
{
	int r;
	ioctl(e->fd, BLKFLSBUF); // clear kernel read buffer
	__u8 buf[2] = { (mem_addr >> 8) & 0x0ff, mem_addr & 0x0ff };
	r = i2c_write_2b(e, buf);
	if (r < 0)
		return r;
	r = i2c_smbus_read_byte(e->fd);
	return r;
}
#endif


int eeprom_read_current_byte(struct eeprom* e)
{
	ioctl(e->fd, BLKFLSBUF); // clear kernel read buffer
	return i2c_smbus_read_byte(e->fd);
}

int eeprom_read_byte(struct eeprom* e, __u16 mem_addr)
{
	int r;
	ioctl(e->fd, BLKFLSBUF); // clear kernel read buffer
	if(e->type == EEPROM_TYPE_8BIT_ADDR)
	{
		__u8 buf =  mem_addr & 0x0ff;
		r = i2c_write_1b(e, buf);
	} else if(e->type == EEPROM_TYPE_16BIT_ADDR) {
		__u8 buf[2] = { (mem_addr >> 8) & 0x0ff, mem_addr & 0x0ff };
		r = i2c_write_2b(e, buf);
	} else {
		fprintf(stderr, "ERR: unknown eeprom type\n");
		return -1;
	}
	if (r < 0)
		return r;
	r = i2c_smbus_read_byte(e->fd);
	return r;
}

int eeprom_write_byte(struct eeprom *e, __u16 mem_addr, __u8 data)
{
	int ret;

	if(e->type == EEPROM_TYPE_8BIT_ADDR) {
		__u8 buf[2] = { mem_addr & 0x00ff, data };
		ret = i2c_write_2b(e, buf);
		if (ret == 0 && e->write_cycle_time != 0) {
			usleep(1000 * e->write_cycle_time);
		}
		return ret;
	} else if(e->type == EEPROM_TYPE_16BIT_ADDR) {
		__u8 buf[3] = 
			{ (mem_addr >> 8) & 0x00ff, mem_addr & 0x00ff, data };
		ret = i2c_write_3b(e, buf);
		if (ret == 0 && e->write_cycle_time != 0) {
			usleep(1000 * e->write_cycle_time);
		}
		return ret;
	} 
	fprintf(stderr, "ERR: unknown eeprom type\n");
	return -1;
}

