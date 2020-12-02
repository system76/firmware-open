CFLAGS=-g -Wall -O2
PREFIX=/usr/bin

all: eeprog 

eeprog: eeprog.o 24cXX.o

eeprog-static: eeprog.o 24cXX.o
	$(CC) -static -o $@ $?

clean: 
	$(RM) eeprog eeprog.o 24cXX.o

distclean: clean
	$(RM) *~
	$(RM) dist/*~

install: eeprog
	install -ps eeprog $(PREFIX)/eeprog-tear
	install -p dist/eeprog-spd-dump $(PREFIX)
	install -p dist/eeprog-spd-flash $(PREFIX)
	install -p dist/eeprog-spd-dump-g34 $(PREFIX)
	install -p dist/eeprog-spd-flash-g34 $(PREFIX)

uninstall:
	$(RM) $(PREFIX)/eeprog-tear
	$(RM) $(PREFIX)/eeprog-spd-dump
	$(RM) $(PREFIX)/eeprog-spd-flash
	$(RM) $(PREFIX)/eeprog-spd-dump-g34
	$(RM) $(PREFIX)/eeprog-spd-flash-g34

.PHONY: all clean distclean install uninstall
