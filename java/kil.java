import java.util.regex.*;
public class kil{
  public static void main(String[] args) {
    Pattern pat = Pattern.compile("raavi");
    Matcher mat = pat.matcher("bhaskar is a creative kid with lots of fucking raavi .");
    if(mat.find()) System.out.println("The string exists in the given string");
    else System.out.println("The string does not exist");
  }
}
