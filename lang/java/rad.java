import javax.swing.*;
import java.awt.*;
import java.applet.*;
public class rad{
  public rad(){
    JFrame f = new JFrame();
    JRadioButton b = new JRadioButton("Phani");
    JRadioButton c = new JRadioButton("Buski");
    /*ButtonGroup bg = new ButtonGroup();
    bg.add(b);
    bg.add(c);*/
    f.setLayout(new FlowLayout());
    f.add(b);
    f.add(c);
    f.setSize(300,300);
    f.setVisible(true);
  }
  public static void main(String[] args) {
    rad temp = new rad();
  }
}
