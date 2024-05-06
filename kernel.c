#include <stdint.h>
#include <stddef.h>
#include "memory.h"
 
unsigned char * uart = (unsigned char *)0x10000000;
void putchar(char c) {
	*uart = c;
	return;
}
 
void print(const char * str) {
	init_allocator();
	while(*str != '\0') {
		putchar(*str);
		str++;
	}
	return;
}
 
unsigned int kmalloc(const size_t size) {
	
}

void kmain(void) {
	
	print("Hello world!\r\n");

	while(1) {
		// Read input from the UART
		putchar(*uart);
	}
	return;
}

