interface st{
  default void show(){
    System.out.println("This is the default implementation of the show method");
  }
}
public class ee implements st{
  //  public void show(){
  //  System.out.println("This is the implementation of the method in the implemented class");
//  }
  public static void main(String[] args) {
    ee temp = new ee();
    temp.show();
  }
}
