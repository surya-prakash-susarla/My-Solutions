import java.awt.*;
import java.applet.*;
//<applet code="windows.class" height=500 width=500></applet>
public class windows extends Applet{
  public void init(){
    Frame f = new Frame("Window");
    f.add(new Label("GoodBye Java!!!"));
    f.setSize(500,200);
    f.setVisible(true);
  }
}
