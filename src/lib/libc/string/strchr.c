#include <string.h>

char *
strchr(const char str*, int c)
{
	char *tmp_str = str;

	while(*tmp_str++) if(*tmp_str == (char) c) return tmp_str;

	return NULL;
}
