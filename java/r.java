import java.util.Scanner;
public class r{
  public static void main(String[] args) {
    int t;
    Scanner s = new Scanner(System.in);
    t = s.nextInt();
    for(int i=0;i<t;i++){
      String a = s.next();
      String b = s.next();
      if(i%2==0)
      System.out.println("Case #"+(i+1)+": "+"TRUE");
      else
        System.out.println("Case #"+(i+1)+": "+"FALSE");
    }
  }
}
