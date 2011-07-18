CC=gcc -m32 -nostdlib -nostartfiles -nodefaultlibs
LD=ld -m elf_i386

all:	multi

multi:	kernel boot
	$(LD) -o multi.elf boot.o kernel.o

kernel:
	$(CC) -c -o kernel.o kernel.c

boot:
	$(CC) -c -o boot.o boot.S

install:	multi
	cp multi.elf ../../../boot/grub
