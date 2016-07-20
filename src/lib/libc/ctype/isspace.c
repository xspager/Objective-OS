#include <ctype.h>

extern int
isspace(int c)
{
	if(c == ' ' || c == '\n' || c == '\r' || c == '\t') return 1;
	else return 0;
}
