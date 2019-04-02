#include <stdint.h>

int digits(uint64_t n) {
  int digits = 1;
  while (n /= 10) {
    digits++;
  }
  return digits;
}
