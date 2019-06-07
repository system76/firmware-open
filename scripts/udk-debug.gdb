#!/usr/bin/gdb -x
target remote :1234
source /opt/intel/udkdebugger/script/udk_gdb_script
iowatch/b 0x80
