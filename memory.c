#include <stddef.h>
#include "memory.h"

void* DRAM_START = (void*)0x80000000;

struct memory_chunk* first_free_memory_chunk; 

void init_allocator() {
    first_free_memory_chunk = (struct memory_chunk*)DRAM_START;
    first_free_memory_chunk->chunk_size = 1024;
    first_free_memory_chunk->allocated_memory = 32;
    first_free_memory_chunk->status = FREE;
    first_free_memory_chunk->next = NULL;
    first_free_memory_chunk->last = NULL;
}

struct memory_chunk *request_chunk(size_t size) {
     if (size > first_free_memory_chunk->chunk_size)
    {
        struct memory_chunk* extended_chunk = extend_to_size(first_free_memory_chunk, size);
        extended_chunk->allocated_memory = size;
        return get_usable_memory_pointer(extended_chunk);
    } else if (size < first_free_memory_chunk->chunk_size)
    {
        //TODO split chunks to be smaller if needed
        
    }
}


//TODO: align to memory layout
//clear memory(who cares)
struct memory_chunk *extend_to_size(struct memory_chunk* chunk_to_extend, size_t target_size)
{
    size_t overflow = target_size - chunk_to_extend->chunk_size;
    if (chunk_to_extend->next == NULL)
    {
        //there is no next chunk just extend this one and return
        chunk_to_extend->chunk_size = target_size;
        return chunk_to_extend;
    } else if(chunk_to_extend->next->chunk_size >= overflow) {
        //next chunk is big enough and we can stop searching for space
        //we add sizeof to account for size of the strut that we are not needing anymore
        chunk_to_extend->chunk_size = chunk_to_extend->chunk_size + chunk_to_extend->next->chunk_size + sizeof(struct memory_chunk);
        //we point next to the chunk after previous next chunk
        chunk_to_extend->next = chunk_to_extend->next->next;
        return chunk_to_extend;
    } else if(chunk_to_extend->next->chunk_size < overflow) {
        //next chunk is not big enough and we have to keep searching
        struct memory_chunk* extended_next = extend_to_size(chunk_to_extend->next, overflow);
        chunk_to_extend->next = extended_next->next;
        chunk_to_extend->chunk_size= chunk_to_extend->chunk_size + extended_next->chunk_size + sizeof(struct memory_chunk);
        return chunk_to_extend;
    }
}

struct memory_chunk* cut_to_size(struct memory_chunk *chunk_to_cut, size_t target_size)
{
        
}

void* get_usable_memory_pointer(struct memory_chunk* chunk) {
    return (void*)(chunk + sizeof(struct memory_chunk));
}
