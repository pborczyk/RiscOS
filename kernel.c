#include "stdlib.h"
#include "memory.h"

void kmain(void) {
     init_allocator();
     printf("Memory allocator initialized");
     printf("Hello world! %d\n", 11);
}