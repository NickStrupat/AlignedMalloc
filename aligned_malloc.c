#include "aligned_malloc.h"

#if defined(__APPLE__) || defined(__linux__)

#include <stdlib.h>

void * aligned_malloc(size_t size, size_t alignment) {
	void * pointer;
	posix_memalign(&pointer, alignment, size);
	return pointer;
}

#elif defined(_WIN32)

#include <crtdbg.h>

void * aligned_malloc(size_t size, size_t alignment) {
	return _aligned_malloc_dbg(size, alignment); // This is reduced to a call to `_aligned_malloc` when _DEBUG is not defined
}

#else
#error Unrecognized platform
#endif