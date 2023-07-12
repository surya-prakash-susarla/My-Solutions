import java.util.regex.*;
public class matches_test{
  public static void main(String[] args){
    String s = "new_file.mp3";
    String ex=s.substring(s.lastIndexOf('.')+1);
    System.out.println(ex);
  }
}
