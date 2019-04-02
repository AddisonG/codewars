public class BuyCar {
  public static int[] nbMonths(double oldValue, double newValue, int income, double depreciation) {
    double savings = 0;
    int months = 0;
    while (oldValue + savings < newValue) {
      oldValue *= (100 - depreciation) / 100;
      newValue *= (100 - depreciation) / 100;
      savings += income;
      if (months % 2 == 0) {
        depreciation += 0.5;
      }
      months++;
    }
    return new int[] {months, (int) Math.round(oldValue + savings - newValue)};
  }
}
