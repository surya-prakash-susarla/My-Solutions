import java.awt.*;
import java.applet.*;
public class windows1{
  windows1(){
    Frame f = new Frame("Windows");
    f.add(new Label("Goodbye JAVA !!!"));
    f.setSize(500,400);
    f.setVisible(true);
  }
  public static void main(String[] args){
    new windows1();
  }
}
