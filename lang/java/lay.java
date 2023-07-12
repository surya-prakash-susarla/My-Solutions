import java.awt.*;
import java.applet.*;
public class lay {
  Button b1,b2,b3,b4,b5;
  public lay(){
    Frame f = new Frame("Layout display");
    Panel p1 = new Panel();
    p1.setLayout(new FlowLayout());
    p1.add(new Button("Button 1"));
    p1.add(new Button("Button 2"));
    p1.add(new Button("Button 3"));
    p1.add(new Button("Button 4"));
    p1.add(new Button("Button 5"));
    Panel p2 = new Panel();
    p2.setLayout(new BorderLayout());
    p2.add(new Button("Button 1"),BorderLayout.NORTH);
    p2.add(new Button("Button 2"),BorderLayout.SOUTH);
    p2.add(new Button("Button 3"),BorderLayout.EAST);
    p2.add(new Button("Button 4"),BorderLayout.WEST);
    p2.add(new Button("Button 5"),BorderLayout.CENTER);
    f.setLayout(new GridLayout(1,2));
    f.add(p1);
    f.add(p2);
    f.setSize(500,500);
    f.setVisible(true);
  }
  public static void main(String[] args){
    new lay();
  }
}
