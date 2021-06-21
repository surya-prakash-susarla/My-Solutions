import java.io.*;
public class file_tester{

  void print_file(File f) throws Exception{
    File[] temp = f.listFiles();
    if(temp!=null){
    for(int i=0;i<temp.length;i++){
      if(temp[i].isDirectory())
        print_file(temp[i]);
      else
        System.out.println(temp[i].getAbsolutePath());
    }
  }
  }

  public static void main(String[] args) throws Exception{
    File drive = new File("E:\\");
    new file_tester().print_file(drive);

  }
}
