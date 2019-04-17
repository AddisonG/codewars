public class Kata {
  public static String encrypt(final String text, final int n) {
    String s = text;
    for (int i = 0; i < n; i++) {
      StringBuilder even = new StringBuilder(), odd = new StringBuilder();
      int j = 0;
      for (char c : s.toCharArray()) {
        if (j++ % 2 == 0) {
          even.append(c);
        } else {
          odd.append(c);
        }
      }
      s = odd.toString() + even.toString();
    }
    return s;
  }
  public static String decrypt(final String encryptedText, final int n) {
    String s = encryptedText;
    for (int i = 0; i < n; i++) {
      StringBuilder reversed = new StringBuilder();
      for (int j = 0; j < s.length() / 2; j++) {
        reversed.append(s.charAt(s.length() / 2 + j)).append(s.charAt(j));
      }
      if (s.length() % 2 == 1) {
        reversed.append(s.charAt(s.length() - 1));
      }
      s = reversed.toString();
    }
    return s;
  }
}
