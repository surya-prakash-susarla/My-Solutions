import java.util.*;
public class vector{
  public static void main(String[] ars){
    Vector v = new Vector();
    System.out.println("Etner any 5 strings");
    for(int i=0;i<5;i++){
      String temp;
      Scanner s = new Scanner(System.in);
      temp = s.next();
      v.addElement(temp);
    }

    for(int i=0;i<5;i++){
      System.out.println(v.elementAt(i));
    }

    System.out.println(v.size());
  }
}
