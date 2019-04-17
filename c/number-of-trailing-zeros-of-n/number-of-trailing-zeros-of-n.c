long zeros(long n) {
  // I know that only (___*__0), and (__2*__5) can multiply to get trailing zeroes.
  // It seems that in this case, it's actually powers of 2 and 5. For example - 2*5, 4*25, 8*125, ...
  long m = 1, result = 0;
  while ((m *= 5) <= n) {
    result += n / m;
  }
  return result;
}
