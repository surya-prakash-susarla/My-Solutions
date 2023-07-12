import java.util.*;
public class di{
  public static void main(String[] args) {

    List<Character> arr = new ArrayList<Character>();
    for(int i=0;i<5;i++)
    arr.add('a');
    System.out.println(arr);
    List<Character> ar = new ArrayList<Character>(arr);
    ar.add('z');
    System.out.println(ar+"\t0"+arr);
  }
}
