#ifndef ALIGNED_MALLOC_H_INCLUDED
#define ALIGNED_MALLOC_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

void * aligned_malloc(size_t size, size_t alignment);

#ifdef __cplusplus
}
#endif

#endif