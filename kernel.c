#include "stdlib.h"
#include "memory.h"
#include <stdint.h>
#include "fdt.h"

void kmain()
{
     uint64_t fdt_address = 0x40000000;
     void *fdt_header_addr = (struct fdt_header *)0x40000000;
     if (!validate_fdt(fdt_header_addr))
     {
          printf("Invalid FDT\n");
          return;
     }
     printf("FDT is valid\n");
     struct fdt_header header = parse_header(fdt_header_addr);
     printf("Memory allocator initialized \n");
     printf("Hello world! %d\n", 11);
}