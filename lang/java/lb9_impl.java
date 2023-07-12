
public class lb9_impl implements lb9_inter1,lb9_inter2{
  public void func1(){
    System.out.println("Function of first interface");
  }
  public void func2(){
    System.out.println("Function of second interface");
  }
  public static void main(String[] args){
    lb9_impl temp = new lb9_impl();
    temp.func1();
    temp.func2();
  }
}
