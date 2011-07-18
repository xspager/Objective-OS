MAKE=gmake
CC=gcc
CFLAGS=-m32 -nostdlib -nodefaultlibs -O0 -fno-builtin
LD=ld -z nodefaultlibs #-m elf_i386

all:	objos.elf

objos.elf:	boot.o kernel.o beep.o libcrt libcpuid
	$(LD) -Ttext=0x100000 -o objos.elf boot.o kernel.o libcrt/crt.o ../lib/libc/string/strcpy.o ../lib/libc/string/strncmp.o ../lib/libc/string/strcmp.o libcpuid/cpuid.o beep.o


kernel.o:	kernel.c multiboot.h
	$(CC) $(CFLAGS) -c -o kernel.o kernel.c

boot.o: boot.S multiboot.h
	$(CC) $(CFLAGS) -c -o boot.o boot.S

beep.o: beep.asm
	nasm -f elf -o beep.o beep.asm

libcrt:
	$(MAKE) -C libcrt

libcpuid:
	$(MAKE) -C libcpuid

install:	objos.elf
	mount ../../Objective-OS.ima /mnt -oloop
	cp objos.elf /mnt/boot/
	umount /mnt

run:	install
#	qemu-system-x86_64 -m 8 -fda ../../Objective-OS.ima
	qemu -m 8 -fda ../../Objective-OS.ima

#finstall:	objos.elf
#	mount	
