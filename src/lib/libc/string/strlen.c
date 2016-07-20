#include <string.h>

extern size_t
strlen(const char *str)
{
	char *tmp;
	
	tmp = str;
	while(*(tmp++));

	return((size_t)(tmp - str));
}
