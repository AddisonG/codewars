#include <stdlib.h>

long bytesAllocated = 0;

unsigned long long get_currently_allocated_size() {
  return bytesAllocated;
}

void *mem_alloc(size_t size) {
  size_t *lenAndMem = malloc(sizeof(size_t) + size);
  lenAndMem[0] = size;
  bytesAllocated += size;
  return &(lenAndMem[1]);
}

void mem_free(void* mem) {
  size_t *lenAndMem = &((size_t *) mem)[-1];
  bytesAllocated -= lenAndMem[0];
  free(lenAndMem);
}
