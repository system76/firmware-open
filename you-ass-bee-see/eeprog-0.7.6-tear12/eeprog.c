/***************************************************************************
    copyright            : (C) by 2003-2004 Stefano Barbato
    email                : stefano@codesink.org
    
    Copyright (C) 2011 by Kris Rusocki <kszysiu@gmail.com>
    - usage/strings cleanup
    - misc cleanup: use "static" keyword where appropriate
    - misc cleanup: have confirm_action() return void
    - support custom input and output files
    - support user-defined write cycle time
    - ensure that stdin is a terminal when operating w/o -f
    - do not allow reading data from a terminal w/o -f
    - perform complete input validation before taking action
    - use dedicated exit code when opening I2C device fails

    $Id: eeprog.c,v 1.28 2004/02/29 11:06:41 tat Exp $
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
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "24cXX.h"

#define VERSION 	"0.7.6-tear12"

#define ENV_DEV		"EEPROG_DEV"
#define ENV_I2C_ADDR	"EEPROG_I2C_ADDR"

static int g_quiet;

#define usage_if(a) do { do_usage_if( a , __LINE__); } while(0);
static void do_usage_if(int b, int line)
{
const static char *eeprog_usage = 
"eeprog " VERSION ", a 24Cxx EEPROM reader/writer\n"
"Copyright (c) 2003-2004 by Stefano Barbato - All rights reserved.\n"
"Copyright (c) 2011 by Kris Rusocki - All rights reserved.\n"
"Usage:\n"
"\teeprog [-fqxd] [-16|-8] -r addr[:count] [-o file] /dev/i2c-N  i2c-address\n" 
"\teeprog [-fqd] [-16|-8] -w addr [-i file] [-t tWC] /dev/i2c-N  i2c-address\n" 
"\teeprog -h\n"
"\n"
"  Address modes: \n"
"	-8		Use 8bit address mode for 24c0x...24C16 [default]\n"
"	-16		Use 16bit address mode for 24c32...24C256\n"
"  Actions: \n"
"	-r addr[:count]	Read [count] (1 if omitted) bytes from [addr]\n" 
"			and print them to the standard output (or file\n"
"			specified by -o)\n"
"	-w addr		Write stdin (or file specified by -i) starting\n"
"			at address [addr] of the EEPROM\n"
"	-h		Print this help\n"
"  Options: \n"
"	-i file		Read input from [file] (for use with -w)\n"
"	-o file		Write output to [file] (for use with -r)\n"
"	-x		Set hex output mode\n" 
"	-d		Dummy mode, display what *would* have been done\n" 
"	-f		Disable warnings and don't ask confirmation\n"
"	-q		Quiet mode\n"
"	-t tWC		Define chip's write cycle time to [tWC] miliseconds\n"
"\n"
"The following environment variables could be set instead of the command\n"
"line arguments:\n"
"	EEPROG_DEV		device name(/dev/i2c-N)\n"
"	EEPROG_I2C_ADDR		i2c-address\n"
"\n"
"	Examples\n"
"	1- read 64 bytes from the EEPROM at address 0x54 on bus 0 starting\n"
"	   at address 123 (decimal)\n"
"		eeprog /dev/i2c-0 0x54 -r 123:64\n"
"	2- prints the hex codes of the first 32 bytes read from bus 1 \n"
"	   at address 0x22\n"
"		eeprog /dev/i2c-1 0x51 -x -r 0x22:0x20\n"
"	3- write the current timestamp at address 0x200 of the EEPROM on \n"
"	   bus 0 at address 0x33 \n"
"		date | eeprog /dev/i2c-0 0x33 -w 0x200 -f\n";

	if(!b)
		return;
	fprintf(stderr, "%s\n[line %d]\n", eeprog_usage, line);
	exit(1);
}


#define die_if3(a, msg, code) do { do_die_if( a , msg, __LINE__, code); } while(0)
#define die_if(a, msg) die_if3(a, msg, 1)
static void do_die_if(int b, char* msg, int line, int exitcode)
{
	if(!b)
		return;
	fprintf(stderr, "Error at line %d: %s\n", line, msg);
	//fprintf(stderr, "	sysmsg: %s\n", strerror(errno));
	exit(exitcode);
}

#define print_info(args...) do { if(!g_quiet) fprintf(stderr, args); } while(0)

static int parse_arg(char *arg, int* paddr, int *psize)
{
	char *end;
	unsigned int out_paddr, out_psize;

	if(arg[0] == '\0')
		return -1;

	out_paddr = strtol(arg, &end, 0);
	if(*end == '\0')
	{
		if(paddr)
			*paddr = out_paddr;
		return 1;
	}

	if(*end != ':')
		return -1;

	if(end[1] == '\0')
		return -1;

	out_psize = strtol(end + 1, &end, 0);
	if(*end == '\0')
	{
		if (paddr)
			*paddr = out_paddr;
		if (psize)
			*psize = out_psize;
		return 2;
	}

	return -1;
}

static void confirm_action()
{
	fprintf(stderr, 
	"\n"
	"____________________________WARNING____________________________\n"
	"Erroneously writing to a system EEPROM (like DIMM SPD modules)\n"
	"may break your system.  In such event, it will NOT boot anymore\n"
	"and you may not be able to fix it.\n"
	"\n"
	"Reading from 8bit EEPROMs (like that in your DIMM) while using\n"
	"-16 option can also UNEXPECTEDLY write to them so be sure to\n"
	"use -16 option ONLY when required.\n"
	"\n"
	"Use -f to disable this warning message\n"
	"\n"
	"Press ENTER to continue or hit CTRL-C to exit\n"
	"\n"
	);

	getchar();
}

static int read_from_eeprom(struct eeprom *e, FILE *fp, int addr, int size, int hex)
{
	int ch, i;
	for(i = 0; i < size; ++i, ++addr)
	{
		die_if((ch = eeprom_read_byte(e, addr)) < 0, "read error");
		if(hex)
		{
			if( (i % 16) == 0 ) 
				fprintf(fp, "\n %.4x|  ", addr);
			else if( (i % 8) == 0 ) 
				fprintf(fp, "  ");
			fprintf(fp, "%.2x ", ch);
		} else 
			putc(ch, fp);
	}
	if(hex)
		fprintf(fp, "\n\n");
	fflush(fp);
	return 0;
}

static int write_to_eeprom(struct eeprom *e, FILE *fp, int addr)
{
	int c;
	while((c = fgetc(fp)) != EOF)
	{
		print_info(".");
		fflush(stdout);
		die_if(eeprom_write_byte(e, addr++, c), "write error");
	}
	print_info("\n\n");
	return 0;
}

int main(int argc, char** argv)
{
	struct eeprom e;
	int ret, op, i2c_addr, memaddr, size, want_hex, dummy, force, sixteen, write_cycle_time;

	char *input_file, *output_file;
	FILE *input_fp, *output_fp;

	char *device, *arg = 0, *i2c_addr_s;
	struct stat st;
	int eeprom_type = 0;

	op = want_hex = dummy = force = sixteen = write_cycle_time = 0;
	size = 1; // default
	g_quiet = 0;

	input_file = output_file = NULL;
	input_fp = stdin;
	output_fp = stdout;

	while((ret = getopt(argc, argv, "1:8fr:qhw:xdt:i:o:")) != -1)
	{
		switch(ret)
		{
		case '1':
			usage_if(*optarg != '6' || strlen(optarg) != 1);
			die_if(eeprom_type, "EEPROM type switch (-8 or -16) used twice");
			eeprom_type = EEPROM_TYPE_16BIT_ADDR;	
			break;
		case 'x':
			want_hex++;
			break;
		case 'd':
			dummy++;
			break;
		case '8':
			die_if(eeprom_type, "EEPROM type switch (-8 or -16) used twice");
			eeprom_type = EEPROM_TYPE_8BIT_ADDR;
			break;
		case 'f':
			force++;
			break;
		case 'q':
			g_quiet++;
			break;
		case 'h':
			usage_if(1);
			break;
		case 't':
			die_if(parse_arg(optarg, &write_cycle_time, NULL) != 1 || write_cycle_time < 0, "-t -- invalid argument");
			break;
		case 'i':
			input_file = optarg;
			break;
		case 'o':
			output_file = optarg;
			break;
		default:
			die_if(op != 0, "Both read and write requested"); 
			arg = optarg;
			op = ret;
		}
	}
	if(!eeprom_type)
		eeprom_type = EEPROM_TYPE_8BIT_ADDR; // default

	usage_if(op == 0); // no switches 
	// set device and i2c_addr reading from cmdline or env
	device = i2c_addr_s = 0;
	switch(argc - optind)
	{
	case 0:
		device = getenv(ENV_DEV);
		i2c_addr_s = getenv(ENV_I2C_ADDR);
		break;
	case 1:
		if(stat(argv[optind], &st) != -1)
		{
			device = argv[optind];
			i2c_addr_s = getenv(ENV_I2C_ADDR);
		} else {
			device = getenv(ENV_DEV);
			i2c_addr_s = argv[optind];
		}
		break;
	case 2:
		device = argv[optind++];
		i2c_addr_s = argv[optind];
		break;
	default:
		usage_if(1);
	}
	usage_if(!device || !i2c_addr_s);
	die_if(parse_arg(i2c_addr_s, &i2c_addr, NULL) != 1 || i2c_addr < 0, "I2C address -- invalid argument");
	ret = parse_arg(arg, &memaddr, &size);
	die_if(op == 'r' && (ret == -1 || memaddr < 0 || size < 0), "-r -- invalid argument");
	die_if(op == 'w' && (ret != 1 || memaddr < 0), "-w -- invalid argument");

	print_info("eeprog %s, a 24Cxx EEPROM reader/writer\n", VERSION);
	print_info("Copyright (c) 2003-2004 by Stefano Barbato - All rights reserved.\n");
	print_info("Copyright (c) 2011 by Kris Rusocki - All rights reserved.\n");
	print_info("  Bus: %s, Address: 0x%02x, Mode: %dbit\n", 
			device, i2c_addr, 
			(eeprom_type == EEPROM_TYPE_8BIT_ADDR ? 8 : 16) );
	if(op == 'r')
	{
		print_info("  Operation: read %d bytes from offset %d, Output file: %s\n",
				size, memaddr, output_file ? output_file : "<stdout>");
	} else {
		print_info("  Operation: write at offset %d, Input file: %s\n",
				memaddr, input_file ? input_file : "<stdin>");
		if(write_cycle_time != 0)
			print_info("  Write cycle time: %d milliseconds\n", write_cycle_time);
	}

	if(dummy)
	{
		fprintf(stderr, "Dummy mode selected, nothing done.\n");
		return 0;
	}

	if (input_file) {
		die_if((input_fp = fopen(input_file, "rb")) == NULL,
			"unable to open input file "
			"(check that the file exists and that it's readable)");
	} else {
		input_file = "<stdin>";
	}

	if (output_file) {
		die_if((output_fp = fopen(output_file, "wb")) == NULL,
			"unable to create output file "
			"(check that you have permissions to write the file)");
	} else {
		output_file = "<stdout>";
	}

	die_if3(eeprom_open(device, i2c_addr, eeprom_type, write_cycle_time, &e) < 0, 
			"unable to open eeprom device file "
			"(check that the file exists and that it's readable)",
			2);
	switch(op)
	{
	case 'r':
		if(force == 0) {
			/* Confirmation must come from a terminal */
			die_if(isatty(0) == 0,
				"stdin is not a terminal"
			);
			confirm_action();
		}
		print_info("  Reading %d bytes from 0x%x\n", size, memaddr);
		read_from_eeprom(&e, output_fp, memaddr, size, want_hex);
		break;
	case 'w':
		if(force == 0) {
			/* Don't read data from a terminal */
			die_if(isatty(fileno(input_fp)) == 1,
				"refusing to read data from a terminal\n"
				"\n"
				"Use -i to provide input file or -f to force."
			);

			/* Confirmation must come from a terminal */
			die_if(isatty(0) == 0,
				"stdin is not a terminal"
				"\n"
				"Use -f to force."
			);
			confirm_action();
		}
		print_info("  Writing %s starting at address 0x%x\n",
			input_file, memaddr);
		write_to_eeprom(&e, input_fp, memaddr);
		break;
	default:
		usage_if(1);
		exit(1);
	}
	eeprom_close(&e);

	return 0;
}
