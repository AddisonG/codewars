public class Line {
  public static String WhoIsNext(String[] names, int n) {
    int remaining = n;
    int multiplier = 1;
    
    for (int i = 0; ; i++) {
      if (names.length * multiplier >= remaining) {
        for (int person = 0; person < names.length; person++) {
          if (multiplier >= remaining) {
            return names[person];
          }
          remaining -= multiplier;
        }
      } else {
        remaining -= names.length * multiplier;
        multiplier *= 2;
      }
    }
  }
}
