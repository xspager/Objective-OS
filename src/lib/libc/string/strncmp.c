#include <string.h>

extern int
strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;
	char *ptr1, *ptr2;
	ptr1 = str1;
	ptr2 = str2;

	for(i = 0; i <= n + 1 && (*ptr1 == *ptr2) && *ptr1 && *ptr2; i++, ptr1++, ptr2++);
/*	for(i = 0; i <= n; i++){
		if(!*ptr1) break; *//* if char pointed by str1 is null, break */
/*		if(!*ptr2) break; *//* str2, break */
/*		if(*ptr1 != *ptr2) break; *//* if diff, break */
/*		ptr1++; ptr2++;
	}
*/	return (*ptr1 - *ptr2);
}
