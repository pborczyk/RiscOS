#ifndef FDT_H
#define FDT_H

#include <stdint.h>
#include <stdbool.h>

struct fdt_header
{
    uint32_t magic;
    uint32_t totalsize;
    uint32_t off_dt_struct;
    uint32_t off_dt_strings;
    uint32_t off_mem_rsvmap;
    uint32_t version;
    uint32_t last_comp_version;
    uint32_t boot_cpuid_phys;
    uint32_t size_dt_strings;
    uint32_t size_dt_struct;
};

bool validate_fdt(void *fdt_header_addr);

struct fdt_header parse_header(void *fdt_headerd_addr);

#endif /* FDT_H */