import java.io.*;
public class deser{
  public static void main(String[] args) throws Exception{
    ObjectInputStream in = new ObjectInputStream(new FileInputStream("f.txt"));
    student s = (student) in.readObject();
    s.getName();
  }
}
