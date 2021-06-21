import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="bar.java" width=500 height=500>
</applet>
*/
public class bar extends Applet implements MouseMotionListener{
  int x,y;
  public void init(){
    addMouseMotionListener(this);
  };
  public void mouseDragged(MouseEvent me){}
  public void mouseMoved(MouseEvent me){
    x= me.getX();
    y = me.getY();
    showStatus(x+" "+y);
  }
}
