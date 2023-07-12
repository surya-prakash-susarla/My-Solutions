import java.awt.*;
import java.applet.*;
import java.awt.event.*;
//<applet code="but.class" height=500 width=500></applet>
public class but extends Applet{
  Button b;
  String msg;
  public void init(){
    b = new Button("Click me");
    //b.setBounds(100,200,100,200);
    b.addActionListener(new ActionListener(){
      public void actionPerformed(ActionEvent ae){
        msg = "Fish";
        repaint();
      }
    });
    add(b);
  }
  public void paint(Graphics g){
    g.drawString(msg,200,200);
  }
}
