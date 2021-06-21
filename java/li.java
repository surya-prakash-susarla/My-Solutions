import java.awt.*;
import java.applet.*;
import javax.swing.*;
public class li{
  public li(){
    JFrame f = new JFrame("NEW FRAME");
    f.setLayout(new FlowLayout());
    f.getContentPane().setBackground(Color.green);
    String[] a = {"Baski","pussy","cat"};
    JList<String> jl = new JList<String>(a);
    f.add(jl);
    JLabel g = new JLabel("This is phani cat ");
    f.add(g);
    f.setSize(300,300);
    f.setVisible(true);
  }
  public static void main(String[] args) {
    li temp = new li();
  }
}
