class A{
    final public void show(){
    System.out.println("Hello");
  }
}

public class extend extends A{
  public void kill(){
    System.out.println("Kill");
  }
  public static void main(String[] args){
    extend temp = new extend();
    temp.show();
    temp.kill();
  }
}
