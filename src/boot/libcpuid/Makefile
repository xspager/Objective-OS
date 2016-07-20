
CC=gcc
CFLAGS=-m32 -fno-builtin -I../../include

all:	cpuid.o

cpuid.o: cpuid.c cpuid.h
	$(CC) $(CFLAGS) -c -o cpuid.o cpuid.c
