abstract class j{
  abstract public void show();
  public void write(){
    System.out.println("write");
  }
}
public class pali extends j{
  public void show(){
      System.out.println("pali show");
  }
  public static void main(String[] args) {
    pali t = new pali();
    t.show();
    t.write();
  }
}
