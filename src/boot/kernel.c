/* kernel.c - the C part of the kernel */
/* Copyright (C) 1999  Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */

#include "multiboot.h"
#include "libcpuid/cpuid.h"
#include "libcrt/crt.h"

/* Macros. */

/* Check if the bit BIT in FLAGS is set. */
#define CHECK_FLAG(flags,bit)   ((flags) & (1 << (bit)))

/* Forward declarations. */
void cmain (unsigned long magic, unsigned long addr);
extern void itoa (char *buf, int base, int d);
unsigned char getc();

/* Check if MAGIC is valid and print the Multiboot information structure
   pointed by ADDR. */
void
cmain (unsigned long magic, unsigned long addr) {
    multiboot_info_t *mbi;

    /* Clear the screen. */
    init(); // Init the screen
    cls (); // and crear it

    printf("\nObjective-OS\n\n");

#if 0
	/* Am I booted by a Multiboot-compliant boot loader? */
    	if (magic != MULTIBOOT_BOOTLOADER_MAGIC)
    	{
    		printf ("Invalid magic number: 0x%x\n", (unsigned) magic);
    		return;
    	}
    
    /* Set MBI to the address of the Multiboot information structure. */
       mbi = (multiboot_info_t *) addr;

    /* Print out the flags. */
       printf ("flags = 0x%x\n", (unsigned) mbi->flags);

    /* Are mem_* valid? */
		if (CHECK_FLAG (mbi->flags, 0))
			printf ("mem_lower = %uKB, mem_upper = %uMB\n",
        		(unsigned) mbi->mem_lower, (unsigned) mbi->mem_upper/1024);
    
    /* Is boot_device valid? */
		if (CHECK_FLAG (mbi->flags, 1))
			printf ("boot_device = 0x%x\n", (unsigned) mbi->boot_device);
    
    /* Is the command line passed? */
		if (CHECK_FLAG (mbi->flags, 2))
             printf ("cmdline = %s\n", (char *) mbi->cmdline);
    
    /* Are mods_* valid? */
		if (CHECK_FLAG (mbi->flags, 3))
		{
			module_t *mod;
			int i;

               printf ("mods_count = %d, mods_addr = 0x%x\n",
                       (int) mbi->mods_count, (int) mbi->mods_addr);
               for (i = 0, mod = (module_t *) mbi->mods_addr;
                    i < mbi->mods_count;
                    i++, mod++)
                 printf (" mod_start = 0x%x, mod_end = 0x%x, string = %s\n",
                         (unsigned) mod->mod_start,
                         (unsigned) mod->mod_end,
                         (char *) mod->string);
             }
    
    /* Bits 4 and 5 are mutually exclusive! */
           if (CHECK_FLAG (mbi->flags, 4) && CHECK_FLAG (mbi->flags, 5))
             {
               printf ("Both bits 4 and 5 are set.\n");
               return;
             }
    
    /* Is the symbol table of a.out valid? */
           if (CHECK_FLAG (mbi->flags, 4))
             {
               aout_symbol_table_t *aout_sym = &(mbi->u.aout_sym);

               printf ("aout_symbol_table: tabsize = 0x%0x, "
                       "strsize = 0x%x, addr = 0x%x\n",
                       (unsigned) aout_sym->tabsize,
                       (unsigned) aout_sym->strsize,
                       (unsigned) aout_sym->addr);
             }
    
    /* Is the section header table of ELF valid? */
           if (CHECK_FLAG (mbi->flags, 5))
             {
               elf_section_header_table_t *elf_sec = &(mbi->u.elf_sec);

               printf ("elf_sec: num = %u, size = 0x%x,"
                       " addr = 0x%x, shndx = 0x%x\n",
                       (unsigned) elf_sec->num, (unsigned) elf_sec->size,
                       (unsigned) elf_sec->addr, (unsigned) elf_sec->shndx);
             }
    
    /* Are mmap_* valid? */
           if (CHECK_FLAG (mbi->flags, 6))
             {
               memory_map_t *mmap;

               printf ("mmap_addr = 0x%x, mmap_length = 0x%x\n",
                       (unsigned) mbi->mmap_addr, (unsigned) mbi->mmap_length);
               for (mmap = (memory_map_t *) mbi->mmap_addr;
                    (unsigned long) mmap < mbi->mmap_addr + mbi->mmap_length;
                    mmap = (memory_map_t *) ((unsigned long) mmap
                                             + mmap->size + sizeof (mmap->size)))
                 printf (" size = 0x%x, base_addr = 0x%x%x,"
                         " length = 0x%x%x, type = 0x%x\n",
                         (unsigned) mmap->size,
                         (unsigned) mmap->base_addr_high,
                         (unsigned) mmap->base_addr_low,
                         (unsigned) mmap->length_high,
                         (unsigned) mmap->length_low,
                         (unsigned) mmap->type);
             }

    	   if (CHECK_FLAG (mbi->flags, 9))
    	   	{
    			printf("Boot Loader Name: %s\n", (char *) mbi->boot_loader_name);
    		}

    	   if(CHECK_FLAG (mbi->flags, 11)){
    		   printf("vbe:\n");
    		   printf(" vbe_control_info = 0x%x\n", mbi->vbe_control_info);
    		   printf(" vbe_mode_info = 0x%x\n", mbi->vbe_mode_info);
    		   printf(" vbe_mode = 0x%x\n", mbi->vbe_mode);
    		   printf(" vbe_interface_seg = 0x%x\n", mbi->vbe_interface_seg);
    		   printf(" vbe_interface_off = 0x%x\n", mbi->vbe_interface_off);
    		   printf(" vbe_interface_len = 0x%x\n", mbi->vbe_interface_len);
    	   }
#endif
    
    unsigned int i;

	printf("CPUid:\n");
    struct cpu_id cpuidres; // cpuid result
    
	cpuid(&cpuidres);
	char *vendor;
	switch(cpuidres.vendor){
		case IS_AMD:
			vendor = "AMD";
			break;
		case IS_Intel:
			vendor = "Intel";
			break;
		default:
			vendor = "Unknown";
			break;
	}
	printf(" vendor = %s\n", vendor);
    printf(" maximum supported standard level = 0x%x\n", cpuidres.max_sup_std_levl);
    printf(" vendor string = %s\n", cpuidres.vendor_string);
    printf(" processor signature = 0x%x\n", cpuidres.processor_signature);
    printf(" stepping id = 0x%x\n", cpuidres.stepping_id);
    printf(" model number = 0x%x\n", cpuidres.model_number);
    printf(" family code = 0x%x\n", cpuidres.family_code);
    printf(" processor type = 0x%x\n", cpuidres.processor_type);
	printf(" max extended information = 0x%x\n", cpuidres.max_ext_info_lvl);
    if (cpuidres.proc_brand_string[0]){
        printf(" cpu name = %s\n", cpuidres.proc_brand_string);
    }

	u32 lol;

	printf("\n registers values:\n");


	printf("\t    EAX    |     EBX   |     ECX   |     EDX\n");
	for(lol = 0; lol <= cpuidres.max_sup_std_levl; lol++)
		printf("%X\t0x%X| 0x%X| 0x%X| 0x%X\n", lol, cpuidres.raw_results[lol].eax, cpuidres.raw_results[lol].ebx, cpuidres.raw_results[lol].ecx, cpuidres.raw_results[lol].edx);
	for(lol = 0x80000000; lol <= cpuidres.max_ext_info_lvl; lol++)
		printf("%X\t0x%X| 0x%X| 0x%X| 0x%X\n", lol, cpuidres.raw_results[lol].eax, cpuidres.raw_results[lol].ebx, cpuidres.raw_results[lol].ecx, cpuidres.raw_results[lol].edx); 

	unsigned char c = 0;

	while(c != 0x13){
		c = getc();
		if(c == 'g'){
			__asm__("movb $0xB6, %al");
            __asm__("outb %al, $0x43");
            __asm__("movb $0x0D, %al");
            __asm__("outb %al, $0x43");
            __asm__("movb $0x11, %al");
            __asm__("outb %al, $0x42");
            __asm__("inb $0x61, %al");
            __asm__("orb $3, %al");
            __asm__("outb %al, $0x61");
			printf("Beeep!");
		}
		//printf("0x%X, ", c);
		printf("%c", c);
	}
}

