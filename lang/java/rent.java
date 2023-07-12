import  java.util.Scanner;
public class rent{
  public static void main(String[] args){
    int t;
    Scanner s = new Scanner(System.in);
    t  = s.nextInt();
    for(int l=0;l<t;l++){
      int n;
      n = s.nextInt();
      int[] a = new int[n];
      for(int i=0;i<n;i++)
        a[i] = s.nextInt();
      int total=0;
      for(int h: a){
        if(h==0)
          total+=1100;
        else if (h==1&&total>0)
          total+=100;
        else if(h==1&&total<=0)
          total=0;
      }
      System.out.println(total);
    }
  }
}
