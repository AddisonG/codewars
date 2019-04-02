#include <stdio.h>
#include <stdlib.h>

long long gcdi(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  
  while (a != b) {
    if (a > b) {
      a -= b;
    } else {
      b -= a;
    }
  }
  
  return a;
}

long long lcmu(long long a, long long b) {
  return abs(a * b / gcdi(a, b));
}
long long som(long long a, long long b) {
  return a + b;
}
long long maxi(long long a, long long b) {
  return a > b ? a : b;
}
long long mini(long long a, long long b) {
  return a < b ? a : b;
}

typedef long long (*generic_func_t) (long long, long long);

long long* operArray(generic_func_t func, long long* input, int size, long long init) {
  if (size == 0) {
    return NULL;
  }
  
  long long* result = malloc(sizeof(long long) * size);
  result[0] = func(init, input[0]);
  
  for (int i = 1; i < size; i++) {
    result[i] = func(result[i - 1], input[i]);
  }
  
  return result;
}
