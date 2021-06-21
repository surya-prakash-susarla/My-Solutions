import java.util.Scanner;
public class ha{
  public static void main(String[] args){
    int n;
    Scanner s = new Scanner(System.in);
    n = s.nextInt();
    System.out.print("");
    String c= s.next();
    String temper = s.nextLine();
    String[] a = temper.split("\\s+");
    for(String j:a)
      System.out.println(j);
    int k=999999;
    System.out.println(n+" "+a.length);
    for(int i=0;i<n;i++){
      if(a[i]!="@")
      for(int j=0;j<n;j++){
        if(j!=i&&a[j]!="@"){
          int temp = Integer.parseInt(a[i])-Integer.parseInt(a[j]);
          if(temp<0)
            temp=0-temp;
          if(temp<k)
            k=temp;
        }
      }
      a[i]="@";
    }
    System.out.println(k);
      }
    }
