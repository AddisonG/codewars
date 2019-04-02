import java.math.BigInteger;

public class SumFct {
  private static final BigInteger ONE = BigInteger.ONE;
  private static final BigInteger ZERO = BigInteger.ZERO;
  
  public static BigInteger perimeter(BigInteger n) {
    BigInteger res = ONE, prev = ZERO, curr = ONE, temp;
    while (! n.equals(ZERO)) {
      temp = curr;
      curr = curr.add(prev);
      prev = temp;
      res = res.add(curr);
      
      n = n.subtract(ONE);
    }
    return res.multiply(new BigInteger("4"));
  }
}
