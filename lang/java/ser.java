import java.io.*;
class student implements Serializable{
  String name;
  student(String name){
    this.name= name;
  }
  void getName(){
    System.out.println(name);
  }
}
public class ser{
  public static void main(String[] args) throws Exception{
    student s1 = new student("Surya Prakash Susarla");
    FileOutputStream fout = new FileOutputStream("f.txt");
    ObjectOutputStream out = new ObjectOutputStream(fout);
    out.writeObject(s1);
    out.flush();
    System.out.println("Done");
  }
}
