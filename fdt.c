#include "fdt.h"

uint32_t big_to_little_endian(uint32_t big)
{
    return ((big & 0xFF000000) >> 24) |
           ((big & 0x00FF0000) >> 8) |
           ((big & 0x0000FF00) << 8) |
           ((big & 0x000000FF) << 24);
}

bool validate_fdt(void *fdt_header_addr)
{
    struct fdt_header *fdt = (struct fdt_header *)fdt_header_addr;
    if (big_to_little_endian(fdt->magic) != 0xd00dfeed)
    {
        return false;
    }
    return true;
}

struct fdt_header parse_header(void *fdt_header_addr)
{
    struct fdt_header *fdt = (struct fdt_header *)fdt_header_addr;
    struct fdt_header header;
    header.magic = big_to_little_endian(fdt->magic);
    header.totalsize = big_to_little_endian(fdt->totalsize);
    header.off_dt_struct = big_to_little_endian(fdt->off_dt_struct);
    header.off_dt_strings = big_to_little_endian(fdt->off_dt_strings);
    header.off_mem_rsvmap = big_to_little_endian(fdt->off_mem_rsvmap);
    header.version = big_to_little_endian(fdt->version);
    header.last_comp_version = big_to_little_endian(fdt->last_comp_version);
    header.boot_cpuid_phys = big_to_little_endian(fdt->boot_cpuid_phys);
    header.size_dt_strings = big_to_little_endian(fdt->size_dt_strings);
    header.size_dt_struct = big_to_little_endian(fdt->size_dt_struct);
    return header;
}