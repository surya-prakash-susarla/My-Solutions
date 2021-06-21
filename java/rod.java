import java.util.*;
public class rod{
  public static int max(int a , int b){
    if ( a>b )  return a;
    else return b;
  }
  public static int cal(int req, HashMap<Integer,Integer> a){
    if(req==0)  return 0;
    if(a.containsKey(req))  return a.get(req);
    int q=-123;
    for(int i=1;i<req;i++)
      q = rod.max(q, a.get(i)+rod.cal(req-1,a));
    a.put(new Integer(req) ,new Integer(q));
    System.out.println("The new length "+req+" is "+q);
    return q;
  }
  public static void main(String[] args) {
    System.out.println("enter the sizes and the prices of the cuts");
    HashMap < Integer,Integer> a = new HashMap< Integer,Integer>();
    int c = 0;
    Scanner s = new Scanner(System.in);
    while(c!=-1){
      int x,y;
      x = s.nextInt();
      y = s.nextInt();
      a.put(new Integer(x),new Integer(y));
      System.out.println("To end press -1");
      c = s.nextInt();
    }
    int req;
    System.out.println("Enter the size of the rod to be cut");
    req = s.nextInt();
    int val = rod.cal(req,a);
    System.out.println("The maximum price of "+req+" length is "+val);
  }
}
