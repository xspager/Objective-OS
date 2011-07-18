/* Test LibC */

//#include <stdio.h>
#include "../../include/string.h"
#include "../../include/ctype.h"

int
main(int argc, char *argv[])
{
	char txt1[] = "This should be a 32 chars string";
	char txt2[] = "This is another string";
	char txt3[20] = "light";
	char txt4[] = "dark";
	char c1 = 'C';
	char c2 = '%';

	printf("Testing this libc!\n\n");
	printf("The string: \"%s\", has %i chars\n", txt1, strlen(txt1));
	printf("The string: \"%s\" is %s to the string: \"%s\"\n", txt1, strcmp(txt1,txt2)?"diferent":"equal", txt2);
	printf("The string: \"%s\" is %s to the string: \"%s\"\n", txt2, strcmp(txt2,txt2)?"diferent":"equal", txt2);
	printf("\"%s\" + \"%s\" = %s\n", txt3, txt4, strcat(txt3,txt4));

	printf("The char \'%c\' is%s alphanumeric  \n\n", c1, isalpha(c1) ? " a" : "\'t");
	printf("The char \'%c\' is%s alphanumeric  \n\n", c2, isalpha(c2) ? " a" : "\'t");
	printf("%c\n", isalpha(c1));
	return(0);
}
