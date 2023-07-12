import java.io.*;
import java.util.Scanner;
public class file_read{
  public static void main(String[] args) throws Exception{
    Scanner  s = new Scanner(new FileReader("test_file.txt"));
    while(s.hasNext()){
      String temp = s.next();
      System.out.println(temp);
    }
  }
}
