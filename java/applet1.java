import java.awt.*;
import java.applet.*;
//<applet code="applet1.class" height=300 width=500></applet>
public class applet1 extends Applet{
  TextField t1;
  public void init(){
    t1 = new TextField();
    add(t1);
  }
  public void paint(Graphics g){
    g.drawString("This is great",100,100);
    g.drawString(t1.getText(),100,200);
  }
}
