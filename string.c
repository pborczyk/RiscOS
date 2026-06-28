#include "string.h"
size_t strlen(char *str)
{
    size_t size = 0;
    size_t strpos = 0;
    while (str[strpos] != '\0')
    {
        size++;
        strpos++;
    }
    return size;
}

size_t strnlen(const char *s, size_t maxlen)
{
    size_t len = 0;
    while (len < maxlen && s[len] != '\0')
        len++;
    return len;
}

void strrev(char *str)
{
    // we swap till the two pointers meet or pass by each other, this way we will reverse string in place
    char *begging_pointer = str;
    char *end_pointer = str + strlen(str) - 1;
    char tmp;
    while (begging_pointer != end_pointer && end_pointer > begging_pointer)
    {
        tmp = *begging_pointer;
        *begging_pointer = *end_pointer;
        *end_pointer = tmp;
        begging_pointer++;
        end_pointer--;
    }
}
void *memset(void *ptr, int value, size_t num)
{
    int *p = (int *)ptr;
    for (size_t i = 0; i < num; i++)
    {
        p[i] = value;
    }
    return ptr;
}
void *memcpy(void *destination, const void *source, size_t num)
{
    char *d = (char *)destination;
    const char *s = (const char *)source;

    for (size_t i = 0; i < num; i++)
    {
        d[i] = s[i]; // Simple forward copy
    }
    return destination;
}
int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    unsigned char *ucptr1 = (unsigned char *)ptr1;
    unsigned char *ucptr2 = (unsigned char *)ptr2;
    for (size_t i = 0; i < num; i++)
    {
        if (ucptr1[i] < ucptr2[i])
        {
            return -1;
        }
        else if (ucptr1[i] > ucptr2[i])
        {
            return 1;
        }
    }
    return 0;
}

void *memmove(void *destination, const void *source, size_t num)
{
    unsigned char *d = (unsigned char *)destination;
    const unsigned char *s = (const unsigned char *)source;
    if (d == s || num == 0)
    {
        return destination; // No need to move if source and destination are the same or num is zero
    }

    if (d < s)
    {
        // Copy forward
        for (size_t i = 0; i < num; i++)
        {
            d[i] = s[i];
        }
    }
    else if (d > s)
    {
        // Copy backward
        for (size_t i = num; i > 0; i--)
        {
            d[i - 1] = s[i - 1];
        }
    }
    return destination;
}
void *memchr(const void *ptr, int value, size_t num)
{
    unsigned char char_val = value;
    const unsigned char* char_start = ptr;
    for(size_t i = 0; i < num; i++) {
        if(char_start[i] == char_val) {
            return (void*)(char_start + i);
        }
    }
    return NULL;
}
char *strchr(const char *str, int c)
{
    unsigned int i = 0;
    while (str[i] != '\0') {
        if(str[i] == (char)c) {
            return (char*)(str + i);
        }
        i++;
    }
    if(c == '\0') return (char*)(str + i);
    return NULL;
}
char *strrchr(const char *str, int c)
{
    unsigned int i = 0;
    char* last_occurence = NULL;
    while (str[i] != '\0') {
        if(str[i] == (char)c) {
            last_occurence = (char*)(str + i);
        }
        i++;
    }
    if(c == '\0') return (char*)(str + i);
    return last_occurence;
}