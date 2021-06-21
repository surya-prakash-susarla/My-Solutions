import java.awt.*;
import java.applet.*;
public class applet2 extends Applet{
  String s = null;
  public void init(){
    s = getParameter("type");
    showStatus("In intialization method");
  }
  public void paint(Graphics g){
    g.drawString(s,150,150);
  }
}
