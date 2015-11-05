# AlignedMalloc
A pair of cross-platform C functions to allocate and free aligned memory

    void * aligned_malloc(size_t size, size_t alignment);
    void aligned_free(void * pointer);

### Usage

Use the two functions in place of `malloc` and `free` when you need aligned memory.

### Supported platforms

Mac OS X and Linux are supported by calling `posix_memalign`, Windows by calling `_aligned_malloc` (`_aligned_malloc_dbg` while compiling with `_DEBUG`). Outside of those platforms, determined with the `__APPLE__`, `__linux__`, and `_WIN32` macro definitions respectively, the function will use a custom implementation. This custom implementation uses `malloc` under the hood, but returns a pointer to an aligned memory address within a larger memory block. It stores the pointer returned by malloc in the extra space before the aligned memory for `aligned_free` to access later. This is necessary to ensure the memory can be freed correctly.