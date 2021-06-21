import java.math.BigInteger;
import java.util.*;

public class by{
  static int m1=2,m2=3,m3=4;
  public static HashMap<BigInteger,BigInteger> f = new HashMap<BigInteger,BigInteger>();
  public static BigInteger max(BigInteger a){
    if(f.containsKey(a))  return by.f.get(a);
    BigInteger n1 = a.divide(new BigInteger(String.valueOf(by.m1)));
    n1 = max(n1);
    BigInteger n2 = a.divide(new BigInteger(String.valueOf(by.m2)));
    n2 = max(n2);
    BigInteger n3 = a.divide(new BigInteger(String.valueOf(by.m3)));
    n3 = max(n3);
    BigInteger total = n1.add(n2);
    total = total.add(n3);
    BigInteger win;
    if(total.compareTo(a)==1) win=total;
    else win=a;
    if(!by.f.containsKey(a)) by.f.put(a,win);
    return win;
  }
  public static void main(String[] args) {
    int t;
    Scanner s = new Scanner(System.in);
    t = s.nextInt();
    f.put(new BigInteger(String.valueOf(0)),new BigInteger(String.valueOf(0)));
    for(int u=0;u<t;u++){
      BigInteger n;
      n = s.nextBigInteger();
      System.out.println(by.max(n));
    }
  }
}
