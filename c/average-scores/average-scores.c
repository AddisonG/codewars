#include <stddef.h>
#include <stdio.h>

int add(const int *values, size_t count) {
  if (count == 1) {
    return values[0];
  }
  return values[0] + add(&(values[1]), count - 1);
}

int average(const int *values, size_t count) {
  return (add(values, count) / (float) count) + 0.5;
}
