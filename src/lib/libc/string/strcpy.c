#include <string.h>

/* copy the string src to the string dest and return a point to dest */
char *
strcpy(char *dest, const char *src)
{
	char *tmp;

	tmp = dest;
	while(*src) *(tmp++) = *(src++);

	return(dest);
}
