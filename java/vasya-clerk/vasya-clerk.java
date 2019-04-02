public class Line {
  public static String Tickets(int[] line) {
    int $25 = 0, $50 = 0;
    for (int i : line) {
      if ((i == 50 && $25 == 0) || (i == 100 && !($25 > 2 || ($50 > 0 && $25 > 0))) ) {
        return "NO";
      } else if (i == 25) {
        $25++;
      } else if (i == 50) {
        $25--;
        $50++;
      } else if (i == 100 && $50 > 0) {
        $50--;
        $25--;
      } else if (i == 100) {
        $25 -= 3;
      }
    }
    return "YES";
  }
}
