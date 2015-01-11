#include "aligned_free.h"

#if defined(__APPLE__) || defined(__linux__)

void aligned_free(void * pointer) {
	free(pointer);
}

#elif defined(_WIN32)

#include <crtdbg.h>

void aligned_free(void * pointer) {
	_aligned_free_dbg(pointer); // This is reduced to a call to `_aligned_free` when _DEBUG is not defined
}

#else
#error Unrecognized platform
#endif