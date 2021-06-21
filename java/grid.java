import java.awt.*;
import java.applet.*;
import java.awt.event.*;

public class grid{
  grid(){
    Frame f = new Frame("GRID Layout");
    f.setSize(300,300);
    f.setLayout(new FlowLayout());
    Button b1 = new Button("North");
    Button b2 = new Button("South");
    Button b3 = new Button("East");
    Button b4 = new Button("West");
    Button b5 = new Button("Center");
    f.add(b1);
    f.add(b2);
    f.add(b3);
    f.add(b4);
    f.setVisible(true);
  }
  public static void main(String[] args) {
    grid temp = new grid();
  }
}
