#include <stdlib.h>
#include "memory.h"
#include <stdint.h>
#include "lib/libfdt/libfdt.h"

void kmain(const void *fdt_addr)
{
   if (fdt_check_header(fdt_addr) != 0)
   {
      printf("Invalid device tree blob\n");
      return;
   }
   int err = fdt_check_full(fdt_addr, fdt_totalsize(fdt_addr));
   printf("FDT check full: %d\n", err);

   int root = fdt_path_offset(fdt_addr, "/");
   int addr_cells = fdt_address_cells(fdt_addr, root);
   int size_cells = fdt_size_cells(fdt_addr, root);

   int memory_node = fdt_path_offset(fdt_addr, "/memory");
   int len;
   const fdt32_t *reg = fdt_getprop(fdt_addr, memory_node, "reg", &len);
   if (!reg)
   {
      printf("Failed to read /memory reg property\n");
      return;
   }

   int region_cells = addr_cells + size_cells;
   size_t region_size = region_cells * sizeof(fdt32_t);
   int num_regions = len / region_size;
   if (num_regions > 1)
   {
      printf("Multiple memory regions not supported");
      return;
   }
   const fdt32_t *entry = reg;

   uint64_t base = 0;
   for (int j = 0; j < addr_cells; j++)
      base = (base << 32) | fdt32_to_cpu(entry[j]); // first shift does nothing as it is shifting zeros

   uint64_t size = 0;
   // we are starting iteration for the size cell where address cell one ended
   for (int j = addr_cells; j < addr_cells + size_cells; j++)
      size = (size << 32) | fdt32_to_cpu(entry[j]);

   printf("DRAM region detected, base=0x%x size=0x%x\n", base, size);
}