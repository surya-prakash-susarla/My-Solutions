import java.awt.*;
import java.applet.*;
import java.awt.event.*;
//<applet code="mouse.class" height=500 width=500></applet>
public class mouse extends Applet implements MouseListener,MouseMotionListener{
  String msg;
  public void init(){
    addMouseListener(this);
    addMouseMotionListener(this);
  }
  public void mousePressed(MouseEvent me){
    msg = "Mouse Pressed";
    repaint();
  }
  public void mouseReleased(MouseEvent me){
    msg = "Mouse Released";
    repaint();
  }
  public void mouseClicked(MouseEvent me){
    msg = "Mouse Clicked";
    repaint();
  }
  public void mouseEntered(MouseEvent me){
    msg = "Mouse Entered";
    repaint();
  }
  public void mouseExited(MouseEvent me){
    msg = "Mouse Exited";
    repaint();
  }
  public void mouseMoved(MouseEvent me){
    msg = "Mouse Moved";
    repaint();
  }
  public void mouseDragged(MouseEvent me){
    msg = "Mouse Dragged";
    repaint();
  }
  public void paint(Graphics g){
    g.drawString(msg,100,100);
  }
}
