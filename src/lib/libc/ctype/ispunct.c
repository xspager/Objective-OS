#include <ctype.h>

extern int
ispunct(int c)
{
	if(isprint(c)){
		if(!isalpha(c))
			if(!isdigit(c)) return 1;
			else return 0;
		else return 0;
	}
	else return 0;
}
