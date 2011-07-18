#include <ctype.h>

extern int
islower(int c)
{
	if(c >= 'a' && c <= 'z') return 1;
	else return 0;
}
