#include <ctype.h>

extern int
isupper(int c)
{
	if(c >= 'A' && c <= 'Z') return 1;
	else return 0;
}
