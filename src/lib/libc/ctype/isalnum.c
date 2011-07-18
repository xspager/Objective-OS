#include "../../../include/ctype.h"

extern int
isalnum(int c)
{
	return(isalpha(c) || isdigit(c));
}
