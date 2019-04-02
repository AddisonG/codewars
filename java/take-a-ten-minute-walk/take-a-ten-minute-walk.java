public class TenMinWalk {
  public static boolean isValid(char[] walk) {
    if (walk.length != 10) {
      return false;
    }
    int vertical = 0;
    int horizontal = 0;
    for (char dir : walk) {
      switch(dir) {
        case 'n':
          vertical++;
          break;
        case 's':
          vertical--;
          break;
        case 'e':
          horizontal++;
          break;
        case 'w':
          horizontal--;
        }
    }
    return vertical == 0 && horizontal == 0;
  }
}