unsigned char make_bake_code_char_map[][2] = {
	[0x01] = { 0x81, 0x13 }, // ESC
	[0x02] = { 0x82, '1' },
	[0x03] = { 0x83, '2' },
	[0x04] = { 0x84, '3' },
	[0x05] = { 0x85, '4' },
	[0x06] = { 0x86, '5' },
	[0x07] = { 0x87, '6' },
	[0x08] = { 0x88, '7' },
	[0x09] = { 0x89, '8' },
	[0x0A] = { 0x8A, '9' },
	[0x0B] = { 0x8B, '0' },
	[0x0C] = { 0x8C, '-' },
	[0x0D] = { 0x8D, '=' },
	[0x0E] = { 0x8E, '\b' },
	[0x0F] = { 0x8F, '\t' },
	[0x10] = { 0x90, 'Q' },
	[0x11] = { 0x91, 'w' },
	[0x12] = { 0x92, 'e' },
	[0x13] = { 0x93, 'r' },
	[0x14] = { 0x94, 't' },
	[0x15] = { 0x95, 'y' },
	[0x16] = { 0x96, 'u' },
	[0x17] = { 0x97, 'i' },
	[0x18] = { 0x98, 'o' },
	[0x19] = { 0x99, 'p' },
	[0x1A] = { 0x9A, '[' },
	[0x1B] = { 0x9B, ']' },
	[0x1C] = { 0x9C, '\n' },
	[0x1D] = { 0x9D, ' ' }, // LEFT CTRL
	[0x1E] = { 0x9E, 'a' },
	[0x1F] = { 0x9F, 's' },
	[0x20] = { 0x80, 'd' },
	[0x21] = { 0x81, 'f' },
	[0x22] = { 0x82, 'g' },
	[0x23] = { 0x83, 'h' },
	[0x24] = { 0x84, 'j' },
	[0x25] = { 0x85, 'k' },
	[0x26] = { 0x86, 'l' },
	[0x27] = { 0x87, ' ' },
	[0x28] = { 0x88, '\'' },
	[0x29] = { 0x89, '`' },
	[0x2A] = { 0x8A, ' ' }, // LEFT SHIFT
	[0x2B] = { 0x8B, '\\' },
	[0x2C] = { 0x8C, 'z' },
	[0x2D] = { 0x8D, 'x' },
	[0x2E] = { 0x8E, 'c' },
	[0x2F] = { 0x8F, 'v' },
	[0x30] = { 0x90, 'b' },
	[0x31] = { 0x91, 'n' },
	[0x32] = { 0x92, 'm' },
	[0x33] = { 0x93, ',' },
	[0x34] = { 0x94, '.' },
	[0x35] = { 0x95, '/' },
	[0x36] = { 0x96, ' ' }, // RIGHT SHIFT
	[0x37] = { 0x97, '*' },
	[0x38] = { 0x98, ' ' }, // LEFT ALT
	[0x39] = { 0x99, ' ' },
	[0x3A] = { 0x9A, ' ' }, // CAPS LOOK
	[0x3B] = { 0x9B, ' ' }, // F1
	[0x3C] = { 0x9C, ' ' }, // F2
	[0x3D] = { 0x9D, ' ' }, // F3
	[0x3E] = { 0x9E, ' ' }, // F4
	[0x3F] = { 0x9F, ' ' }, // F5
	[0x40] = { 0x90, ' ' }, // F6
	[0x41] = { 0x90, ' ' }, // F7
	[0x42] = { 0x90, ' ' }, // F8
	[0x43] = { 0x90, ' ' }, // F9
	[0x44] = { 0x90, ' ' }, // F10
	[0x45] = { 0x90, ' ' }, // NUM LOOK
//	[0x46] = { 0x90, ' ' },
	[0x47] = { 0x90, '7' }, // 
	[0x48] = { 0x90, '8' },
	[0x49] = { 0x90, '9' },
/*	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x43] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' },
	[0x10] = { 0x90, ' ' }*/
};

