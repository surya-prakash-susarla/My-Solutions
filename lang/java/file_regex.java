import java.io.*;
import java.util.Scanner;
import java.util.regex.*;
import java.awt.Desktop;

public class file_regex{
  public static void main(String[] rags) throws Exception{
    FileInputStream fstream = new FileInputStream("test_file.txt");
    DataInputStream in = new DataInputStream(fstream);
    BufferedReader br = new BufferedReader(new InputStreamReader(in));
    String strline;
    System.out.println("Enter a string to be searched");
    String temp;
    Scanner s = new Scanner(System.in);
    temp  = s.next();
    Pattern pat = Pattern.compile(temp);
    while((strline = br.readLine())!=null){
      Matcher mat = pat.matcher(strline);
      if(mat.find()){
        System.out.println("The given string found at "+mat.start());
        if(Desktop.isDesktopSupported()){
          Desktop.getDesktop().open(new File("test_file.txt"));
        }
      }
    }
  }
}
