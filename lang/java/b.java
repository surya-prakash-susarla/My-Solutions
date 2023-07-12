import java.awt.*;
import java.applet.*;
//<applet code="b.class" width=500 height=500></applet>
public class b extends Applet{
  public void paint(Graphics g){
    g.setColor(Color.red);
    g.fillRect(50,150,100,20);
  }
}
