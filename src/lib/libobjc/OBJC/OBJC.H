/* objc.h */

typedef unsigned char BOOL;

#define YES	(BOOL)1
#define NO	(BOOL)0

/* Accessing Selectors */
const char *sel_getName(SEL aSelector);
BOOL sel_isMapped(SEL aSelector);
SEL sel_registerName(const char *str);
SEL sel_getUid(const char *str);

