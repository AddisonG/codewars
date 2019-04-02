#include <stdlib.h>
#include <unistd.h>

size_t bytes = 0;

void *mem_alloc(size_t size) {
  bytes += size;
  return malloc(size);
}

unsigned long long report_total_allocated(void) {
  return bytes;
}
