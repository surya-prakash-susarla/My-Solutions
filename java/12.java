import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="hole.class" height=500 width=600>
</applet>
*/
public class hole extends Applet implements KeyListener{
  TextArea t1,t2;
  String s ="";
  public void init(){
    t1 = new TextArea();
    t2 = new TextArea();
    t1.setText("Enter the number here");
  }
  public void keyPressed(KeyEvent ke){
    if(ke.getKeyCode()==KeyEvent.VK_ENTER)
      s = t1.getText();
      texter();
  }
  public void keyReleased(KeyEvent ke){}
  public void keyTyped(KeyEvent ke){}
  public void texter(){
    String[] f = s.split(" ");
    int[] n = new int[f.length];
    for(int i=0;i<n.length;i++)
      n[i] = Integer.parseInt(f[i]);
    int tmp;
    if(n[0]>n[1]) tmp=n[0];
    else tmp=n[1];
    if(tmp<n[2]) tmp=n[2];
    t2.setText("The greatest value is : "+tmp);
  }
}
