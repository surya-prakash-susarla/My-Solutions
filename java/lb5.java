public class lb5{
  lb5(int a){
    System.out.println("In parameterized constructor 1");
  }
  lb5(char c){
    System.out.println("In parameterized constructor 2");
  }
  public static void main(String[] args){
    lb5 temp1= new lb5(10);
    lb5 temp2= new lb5('a');
  }
}
