import java.net.*;
import java.io.*;
public class server{
  public static void main(String[] args) throws Exception {
    ServerSocket s = new ServerSocket(6699);
    Socket a = s.accept();
    DataInputStream d = new DataInputStream(a.getInputStream());
    System.out.println((String)d.readUTF());
  }
}
