#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long findNb(long long volume) {
  int length = 0;
  
  while (volume >= 0) {
    if (volume == 0) {
      return length;
    }
    length++;
    volume -= pow(length, 3);
  }
  
  return -1;
}
