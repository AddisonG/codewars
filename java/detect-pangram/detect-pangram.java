public class PangramChecker {
  public boolean check(String sentence) {
    int res = (1 << 26) - 1;
    for (char c : sentence.toLowerCase().toCharArray()) {
      res &= ~(1 << (c - 'a'));
    }
    return res == 0;
  }
}
