/*#include <stdio.h>*/
#include "include/string.h"

#define BUFFER_SIZE 200
#define TRUE = 1
#define FALSE = 0

typedef unsigned char byte;

int main()
{
	int c;
	int i = 0,ii;
	char *buf_ptr;
	byte in;

	char *preProcKeys[] = {
		"define",
		"undef",
		"include",
		"if",
		"ifdef",
		"else",
		"endif",
		"line"
	};
	char buffer[BUFFER_SIZE];
	/*in = FALSE ;*/

	while((c = getchar()) != EOF){
		buffer[i++] = c;
		while(c != '\n' && c != EOF){
			if(i > BUFFER_SIZE) break; 
			c = getchar();
			buffer[i++] = c;
		}
		buffer[i-1] = '\0';
		buf_ptr = &buffer[0];
		/*printf("%s", buf_ptr);*/

		do{
			if(*buf_ptr == '#'){
				printf("Encontrado: %s\n", buf_ptr);
				break;
			}
		}while(buf_ptr++);

/*		while(buf_ptr){
			for(ii = 0; ii < i; ii++){
				if(*buf_ptr == preProcKeys[ii]) break;
			}
			if(ii <= sizeof(*preProcKeys)) break;
			else buf_ptr++;
		}*/
		i = 0;
	}

	return(0);
}
