#include <stdio.h>
#include <stdlib.h>

// Haha, cute. Took a few seconds after reading the clue.
int get_num(long number) {
  int holes = 0;
  
  while (number) {
    int digit = number % 10;
    number /= 10;
    
    if (digit == 0 || digit == 6 || digit == 9) {
      holes++;
    } else if (digit == 8) {
      holes += 2;
    }
  }
  
  return holes;
}
