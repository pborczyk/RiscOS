#include "stdlib.h"
#include "string.h"

unsigned char *uart = (unsigned char *)0x10000000;
void putchar(char c) {
  *uart = c;
  return;
}

void print(const char *str) {
  while (*str != '\0') {
    putchar(*str);
    str++;
  }
  return;
}

char *itoa(int value, char *str, int base) {
  char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  if (base > 16) {
    return NULL;
  }
  int str_pos = 0;
  while (value > 0) {
    str[str_pos] = digits[value % base];
    value = value / base;
    str_pos++;
  }
  str[str_pos] = '\0';
  strrev(str);
  return str;
}

void printf(char *format, ...) {
  va_list argp;
  va_start(argp, format);
  char buf[512];
  int format_pos = 0;
  int formatting_mode = 0;
  int num;
  int character;
  char* string;
  while (format[format_pos] != '\0') {
    if (formatting_mode) {
      switch (format[format_pos]) {
      case 'd':
      case 'i':
        num = va_arg(argp, int);
        itoa(num, buf, 10);
        print(buf);
        break;
      case 'f':
        va_arg(argp, double);
        break;
      case 'c':
        character = va_arg(argp, int);
        putchar(character);
        break;
      case 's':
        string = va_arg(argp, char *);
        print(string);
        break;
      case '%':
        putchar('%');
        break;
      default:
        break;
      }
      formatting_mode = 0;
    } else {
      if (format[format_pos] == '%') {
        formatting_mode = 1;
      } else {
        putchar(format[format_pos]);
      }
    }
    format_pos++;
  }
  va_end(argp);
}