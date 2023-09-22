package hashtable.hashfn;

import java.util.HashSet;

class Main {
  public static void main(String[] args) {
    Integer number = new Integer(2020);
    String str = new String("2020");
    System.out.println(number.hashCode()); // 2020
    System.out.println(str.hashCode()); // 1537276

    System.out.println("ABC".hashCode()); // 64578
    System.out.println("BAC".hashCode()); // 65508
    System.out.println("CAB".hashCode()); // 66468

    Main main = new Main();
    main.hashset();
  }

  public void hashset() {
    String[] words = new String("Nothing is as easy as it looks").split(" ");

    HashSet<String> hs = new HashSet<String>();

    for (String x : words) hs.add(x);

    System.out.println(hs.size() + " distinct words detected.");
    System.out.println(hs);
  }
}

/**
  hashCode() => s.charAt(0) * 31n-1 + s.charAt(1) * 31n-2 + ... + s.charAt(n-1)
  where s is a string and n is its length

  Ex: "ABC" = 'A' * 312 + 'B' * 31 + 'C' = 65 * 312 + 66 * 31 + 67 = 64578
*/
