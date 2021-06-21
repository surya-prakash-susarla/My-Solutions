class st{
  int i=1421313123;
  public void in(){
      System.out.println("Hello");
  }
}
public class ex extends st{
  public void in(){
    System.out.println("HI"+super.i);
  }
  public void out(){  System.out.println("KEIEIEIEI");}
  public static void main(String[] args) {
    ex a = new ex();
      a.in();
    st t = new ex();
      t.in();
      //t.out();
    //ex e = new st();
    //  e.in();
  }
}
