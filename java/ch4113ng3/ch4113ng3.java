class Nerd {
  public static String nerdify(String text) {
    text = text.replaceAll("[aA]", "4");
    text = text.replaceAll("[eE]", "3");
    return text.replace("l", "1");
  }
}
