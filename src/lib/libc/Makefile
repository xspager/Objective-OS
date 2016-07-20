CC=gcc -ggdb
CFLAGS=-I../../../include
LIBFLAGS=-O2 -ansi -Wall -nostdlib -nostdinc
LD=ld -m elf_i386
AR=ar
RANLIB=ranlib

objects = string/*.o ctype/*.o

all:	libc.a

libc.a:	string ctype
	$(AR) ru libc.a $(objects)
	$(RANLIB) libc.a

string:
	$(MAKE) -C string/

ctype:
	$(MAKE) -C ctype/

testlibc:	testlibc.c libc.a
	$(CC) $(CFLAGS) $(LIBFLAGS) -o testlibc testlibc.c libc.a
