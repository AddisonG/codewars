import java.util.Set;
import java.util.TreeSet;

public class Hamming {
  
  private static Set<Long> hammingSet = new TreeSet<>();
  
  public static long hamming(int n) {
    populateHammingSet(1);
    hammingSet.add(1L);
    
    int count = 0;
    for (Long hamming : hammingSet) {
      count++;
      if (count == n) {
        return hamming;
      }
    }
    return 0;
  }
  
  private static void populateHammingSet(long number) {
    if (hammingSet.contains(number)) {
      return;
    }
    
    hammingSet.add(number);
    
    if (number > 10000000000L) {
      return;
    }
    
    populateHammingSet(number * 2);
    populateHammingSet(number * 3);
    populateHammingSet(number * 5);
  }
}
