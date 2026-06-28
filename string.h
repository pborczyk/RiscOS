#ifndef STRING_H
#define STRING_H
#include <stddef.h>
size_t strlen(char *str);
size_t strnlen(const char *s, size_t maxlen);

void strrev(char *str);

void *memset(void *ptr, int value, size_t num);
void *memcpy(void *destination, const void *source, size_t num);
int memcmp(const void *ptr1, const void *ptr2, size_t num);
void *memmove(void *destination, const void *source, size_t num);
void *memchr(const void *ptr, int value, size_t num);
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);

#endif /* STRING_H */