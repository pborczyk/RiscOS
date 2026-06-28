#include "stdlib.h"
#include "string.h"

volatile uint8_t *uart = (uint8_t *)0x09000000;
void putchar(char c)
{
  *uart = c;
  return;
}

void print(const char *str)
{
  while (*str != '\0')
  {
    putchar(*str);
    str++;
  }
  return;
}

char *itoa(int value, char *str, int base)
{
  char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  if (base > 16)
  {
    return NULL;
  }
  int str_pos = 0;
  while (value > 0)
  {
    str[str_pos] = digits[value % base];
    value = value / base;
    str_pos++;
  }
  str[str_pos] = '\0';
  strrev(str);
  return str;
}

char *utoa(unsigned int value, char *str, int base)
{
  char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  if (base > 16)
  {
    return NULL;
  }
  int str_pos = 0;
  while (value > 0)
  {
    str[str_pos] = digits[value % base];
    value = value / base;
    str_pos++;
  }
  str[str_pos] = '\0';
  strrev(str);
  return str;
}

void printf(const char *format, ...)
{
  __builtin_va_list argp;
  __builtin_va_start(argp, format);
  char buf[512];
  int format_pos = 0;
  int formatting_mode = 0;
  int num;
  int character;
  char *string;
  while (format[format_pos] != '\0')
  {
    if (formatting_mode)
    {
      switch (format[format_pos])
      {
      case 'd':
      case 'i':
        num = __builtin_va_arg(argp, int);
        itoa(num, buf, 10);
        print(buf);
        break;
      // case 'f':
      //   __builtin_va_arg(argp, double);
      //   break;
      case 'c':
        character = __builtin_va_arg(argp, int);
        putchar(character);
        break;
      case 's':
        string = __builtin_va_arg(argp, char *);
        print(string);
        break;
      case 'x':
        num = __builtin_va_arg(argp, uint32_t);
        utoa(num, buf, 16);
        print(buf);
        break;
      case '%':
        putchar('%');
        break;
      default:
        break;
      }
      formatting_mode = 0;
    }
    else
    {
      if (format[format_pos] == '%')
      {
        formatting_mode = 1;
      }
      else
      {
        putchar(format[format_pos]);
      }
    }
    format_pos++;
  }
  __builtin_va_end(argp);
}

int index_of_char_(char element, char* array, size_t array_size) {
  int i = 0;
  while (i < array_size)
  {
    if(array[i] == element) {
      return i;
    }
    i++;
  }
  return -1;
}

char toupper(char c) {
  if(c >= 'a' && c <= 'z') return c - 32;
  return c;
}

unsigned long strtoul(const char *str, char **first_unknown_char, int base)
{
    char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    unsigned long result = 0;
    for(unsigned int i = 0; str[i] != '\0'; i++) {
      int index = index_of_char_(toupper(str[i]), digits, 16);
      if(index < 0 || index >= base) {
        *first_unknown_char = str + i;
        return 0;
      }
      result = result * base + index;
    }
    return result;
}