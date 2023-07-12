import java.math.BigInteger;
import java.util.Scanner;
public class div{
  public static void main(String[] args){
    int n;
    Scanner f = new Scanner(System.in);
    n = f.nextInt();
    BigInteger one = new BigInteger(String.valueOf("252"));
    BigInteger two = new BigInteger(String.valueOf("525"));
    BigInteger zero = new BigInteger(String.valueOf("0"));
    String s="";
    while(n-->0){
      BigInteger a;
      a = f.nextBigInteger();
      if(a.mod(one).equals(zero))
        s = "Yes ";
      else
        s = "No ";
      if(a.mod(two).equals(zero))
        s =s + "Yes";
      else
        s = s+"No";
      System.out.println(s);
    }
  }
}
