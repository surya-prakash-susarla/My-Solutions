import java.util.Scanner;
public class st{
  public static void main(String[] args) {
    int t;
    Scanner sc = new Scanner(System.in);
    t = sc.nextInt();
    for(int o=0;o<t;o++){
      String a,b;
      a = sc.next();
      b = sc.next();
      int ia=0,ib=0;
      while(ia<a.length()&&ib<b.length()){
        if(a.charAt(ia)!='*'&&b.charAt(ib)!='*'){
            ia+=1;
            ib+=1;
            System.out.println("SAME");
            continue;
        }
        else if(a.charAt(ia)=='*'){
          System.out.println("aaa");
          String start = a.substring(0,ia);
          String rem = a.substring(ia+1);
          String s="";
          int val=0;
          char nx = a.charAt(ia+1);
          while(val<4&&b.charAt(ib)!='*'){
            s = s.concat(Character.toString(b.charAt(ib)));
            ib+=1;
            val+=1;}
          String fin="";
          fin= fin.concat(start);
          fin=fin.concat(s);
          fin=fin.concat(rem);
          a=fin;
          ia+=val;
        }
        else if(b.charAt(ib)=='*'){
          System.out.println("BBB");
          String start = b.substring(0,ib);
          String rem = b.substring(ib+1);
          String s="";
          int val=0;
          char nx = b.charAt(ib+1);
          while(val<4&&a.charAt(ia)!='*'){
            s=s.concat(Character.toString(a.charAt(ia)));
            ia+=1;
            val+=1;
          }
          String fin="";
          fin=fin.concat(start);
          fin=fin.concat(s);
          fin=fin.concat(rem);
          ib+=val;
          b=fin;
        }
        System.out.println("WHILER\n");
      }
      System.out.println("String a = "+a+"\nString b = "+b);
    }
  }
}
