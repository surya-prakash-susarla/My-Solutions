import java.awt.*;
import java.applet.*;
import java.awt.event.*;
//<applet code="audio.class" width=500 height=500></applet>
public class audio extends Applet{
  Button b;
  AudioClip c;
  public void init(){
    c = getAudioClip(getDocumentBase(),"jt.wav");
    b = new Button("Click");
    add(b);
    b.addActionListener(new ActionListener(){
      public void actionPerformed(ActionEvent ae){
        System.out.println("Button clicked");
        c.play();
      }
    });
  }
}
