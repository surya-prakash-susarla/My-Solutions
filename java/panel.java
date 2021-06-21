import java.awt.*;
import java.applet.*;
class pane{
  pane(){
      Frame f = new Frame();
      Panel temp = new Panel();
      temp.add(new Button("Submt"));
      temp.add(new Button("Fuck"));
      temp.setBackground(Color.green);
      temp.setForeground(Color.blue);
      f.add(temp);
      f.setSize(300,300);
      f.setVisible(true);
      f.setLayout(null);
  }
  public static void main(String[] args) {
    pane tmep=new pane();
  }
}
