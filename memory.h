#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>
struct memory_chunk;

extern void* DRAM_START;
extern struct memory_chunk* first_memory_header; 
void init_allocator();

enum STATUS {
    FREE,
    USED
};

struct memory_chunk
{
    size_t chunk_size;
    size_t allocated_memory;
    enum STATUS status;
    struct memory_chunk* next;
    struct memory_chunk* last;
};



#endif /* MEMORY_H */