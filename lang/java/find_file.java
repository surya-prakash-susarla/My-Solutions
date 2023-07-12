import java.io.*;
import java.util.*;
class se{
  public void findFile(String name, File file){
    File[] list = file.listFiles();
    if(list!=null)
    for(File fil:list){
      if(fil.isDirectory())
        findFile(name,fil);
      else if(name.equalsIgnoreCase(fil.getName()))
        System.out.println(fil.getParentFile());
    }
  }
  public static void main(String[] a){
    se ff = new se();
    Scanner s = new Scanner(System.in);
    System.out.println("Enter the file to be searched..");
    String name = s.next();
    System.out.println("Enter the directory where to search ");
    String directory = s.next();
    ff.findFile(name,new File(directory));
  }
}
