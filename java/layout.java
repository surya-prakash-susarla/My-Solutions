import java.awt.*;
import java.applet.*;
import java.awt.event.*;

public class layout{
  layout(){
    Frame f = new Frame("Layout");
    f.setSize(300,300);
    f.setLayout(new BorderLayout(150,150));
    Button b1 = new Button("North");
    Button b2 = new Button("South");
    Button b3 = new Button("East");
    Button b4 = new Button("West");
    Button b5 = new Button("Center");
    f.add(b1,BorderLayout.NORTH);
    f.add(b2,BorderLayout.SOUTH);
    f.add(b3,BorderLayout.EAST);
    f.add(b4,BorderLayout.WEST);
    f.add(b5,BorderLayout.CENTER);
    f.setVisible(true);
  }
  public static void main(String[] args) {
    layout temp = new layout();
  }
}
