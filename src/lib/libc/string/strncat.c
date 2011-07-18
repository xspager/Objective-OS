#include <string.h>

extern char *
strncat(char *dest, const char *src, size_t n)
{
	char *tmp;
	size_t i;

	tmp = dest;
	while(*(tmp++));
	for(i = 0; i <= n && (*src); i++) *(dest++) = *(src++);
	*dest = '\0';

	return(tmp);
}
