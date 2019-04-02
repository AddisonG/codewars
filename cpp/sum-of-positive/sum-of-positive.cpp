#include <vector>

int positive_sum (const std::vector<int> arr) {
  int sum = 0;
  for (int x : arr) {
    sum += (x > 0) ? x : 0;
  }
  return sum;
}
