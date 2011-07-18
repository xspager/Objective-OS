/*
	TODO: TODO 
*/

#include <string.h>
#include "cpuid.h"

/* masks */
#define	INTEL_STEPING_ID_MASK		0x0000000f // 0000 0000 0000 0000 0000 1111
#define INTEL_MODEL_NUMBER_MASK		0x000000f0 // 0000 0000 0000 0000 1111 0000
#define INTEL_FAMILY_CODE_MASK		0x00000f00 // 0000 0000 0000 1111 0000 0000
#define	INTEL_PROCESSOR_TYPE_MASK	0x00003000 // 0000 0000 0011 0000 0000 0000
#define INTEL_EXTENDED_MODEL_MASK	0x000f0000 // 0000 1111 0000 0000 0000 0000
#define INTEL_EXTENDED_FAMILY_MASK	0x0ff00000 // 0000 1111 1111 0000 0000 < 12 

// "magic"? structure to organize the cpu brand string
union {
	u32 part[3];   //   32       32       32
	u8 string[13]; // 8 8 8 8  8 8 8 8  8 8 8 8  8
} brand_str;

union {
	struct cpu_id_regs regs[3];
	u8 string[48]; // max length
} cpu_str;

void do_cpuid(u32, struct cpu_id_regs *);
void fill_cpu_id_struct(struct cpu_id *);

extern void cpuid(struct cpu_id *ret)
{
	u32 sl, el;
	struct cpu_id_regs *result = ret->raw_results;

	/* standard level */
	do_cpuid(0x00000000, &result[0]); // try standard cpuid level
	ret->max_sup_std_levl = result[0].eax; // put max supported level on the struct
	for(sl = 0x00000001; sl <= ret->max_sup_std_levl; sl++) // get the rest and store
		do_cpuid(sl, &result[sl]);

	/* extended level */
	do_cpuid(0x80000000, &result[ret->max_sup_std_levl + 1]); // do the same for extended and store before the the standard on the results vector
	ret->max_ext_info_lvl = result[ret->max_sup_std_levl + 1].eax;
//	for(el = 0x80000001; el <= ret->max_ext_info_lvl; el++)
//		do_cpuid(el, &result[ret->max_sup_std_levl + el - 0x80000000]);

	fill_cpu_id_struct(ret);
}

/* fill the "cpu_id_regs" structure with the result of cpuid level "level" */
void do_cpuid(u32 level, struct cpu_id_regs *regs)
{
	__asm__("mov %0, %%eax" : : "m" (level));
	__asm__("cpuid" :
		"=a" (regs->eax),
		"=b" (regs->ebx),
		"=c" (regs->ecx),
		"=d" (regs->edx)
	);
}

/* take the raw results in cpu_id_struct and fill the rest */
void fill_cpu_id_struct(struct cpu_id *cpu_id_struct)
{
	// sort the brand string and copy to passed struct
	brand_str.part[0] = cpu_id_struct->raw_results[0].ebx;
	brand_str.part[1] = cpu_id_struct->raw_results[0].edx; // why?
	brand_str.part[2] = cpu_id_struct->raw_results[0].ecx;
	strcpy(cpu_id_struct->vendor_string, brand_str.string);

	if(!strncmp(cpu_id_struct->vendor_string, "AuthenticAMD", 12))
		cpu_id_struct->vendor = IS_AMD;
	else if(!strncmp(cpu_id_struct->vendor_string, "GenuineIntel", 12))
		cpu_id_struct->vendor = IS_Intel;
	else
		cpu_id_struct->vendor = UNKNOWN;

	if(cpu_id_struct->max_sup_std_levl >= 1){
		switch(cpu_id_struct->vendor){
			case IS_AMD:
				break;
			case IS_Intel:
				cpu_id_struct->stepping_id = cpu_id_struct->raw_results[1].eax & INTEL_STEPING_ID_MASK;
				cpu_id_struct->model_number = (cpu_id_struct->raw_results[1].eax & INTEL_MODEL_NUMBER_MASK) >> 4;
			cpu_id_struct->family_code = (cpu_id_struct->raw_results[1].eax & INTEL_FAMILY_CODE_MASK) >> 8;
				cpu_id_struct->processor_type = (cpu_id_struct->raw_results[1].eax & INTEL_PROCESSOR_TYPE_MASK) >> 12;
				break;
				cpu_id_struct->extended_model = (cpu_id_struct->raw_results[1].eax & INTEL_EXTENDED_MODEL_MASK) >> 19;
				cpu_id_struct->extended_family = (cpu_id_struct->raw_results[1].eax & INTEL_EXTENDED_FAMILY_MASK) >> 27;
		}
		cpu_id_struct->processor_signature = cpu_id_struct->raw_results[1].eax;
		
//	if(ret->max_sup_std_levl >= 4){ */// support brand string?
/*			do_cpuid(0x800000002, result[ret->max_sup_std_levl + 1 + 2]);
			do_cpuid(0x800000003, result[ret->max_sup_std_levl + 1 + 3]);
			do_cpuid(0x800000004, result[ret->max_sup_std_levl + 1 + 4]);
		}*/
	}
} 
