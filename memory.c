#include <stddef.h>
#include "memory.h"

void* DRAM_START = (void*)0x80000000;

struct memory_chunk* first_memory_header; 

void init_allocator() {
    first_memory_header = (struct memory_chunk*)DRAM_START;
    first_memory_header->chunk_size = 1024;
    first_memory_header->allocated_memory = 32;
    first_memory_header->status = FREE;
    first_memory_header->next = NULL;
    first_memory_header->last = NULL;
}

