import java.util.List;

public class BinaryArrayToNumber {
  public static int ConvertBinaryArrayToInt(List<Integer> binary) {
    int result = 0;
    for (Integer x : binary) {
      result <<= 1;
      result |= x;
    }
    return result;
  }
}
