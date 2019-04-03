namespace Triangle {
  bool isTriangle(long long a, long long b, long long c) {
    return (a + b > c) && (b + c > a) && (a + c > b);
  }
};
