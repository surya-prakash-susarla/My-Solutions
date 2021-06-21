import java.awt.*;
import java.applet.*;
//<applet code="img.class" height=500 width=500></applet>
public class img extends Applet{
  Image pic ;
  public void init(){
    pic = getImage(getDocumentBase(),"rainy.jpg");
    repaint();
  }
  public void paint(Graphics g){
    g.drawImage(pic,20,20,this);
  }
}
