import java.net.*;
public class netw{
  public static void main(String[] args) {
    try{
      System.out.println(InetAddress.getByName("www.youtube.com").isMulticastAddress());l
    }
    catch(Exception e){}
  }
}
