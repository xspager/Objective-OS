#include "../../../include/ctype.h"

extern int
isascii(int c)
{
	if(c >= 0 && c <= 0xEF) return 1;
	else return 0;
}
