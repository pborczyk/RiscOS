#include "stdlib.h"
#include "memory.h"
#include <stdint.h>
#include "fdt.h"

void kmain(void *fdt_addr)
{
     if (!validate_fdt(fdt_addr))
     {
          printf("Invalid FDT\n");
          return;
     }
     printf("FDT is valid\n");
     struct fdt_header header = parse_header(fdt_addr);
     printf("Memory allocator initialized \n");
     printf("Hello world! %d\n", 11);
}