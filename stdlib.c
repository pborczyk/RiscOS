#include "stdlib.h"
#include "memory.h"

void *malloc(size_t size) {
    if (size > first_free_memory_chunk->chunk_size)
    {
        
    } else if (size < first_free_memory_chunk->chunk_size)
    {
        /* code */
    }
    
    
}

void free(void * ptr){

}

void *calloc(size_t nmemb, size_t size){

}

void *realloc(void * ptr, size_t size) {

}
void *reallocarray(void * ptr, size_t nmemb, size_t size) {
    
}