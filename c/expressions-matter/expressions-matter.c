int expression_matter(int a, int b, int c) {
  if (a == 1 && c == 1)
    return a + b + c;
  if (a == 1 || (b == 1 && a < c)) {
    return (a + b) * c;
  } else if (b == 1 || c == 1) {
    return a * (b + c);
  }
  
  return a * b * c;
}
