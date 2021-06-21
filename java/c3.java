import java.util.*;
import java.math.BigInteger;
public class c3{
  public static void main(String[] args){
    int t;
    BigInteger zero = new BigInteger(String.valueOf(0));
    BigInteger one = new BigInteger(String.valueOf(1));
    Scanner s = new Scanner(System.in);
    t = s.nextInt();
    BigInteger total,temp,ba,n;
    while(t-->0){
      n = s.nextBigInteger();
      total=zero;
      ba=n;
      while(ba.compareTo(zero)>0){
        temp = s.nextBigInteger();
        total = total.add(temp);
        ba=ba.subtract(one);
      }
      if((total.mod(n)).compareTo(zero)==0){
        System.out.println("YES");
      }
      else{
        System.out.println("NO");
      }
    }
  }
}
