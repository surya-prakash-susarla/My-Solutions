interface a{
  default void show(){
    System.out.println("This is the default implementation of the interface");
  }
}
public class th implements a{
  public static void main(String[] args) {
    new th().show();
  }
}
