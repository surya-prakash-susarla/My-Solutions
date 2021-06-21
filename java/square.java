import java.util.Scanner;
import java.math.BigInteger;
public class square{
  public static void main(String[] args) {
    int t=0;
    Scanner s = new Scanner(System.in);
    t = s.nextInt();
    for(int o=0;o<t;o++){
      int m,n;
      m = s.nextInt();
      n = s.nextInt();
      m-=1;
      n-=1;
      int lim;
      if(m>n) lim=n;
      else lim=m;
      System.out.println(m+" "+n+" "+lim);
      BigInteger val=new BigInteger("0");
      for(int r=1;r<=lim;r++){
        BigInteger bi = new BigInteger(Integer.toString((n-(r-1))*(m-(r-1))));
        //System.out.println("BI"+bi);
        val = val.add(bi);
        val=val.add(bi.multiply(BigInteger.valueOf(r-1)));
        //System.out.println("val"+val);
        val=val.mod(BigInteger.valueOf(1000000007));
      }
      System.out.println("Case #"+(o+1)+": "+val);
    }
  }
}
