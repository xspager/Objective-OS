#include "../../../include/ctype.h"

extern int
isalpha(int c)
{
	return(isupper(c) || islower(c));
}
