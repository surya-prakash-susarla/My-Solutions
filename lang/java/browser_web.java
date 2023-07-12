import java.awt.Desktop;
import java.net.URI;
import java.util.Scanner;
import java.io.File;
public class desk{
  public static void main(String[] arsgs) throws Exception{
    String strin;
    Scanner s = new Scanner(System.in);
    strin = s.next();
    if(Desktop.isDesktopSupported()){
      Desktop.getDesktop().browse(new URI(strin));
      String fil;
      System.out.println("Enter the name of the file");
      fil = s.next();
      fil = fil+".txt";
      Desktop.getDesktop().open(new File(fil));

      System.out.println(File.pathSeparator);
    }
  }
}
