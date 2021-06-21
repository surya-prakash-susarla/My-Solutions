import java.util.*;

public class dic{
  public static void main(String[] a){
    Dictionary d= new Hashtable();
    System.out.println("Enter the numbers and keys");
    Scanner s = new Scanner(System.in);
    for(int i=0;i<5;i++){
      String si;
      int m;
      si = s.next();
      m = s.nextInt();
      d.put(si,m);
    }
    for(Enumeration e = d.keys();e.hasMoreElements();){
      System.out.println(e.nextElement());
    }
  }
}
