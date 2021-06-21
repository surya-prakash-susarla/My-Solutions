import java.awt.*;
import java.applet.*;
/*
  <applet code="param.class" width=400 height=500>
  <param name="hello" value="applet">
  </applet>
*/
public class param extends Applet{
  public void init(){
    setBackground(Color.red);
    setForeground(Color.black);
  }
  public void paint(Graphics g){
    g.drawString(getParameter("hello"),150,150);
  }
}
