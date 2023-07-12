import java.io.*;
import java.util.*;
public class file_list{
  Vector<String> details = new Vector<String>();
  public void getList(File file) throws Exception{
    File[] temp = file.listFiles();
    for(File f:temp){
      if(!f.isDirectory())
        details.add(f.getAbsolutePath());
      else
        getList(f);
    }
  }


  public static void main(String[] args) throws Exception{
    String drive;
    System.out.println("Enter the name of the drive to search for files");
    drive = new Scanner(System.in).next();
    //drive = drive+":\\";
    file_list temp = new file_list();
    temp.getList(new File(drive));
    System.out.println("**************************************************************************");
    System.out.println("The names of the files in the given drive are : ");
    for(int i=0;i<temp.details.size();i++)
      System.out.println(temp.details.get(i));
    System.out.println("**************************************************************************");

  }
}
