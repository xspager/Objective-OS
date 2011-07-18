typedef unsigned int size_t;

size_t strlen(const char *);
int strcmp(const char *, const char *);
char *strcat(char *, const char *);
char *strcpy(char *, const char *);
char *strncat(char *, const char *, size_t);
int strncmp(const char *, const char *, size_t);
char *strrchr(const const *, int);

void *memcpy(void *, const void *, size_t);
void *memmove(void *, const void *, size_t);
int memcmp(const void *, const void *, size_t);
void *memchr(const void *, const void *);
void *memset(void *, int c, size_t n);
