#include <stdlib.h>
#include <stdio.h>

int find_outlier(const int *values, size_t count);

/**
 * Takes a list of integers, and returns the "odd" one out.
 * Invalid input results in undefined behaviour - There is no error handling.
 */
int find_outlier(const int *values, size_t count) {
  int outlierEvenness;
  
  int first = values[0];
  int second = values[1];
  
  // These two values are guaranteed to exist, and will be used to decide on if the outlier is odd or even.
  // The double negation converts any number except 0 into 1, and leaves 0 as 0. It's like a fast abs().
  
  if (!!(first % 2) == !!(second % 2)) {
    // Outlier is different than first (and second) value
    outlierEvenness = !(first % 2);
  } else {
    // Either first or second value is the outlier
    outlierEvenness = !!(first % 2);
  }
  
  size_t current = 0;
  while (current < count) {
    if (!!(values[current] % 2) == outlierEvenness) {
      return values[current];
    }
    current++;
  }
  
  return 0;
}
