import java.io.*;
public class stream{
  public static void main(String[] args) throws Exception{
    InputStreamReader f = new InputStreamReader(System.in);
    char c;
    do{
      c = (char)f.read();
      System.out.println("Entered "+c);
    }
    while(c!='q');
  }
}
