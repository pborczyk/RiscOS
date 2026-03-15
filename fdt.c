#include "fdt.h"



uint32_t big_to_little_endian(uint32_t big) {
    return ((big & 0xFF000000) >> 24) |
           ((big & 0x00FF0000) >> 8)  |
           ((big & 0x0000FF00) << 8)  |
           ((big & 0x000000FF) << 24);
}