import java.util.Scanner;
public class matsp{
  public static void main(String[] arsgs){
    int n;
    System.out.println("Enter the size of the matrix");
    Scanner se = new Scanner(System.in);
    n = se.nextInt();
    int[][] a = new int[n][n];
    System.out.println("Enter the contents of the matrix");
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        a[i][j] = se.nextInt();
    int s=0,e=n-1;
    System.out.println("n/2="+n/2);
    while(s<=n/2&&e>=n/2){
        for(int j=s;j<e;j++)
          System.out.println(a[s][j]);
        for(int i=s;i<e;i++)
          System.out.println(a[i][e]);
        for(int j=e;j>s;j--)
          System.out.println(a[e][j]);
        for(int i=e;i>s;i--)
          System.out.println(a[i][s]);
      if(s==e)
        System.out.println(a[s][e]);
      s+=1;e-=1;
    }
  }
}
