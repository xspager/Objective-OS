	#define COLUMNS                 80
	#define LINES                   25
	#define BACKGROUND              0x2
	#define FOREGROUND              0xA              
//	#define ATTRIBUTE				0x0A
	#define ATTRIBUTE				0x6E
	/* The video memory address. */
     #define VIDEO                   0xB8000

/* Colors */
	#define BLACK	0
	#define BLUE	1
	#define GREEN	2
	#define CYAN	3
	#define RED		4
	#define MAGENTA	5
	#define BROWN	6
	#define GRAY	7

	#define DARK_GRAY
	#define LIGHT_BLUE
	#define LIGHT_GREEN
	#define LIGHT_CYAN
	#define LIGHT_RED
	#define LIGHT_MAGENTA
	#define YELLOW
	#define WHITE

     /* Forward declarations. */
	 extern void init(void);
     extern void cls (void);
     extern void putchar (int c);
     extern void printf (const char *format, ...);
	 extern void clean_line(int l);
