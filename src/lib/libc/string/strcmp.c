#include <string.h>

/* compare str1 with str2 */
extern int
strcmp(const char *str1, const char *str2)
{
	char *ptr1, *ptr2;

	ptr1 = str1;
	ptr2 = str2;

	while(*ptr1++ == *ptr2++ && *ptr1 && *ptr2);

	return(*ptr1 - *ptr2);
}
