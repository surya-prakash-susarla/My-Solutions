import java.util.*;

public class tester1{
  static int m,n,total,ans;
  public static double fac(int f){
    double pr=1;
    for(int i=f;i>0;i--)
      pr*=i;
    return pr;
  }
  public static void path(int a , int b, int votea, int voteb, List<Character> y){
    if(a==0&&b==0){
        System.out.println("Possible path: "+y);
        tester1.total+=tester1.ans;
        return;
    }
    if(voteb+1<votea&&b>0){
      int bc=b-1;
      int vb=voteb+1;
      List<Character> gh = new ArrayList<Character>(y);
      gh.add('b');
      path(a,bc,votea,vb,gh);
    }
    if(a>0){
      a-=1;
      votea+=1;
      y.add('a');
      path(a,b,votea,voteb,y);
    }
  }
  public static void main(String[] args) {
    int t;
    Scanner s = new Scanner(System.in);
    t=s.nextInt();
    for(int u=1;u<=t;u++){
    tester1.m = s.nextInt();
    tester1.n = s.nextInt();
    List<Character> a = new ArrayList<Character>();
    double k = tester1.fac(tester1.m+tester1.n);
    tester1.ans = (int)tester1.fac((m))*(int)tester1.fac(n);
    tester1.path(m,n,0,0,a);
    //System.out.println(tester1.f+"\t"+k);
    double r =((double)tester1.total)/k;
    System.out.println("Case #"+u+": "+r);
    tester1.total=0;
  }
}
}
