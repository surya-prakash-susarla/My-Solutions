import java.net.*;
import java.io.*;
import java.util.Scanner;
public class client{
  public static void main(String[] args) throws Exception {
    Socket s = new Socket("localhost",6699);
    DataOutputStream d = new DataOutputStream(s.getOutputStream());
    System.out.println("Enter a string");
    Scanner t = new Scanner(System.in);
    String f = t.next();
    d.writeUTF(f);
  }
}
