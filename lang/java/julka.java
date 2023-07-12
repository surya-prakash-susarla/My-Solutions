import java.util.Scanner;
import java.math.BigInteger;
public class julka{
  public static void main(String[] args){
    BigInteger total,m,k,n;
    Scanner s = new Scanner(System.in);
    for(int i=0;i<10;i++){
      total = s.nextBigInteger();
      m = s.nextBigInteger();
      n = total.subtract(m);
      n = n.divide(new BigInteger(String.valueOf(2)));
      k = total.subtract(n);
      System.out.println(k+"\n"+n);
    }
  }
}
