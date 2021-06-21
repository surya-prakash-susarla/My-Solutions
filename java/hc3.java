import java.util.Scanner;
public class hc3{
  public static void main(String[] args){
    Scanner in= new Scanner(System.in);
    int n,k,q;
    System.out.println("Enter the values of n, p and q");
    n = in.nextInt();
    k = in.nextInt();
    q = in.nextInt();
    System.out.println("Enter the values of the array");
    int[] a = new int[n];
    for( int i=0 ;i<n ;i++)
      a[i]=in.nextInt();
    for(int j=0;j<k;j++){
        int temp=a[0];
        for(int i=1;i<=n-1;i++){
          int s = a[i];
          a[i]=temp;
          temp=s;
        }
        a[0]=temp;
    }
  for(int i:a)
    System.out.println(i);
    int[] qe = new int[q];
    for(int i : qe)
      i = in.nextInt();
    for(int i:qe)
      System.out.println(a[i]);
}
}
