#include <stdio.h>
#include "../include/stdio.h"

int main()
{
	char string[] = "A long time ago...";
	char string2[] = "A long time was taken to discover that I miss everything";
	printf("The string: \"%s\" had %lu chars\n", string, strlen(string));
	printf("The string:\t\"%s\"\nand:\t\t \"\%s\"\n\tare %s", string, string2, !(strcmp(string,string2))?"the same\n":"diferent\n");
	printf("The string:\t\"%s\"\nand:\t\t \"\%s\"\n\tare %s", string2, string2, !(strcmp(string2,string2))?"the same\n":"diferent\n");
	return(0);
}
