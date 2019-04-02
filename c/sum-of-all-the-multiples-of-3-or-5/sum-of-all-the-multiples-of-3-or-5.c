#include <stdio.h>
#include <stdlib.h>

int findSum (int n);

int findSum (int n) {
  double numThrees = n / 3;
  double numFives = n / 5;
  double numFifteens = n / 15;
  // intentional stripping of decimal place
  
  double threeSum = numThrees * 3.0 * ((numThrees + 1.0) / 2.0);
  double fiveSum = numFives * 5.0 * ((numFives + 1.0) / 2.0);
  double fifteensSum = numFifteens * 15.0 * ((numFifteens + 1.0) / 2.0);
  
  return threeSum + fiveSum - fifteensSum;
}
