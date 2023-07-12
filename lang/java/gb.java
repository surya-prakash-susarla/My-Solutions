import java.awt.*;
import java.applet.*;
public class gb {
  public gb(){
    Frame f = new Frame("Grid Bag Layout");
    GridBagLayout g = new GridBagLayout();
    GridBagConstraints cons = new GridBagConstraints();
    f.setLayout(g);
    TextField a = new TextField();
    cons.gridx=0;
    cons.gridy=1;
    g.setConstraints(a,cons);
    f.add(a);
    Button b =new Button("Submit");
    cons.gridx=1;
    cons.gridy=2;
    g.setConstraints(b,cons);
    f.add(b);
    Button r = new Button("KILL");
    cons.gridx=2;
    cons.gridy=3;
    g.setConstraints(r,cons);
    f.add(r);
    f.setSize(300,300);
    f.setVisible(true);
  }
  public static void main(String[] args) {
    gb temp = new gb();
  }
}
