#include <string.h>

/* concatenate string dest in the end of dest */
extern char *
strcat(char *dest, const char *src)
{
	char *ret = dest;

	while(*(dest++));
	while(*src) *(dest++) = *(src++);
	*dest = '\0';

	return(ret);
}
