CC=gcc -ggdb
CFLAGS=-I../../../include
LIBFLAGS=-O2 -ansi -Wall -nostdlib -nostdinc
LD=ld #-m elf_i386
AR=ar
RANLIB=ranlib

#string = strlen.o strcmp.o strcat.o strcpy.o strncat.o
#ctype = isalnum.o isalpha.o iscntrl.o isdigit.o \
	isgraph.o islower.o isprint.o ispunct.o \
	isspace.o isupper.o isxdigit.o isascii.o isblank.o

#objects = string/$(ostring) ctype/$(octype)
objects = string/*.o ctype/*.o

all:	libc.a

libc.a:	string ctype
	$(AR) ru libc.a $(objects)
	$(RANLIB) libc.a

#$(objects): %o: %c
#	$(CC) $(LIBFLAGS) $(CFLAGS) -c -o $@ $<

string:
	$(MAKE) -C string/

ctype:
	$(MAKE) -C ctype/

testlibc:	testlibc.c libc.a
	$(CC) $(CFLAGS) $(LIBFLAGS) -o testlibc testlibc.c libc.a
