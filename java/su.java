public class su{
  public static void main(String[] args) {
    try{
      int i= Integer.parseInt(args[0]);
      if(i==1)
          throw new ArithmeticException();
      else if(i==2)
        throw new Exception();
    }
    catch(ArithmeticException e){
      System.out.println("FUCK");
    }
    catch(Exception e){
      System.out.println("FUCKER");
    }
  }
}
