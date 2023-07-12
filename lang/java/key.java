import java.awt.*;
import java.applet.*;
import java.awt.event.*;
//<applet code="key.class" height=500 width=500></applet>
public class key extends Applet implements KeyListener{
  String msg;
  TextField a;
  public void init(){
    a = new TextField("Use keyboard here");
    add(a);
    a.addKeyListener(this);
  }
  public void keyPressed(KeyEvent ke){
    msg = ke.getKeyText(ke.getKeyCode());
    repaint();
  }
  public void keyReleased(KeyEvent ke){
    msg = "Key Released";
    repaint();
  }
  public void keyTyped(KeyEvent ke){
    msg = ""+ke.getKeyChar();
    repaint();
  }
  public void paint(Graphics g){
    g.drawString(msg,100,100);
  }
}
