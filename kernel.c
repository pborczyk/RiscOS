#include "stdlib.h"
#include "memory.h"
#include <stdint.h>
#include "lib/libfdt/libfdt.h"


void kmain(void *fdt_addr)
{
     if (fdt_check_header(fdt_addr) != 0) {
        printf("Invalid device tree blob\n");
        return;
     }
     printf("Device tree blob is valid\n");
     
     printf("Hello world! %d\n", 11);
}