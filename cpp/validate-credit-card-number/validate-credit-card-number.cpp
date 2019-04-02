class Kata {
  public: static bool validate(long long int n) {
    int l = 0, v = 0;
    do {
      int d = n % 10;
      v += (l++ % 2) ? ((d > 4) ? d * 2 - 9: d * 2) : d;
    } while ((n /= 10) >= 1);
    return l < 17 && ! (v % 10);
  }
};
