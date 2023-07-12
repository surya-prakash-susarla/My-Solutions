import java.net.*;
import java.util.regex.*;
public class net{
  public static void main(String[] args){
    try{
    System.out.println(InetAddress.getLocalHost());
  }
  catch(Exception e){}
  }
}
