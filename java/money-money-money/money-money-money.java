public class Money {
  public static int calculateYears(double principal, double interest, double tax, double desired) {
    if (principal >= desired) {
      return 0;
    }
    double untaxedInterest = principal * interest;
    double taxedInterest = untaxedInterest * (1.0 - tax);
    return 1 + calculateYears(principal + taxedInterest, interest, tax, desired);
  }
}
