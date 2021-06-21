import java.awt.*;
import java.applet.*;
import java.awt.event.*;
/*
<applet code="appleter.class" height=500 width=500>
<param name="image" value="rainy.jpeg">
</applet>
*/
public class appleter extends Applet{
  Image img;
  public void init(){
    setLayout(new FlowLayout());
    img = getImage(getDocumentBase(),getParameter("image"));
    repaint();
  }
  public void paint(Graphics g){
    g.drawImage(img,0,0,this);
  }
}
