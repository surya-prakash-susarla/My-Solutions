import java.util.Scanner;
public class hc2{
  public static void main(String[] args){
    String s;
    Scanner inp = new Scanner(System.in);
    s = inp.nextLine();
    int a = Integer.parseInt(s.substring(0,2));
    String temp = s.substring(8,s.length());
    String ans="";
    System.out.println(a+temp);
    if(temp.equals("PM")&&a!=12){
      System.out.println("In if loop");
      a=a+12;
      System.out.println(a);
      ans = Integer.toString(a);
      System.out.println(ans);
    }
    else if(temp.equals("AM")&&a==12)
      ans="00";
    else
      ans=s.substring(0,2);
    temp=s.substring(2,s.length());
    System.out.println("temp="+temp);
    ans = ans.concat(temp);
    System.out.println(ans);
  }
}
