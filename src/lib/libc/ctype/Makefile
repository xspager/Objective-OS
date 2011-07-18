CC=gcc -m32
CFLAGS=-I../../../include -O2 -ansi -Wall -nostdlib -nostdinc -fno-builtin
AR=ar

objects = isalnum.o isalpha.o iscntrl.o isdigit.o \
	isgraph.o islower.o isprint.o ispunct.o \
	isspace.o isupper.o isxdigit.o isascii.o isblank.o

all:	ctype.a

ctype.a:	$(objects)
	$(AR) rvs ctype.a $(objects) 
	
$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	rm -f *.o
