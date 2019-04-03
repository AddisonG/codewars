#include <math.h>

bool is_square(int n) {
  return int(sqrt(n)) * int(sqrt(n)) == n;
}
