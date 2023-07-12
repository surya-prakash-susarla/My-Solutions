import java.net.*;
import java.io.*;
public class ne{
  public static void main(String[] args) throws Exception {
    URL a = new URL("http://google.com");
    System.out.println(a.getPort());
    URLConnection f = a.openConnection();
    f.connect();
    BufferedReader r = new BufferedReader(new InputStreamReader(a.openStream()));
    String s;
    try{
    while((s=r.readLine())!=null)
      System.out.println(s);}
    catch(Exception e){
      System.out.println("Infinite loop");
  }}
}
