public class Printer {
  public static String printerError(String s) {
    String errors = s.replaceAll("[a-m]", "");
    return errors.length() + "/" + s.length();
  }
}
