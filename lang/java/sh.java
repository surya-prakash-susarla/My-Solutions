import java.util.Scanner;
public class sh{
  static int[] a;
  static int n;
    static int high(int st){
      int temp=a[st];
      int loc=st;
      for(int i=st+1; i<n;i++){
        if(a[i]>temp){
          loc=i;
          temp=a[i];
        }
      }
      if(loc==st)
        return 0;
      else
        return loc;
    }
    public static void main(String[] args){
      int t;
      Scanner s = new Scanner(System.in);
      t = s.nextInt();
      for(int i=0;i<t;i++){
         n = s.nextInt();
         a = new int[n];
         for(int l=0;l<n;l++)
           a[l] = s.nextInt();
         int ex=0,pr=0,co=0;
         o:
         for(int u=0;u<n;u++){
           int lim = high(u);
          // System.out.println("lim="+lim+"\tu="+u);
           if(lim==0)
            break o;
           for(int j=u;j<lim;j++){
             ex = ex+a[j];
             co=co+1;
           }
           pr = pr+ ((a[lim]*co)-ex);
           u=lim;
           ex=0;
           co=0;
        //   System.out.println(pr+"\t"+lim);
         }
         System.out.println(pr);
      }
    }
}
