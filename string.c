#include "string.h"
int strlen(char *str)
{
    int size = 0;
    int strpos = 0;
    while (str[strpos] != '\0')
    {
        size++;
        strpos++;
    }
    return size;
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
void *memmmove(void *destination, const void *source, size_t num)
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