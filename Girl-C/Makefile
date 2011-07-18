CC = gcc
#CC = colorgcc
CFLAGS = -ansi -ggdb -Wall

all:	cpp test

cpp:	cpp.c string
	$(CC) $(CFLAGS) -o cpp cpp.c libc/string/strlen.o libc/string/strcmp.o

test:	test/testlibc.c
	$(CC) $(CFLAGS) -o test/testlibc test/testlibc.c libc/string/strlen.o libc/string/strcmp.o

#string:# libc/string/strlen.c libc/string/strcmp.c

string:	strlen strcmp
#	$(CC) $(CFLAGS) -o libc/string/string.o -c libc/string/strlen.o libc/string/strcmp.o

strlen: libc/string/strlen.c
	$(CC) $(CFLAGS) -c -nostdlib -o libc/string/strlen.o libc/string/strlen.c

strcmp: libc/string/strcmp.c
	$(CC) $(CFLAGS) -c -nostdlib -o libc/string/strcmp.o libc/string/strcmp.c
