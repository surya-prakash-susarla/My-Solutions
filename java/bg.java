import javax.swing.*;
public class bg{
  JFrame f;
  bg(){
    f = new JFrame();
    JRadioButton r1= new JRadioButton("Male");
    JRadioButton r2 = new JRadioButton("Female");
    ButtonGroup bg = new ButtonGroup();
    bg.add(r1); bg.add(r2);
    f.add(r1); f.add(r2);
    f.setLayout(null);
    f.setSize(500,500);
    f.setVisible(true);
  }
  public static void main(String[] args) {
    new bg();
  }
}
