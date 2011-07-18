#include "crt.h"
	
	static int xpos, ypos;
	static volatile unsigned char *video;

extern void
	init(void)
	{
		video = (unsigned char *) VIDEO;
		cls();
	}
	 
	/* Clean the screen*/
extern void
	cls(void)
	{
		int i;

		for(i = 0; i < LINES; i++) clean_line(i);
		xpos = 0; ypos = 0;
	}

	/* Mover cursor to x,y */
extern void
	cursor(int x, int y)
	{
		
	}

	/* clean the line l */
extern void
	clean_line(int l)
	{
		int i;
/*		unsigned char *line_ptr;

		line_ptr = video + (((COLUMNS - 1) * 2) * l);
		for(i = 0; i <= (COLUMNS - 1) * 2; i++) *(line_ptr + i) = '\0';
*/
		unsigned short *line_ptr;
		line_ptr = (unsigned short *) video + COLUMNS * l;
		for(i = 0; i < COLUMNS; i++) *(line_ptr + i) = ' ' | (ATTRIBUTE << 8);
	}

	 /* scrool the screen */
extern void
	scrool()
	{
		int i;
		unsigned short *wchar;

		wchar = (unsigned short *) video;

		for(i = 0; i <= (LINES * (COLUMNS - 1)); i++){
			*(wchar + i) = *(wchar + i + COLUMNS);
		}
		clean_line(LINES - 1);
	 }

	/* Put the character C on the screen. */
extern void
	putchar(int c)
	{
		int tab, i;

		if(c == '\r'){
			clean_line(ypos); // should?
			xpos = 0;
			return;
		}
		if(c == '\t'){
			tab = 8 - (xpos - ((xpos / 8) * 8));
			
			for(i = 0; i <= tab; i++) putchar(' ');
			//xpos += tab;
			return;
		}
		if(c == '\n'){
			newline:
			if(ypos >= LINES - 1) scrool();
			else ++ypos;
			xpos = 0;
			return;
		}
		
		unsigned short *wchar;
		wchar = (unsigned short *) video;
		wchar += xpos + (ypos * COLUMNS);
		*wchar = (unsigned short) (c & 0xFF) | (ATTRIBUTE << 8);

/*		long i;
		for(i = 0; i < 50000; i++);
*/
		if(xpos >= COLUMNS) goto newline;
		else xpos++;
	}

	/* Format a string and print it on the screen, just like the libc
        function printf. */
extern void
	printf (const char *format, ...)
	{
		char **arg = (char **) &format;
		int c;
		char buf[64];

		arg++;

		while ((c = *format++) != 0){
			if (c != '%') putchar (c);
			else{
				char *p;

				c = *format++;
				switch (c){
					case 'd':
					case 'i':
					case 'u':
					case 'X':
					case 'x':
					case 'b':
						itoa (buf, c, *((int *) arg++));
						p = buf;
						goto string;
					break;
					case 's':
						p = *arg++;
						if(!p) p = "(null)";
						string:
						while(*p) putchar(*p++);
					break;
					default:
						putchar (*((int *) arg++));
					break;
				}
			}
		}
	}

extern void
	print_xy()
	{
		printf("\nx = %d, y = %d\n", xpos, ypos);
	}
