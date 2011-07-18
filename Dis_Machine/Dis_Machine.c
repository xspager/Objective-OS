typedef unsigned char byte;

union reg{
	long long l;
	long w;
	byte a;
	byte b;
	byte c;
	byte d;
	byte e;
	byte f;
	byte g;
	byte h;
}

reg src1;
reg src2;
reg dest;

struct Alt{
	int nsend;
	int nrecv;
	struct{
		Chanel* c;
		void* val;
	} entry[];
};

/* ADD */
void addb(){
	byte b;
	dest.a = src1.a + src2.a;
}

void addf(){
	dest.f = src1.f + src2.f;
}

void addw(){
	dest.w = src1.w + src2.w; 
}

/* ALT */

