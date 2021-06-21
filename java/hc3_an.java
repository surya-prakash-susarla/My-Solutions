import java.util.Scanner;
class val{
  public int v;
  public int po;
  void calc(int k){
    po = po+k;
    while(po>=hc3_an.n)
      po-=hc3_an.n;
  }
}
public class hc3_an{
  public static int n;
  public static void main(String[] args){
    Scanner s = new Scanner(System.in);
    int k,q;
    n = s.nextInt();
    k = s.nextInt();
    q = s.nextInt();
    val[] a = new val[n];
    for(int i=0;i<n;i++){
      a[i]=new val();
      a[i].v = s.nextInt();
      a[i].po = i;
    }
    //for(val i:a)
    //    System.out.println(i.v+" "+i.po);
    for(val i: a)
      i.calc(k);
    int[] qe = new int[q];
    for(int i=0;i<q;i++)
      qe[i]= s.nextInt();
      //for(val i :a)
      //System.out.println(i.v+" "+i.po);
    for(int i:qe)
      for(val j: a)
        if(j.po==i)
          System.out.println(j.v);
  }
}