unsigned char
getc()
{
	unsigned char c, a;
	for (;;){
		a = c;
		__asm__("inb %1, %%al": "=a" (c) : "i" (0x60));
		if(c != a)
			if(c == a + 0x80){
				// if(a >= 2 && a <= 0xb)
				c = make_bake_code_char_map[a][1];
				return c;
			}
	}
}

/* Convert the integer D to a string and save the string in BUF. If
    BASE is equal to 'd', interpret that D is decimal, and if BASE is
    equal to 'x', interpret that D is hexadecimal. */
extern void
itoa (char *buf, int base, int d)
{
	char *p = buf;
    char *p1, *p2;
    unsigned long ud = d;
    int divisor = 10;
	int m;

    /* If %d is specified and D is minus, put `-' in the head. */
    if ((base == 'd' || base == 'i') && d < 0) {
        *p++ = '-';
        buf++;
        ud = -d;
    } else if (base == 'x' || base == 'X')
        divisor = 16;
	else if (base == 'b')
		divisor = 2;

    /* Divide UD by DIVISOR until UD == 0. */
    do {
        int remainder = ud % divisor;
		
        *p++ = (remainder < 10) ? remainder + '0' : remainder + (base == 'x' ? 'a' : 'A') - 10;
    } while (ud /= divisor);

	if(divisor == 16 && p - buf < 8)
		while(p - buf < 8) *p++ = '0';

    /* Terminate BUF. */
    *p = 0;

    /* Reverse BUF. */
    p1 = buf;
    p2 = p - 1;
    while (p1 < p2) {
        char tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p1++;
        p2--;
    }
}

