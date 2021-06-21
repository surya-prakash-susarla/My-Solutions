import java.awt.*;
import java.applet.*;
/*
<applet code="banner.class" width=400 height=400>
<param name="roll" value="My Roll Number is 49 . ">
</applet>
*/
public class banner extends Applet implements Runnable{
  String msg = "";
  Thread t;
  public void init(){
    msg = getParameter("roll");
    t = new Thread(this);
    setBackground(Color.black);
    setForeground(Color.white);
    t.start();
  }
  public void run(){
    for(;;){
      repaint();
      try{Thread.sleep(150);} catch(Exception e){}
    }
  }
  public void paint(Graphics g){
    showStatus("In paint method");
    char ch = msg.charAt(0);
    System.out.println(ch);
    msg = msg.substring(1,msg.length());
    msg +=ch;
    g.drawString(msg,50,50);
  }
}
