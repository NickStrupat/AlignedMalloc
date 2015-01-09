#ifndef ALIGNED_MALLOC_H_INCLUDED
#define ALIGNED_MALLOC_H_INCLUDED

#include <stddef.h>

void * aligned_malloc(size_t size, size_t alignment);

#endif