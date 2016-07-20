/* */

#define UNKNOWN		1
#define IS_AMD		2
#define IS_Intel	3

extern void cpu_id();

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

// result of cpuid instruction
struct cpu_id_regs{
	u32 eax;
	u32 ebx;
	u32 ecx;
	u32 edx;
};

typedef struct cpu_id{
	u8 vendor;
	u32 max_sup_std_levl;		// maximum supported standard level
	char vendor_string[13];
	u32 processor_signature;
	u8 stepping_id; // 4 bits
	u8 model_number; // 4 bits
	u8 family_code; // 4 bits
	u8 processor_type; // 2 bits
	u8 extended_model; // 4 bits
	u8 extended_family; // 8 bits
	u8 fpu;
	u8 vme;
/*	brand_id;
	chunks;
	count;
	APIC_id;
*/	u32 max_ext_info_lvl;
	char proc_brand_string[49];		// processor brand string
	struct cpu_id_regs raw_results[16];
};

