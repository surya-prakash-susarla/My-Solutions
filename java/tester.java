import java.util.*;
class counter{
  HashMap<Character,Integer> a ;
  int val;
  counter(String s){
    a = new HashMap<Character,Integer>();
    char[] c = s.toCharArray();
    for(char f:c){
      if(Character.isWhitespace(f)){
        //System.out.println(f);
        continue;
      }
      Character g = new Character(f);
      if(a.containsKey(g)){
        int val=a.get(g);
        a.put(g,val+1);
      }
      else
        a.put(g,1);
    }
    val = a.size();
  }
}
public class tester{
  public static void main(String[] args) {
    int t;
    Scanner s = new Scanner(System.in);
    t = s.nextInt();
    for(int k=1;k<=t;k++){
      int n=0;
      n = s.nextInt();
      s.nextLine();
      String[] a = new String[n];
      int[] val = new int[n];
      for(int i=0;i<n;i++){
        a[i]=s.nextLine();
        val[i] = (new counter(a[i])).val;
        //System.out.println(a[i]+"\t"+val[i]);
      }
      int gr=0,loc=0;
      for(int i=0;i<n;i++)
        if(val[i]>gr){
          gr=val[i];
          loc=i;
        }
        else if(val[i]==gr){
          if(a[i].compareTo(a[loc])<0){
            loc=i;
          }
        }
      System.out.println("Case #"+k+": "+a[loc]);
    }
  }
}
