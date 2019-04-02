typedef union {
    struct {
        unsigned long mantissa:52;
        unsigned long exponent:11;
        unsigned long sign:1;
    } parts;
    double d;
} DoubleParts;

int exponent(double d) {
  DoubleParts dp;
  dp.d = d;
  return dp.parts.exponent;
}
