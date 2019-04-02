using namespace std;

/**
 * Counts the 1's in the binary of each number from 0 to 'end'.
 */
long long countOnesFromZero(long end) {
  long long pow = 1, exp = 0;
  while (pow <= end / 2) {
    exp++;
    pow <<= 1;
  }
  if (pow == end) {
    return pow * exp / 2 + 1;
  }
  if (pow - 1 == end) {
    return pow * exp / 2;
  }
  
  return countOnesFromZero(pow) + countOnesFromZero(end - pow) + end - pow;
}

long long countOnes(long left, long right) {
  return countOnesFromZero(right) - countOnesFromZero(left - 1);
}
