#include <stdio.h>

#define BUFFER_SIZE 100

void getLine(char *, int);
void parseLine(char *);

int main(int argc, char *argv[])
{
    char buffer[BUFFER_SIZE];
    //char buffer[] = "#include <stdio.h>";

    getLine(buffer,BUFFER_SIZE);
	printf("%s", &buffer[0]);
	parseLine(buffer);
	return(0);
}

void getLine(char *buf, int lim)
{
	int c,i = 0;

	c = getchar();
	while((c != EOF) && (c != '\n') && (i < lim)){
		buf[i++] = c;
		c = getchar();
	}
	//printf("Lidos %i caracteres\n", i);
	buf[i] = '\0';

	//printf("Texto: %s\n",buf);
}

void parseLine(char *linha)
{
	int i = 0;

	

	while(linha[i]){
		switch(linha[i])
	}
}
