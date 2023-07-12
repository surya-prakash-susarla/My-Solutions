import java.util.*;
public class hter{
  public static void main(String[] args) {
    HashMap< Integer,Integer> a = new HashMap<Integer,Integer>();
    System.out.println(a.containsKey(10));
    a.put(35,14);
    System.out.println(a.containsKey(35));
    System.out.println(a.get(35));
  }
}
