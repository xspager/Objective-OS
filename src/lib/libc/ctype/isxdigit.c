#include <ctype.h>

extern int
isxdigit(int c)
{
	if((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) return 1;
	else return 0;
}
