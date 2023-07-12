import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="cha.class" height=500 width=500>
</applet>
*/
public class cha extends Applet{
  int x1,y,x2,x3,h1,h2,h3,w;
  public void init(){
    w=50;
    x1=25;
    x2=x1+w;
    x3=x2+w;
    y=150;
    h1=100;
    h2=75;
    h3=250;
  }
  public void paint(Graphics g){
    setBackground(Color.black);
    g.setColor(Color.red);
    g.fillRect(30,100,75,40);
    g.fillRect(30,150,155,40);
    g.fillRect(30,200,115,40);
  }
}
