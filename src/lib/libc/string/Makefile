CC=gcc -m32
CFLAGS=-I../../../include -O2 -ansi -Wall -nostdlib -nostdinc -fno-builtin
LD=ld -m elf_i386
AR=ar

objects = strlen.o strcmp.o strcat.o strcpy.o strncat.o strncmp.o

all:	$(objects)

../string.o:	$(objects)
	$(AR) rvs ../string.a $(objects)

#strlen.o:	strlen.c
#	$(CC) -c -o strlen.o strlen.c

#strcmp.o:	strcmp.c
#	$(CC) -c -o strcmp.o strcmp.c

#srtcat.o:	strcat.c
#	$(CC) -c -o strcat.o strcat.c

$(objects): %o: %c
	$(CC) $(CFLAGS) -c -o $@ $<
