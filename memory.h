#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>
struct memory_chunk;

extern void* DRAM_START;
extern struct memory_chunk* first_free_memory_chunk; 
void init_allocator();
//Extends chunk by combining it with next free chunk
struct memory_chunk* extend_to_size(struct memory_chunk* chunk_to_extend, size_t target_size);
//Cuts to size by splitting chunk into two
struct memory_chunk* cut_to_size(struct memory_chunk* chunk_to_cut, size_t target_size);
void* get_usable_memory_pointer(struct memory_chunk* chunk);
enum STATUS {
    FREE,
    USED
};
void*   kmalloc(size_t size);
void    kfree(void * ptr);
void*   kcalloc(size_t nmemb, size_t size);
void*   krealloc(void * ptr, size_t size);
void*   kreallocarray(void * ptr, size_t nmemb, size_t size);

struct memory_chunk
{
    size_t chunk_size;
    size_t allocated_memory;
    enum STATUS status;
    struct memory_chunk* next;
    struct memory_chunk* last;
};



#endif /* MEMORY_H */