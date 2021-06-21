import java.awt.*;
public class can{
  can(){
    Frame f = new Frame();
    f.add(new temp());
    f.setSize(300,300);
    f.setVisible(true);
    f.setLayout(null);
  }
  public static void main(String[] args) {
    can tem = new can();
  }
}
class temp extends Canvas{
  temp(){
    setSize(300,300);
    setBackground(Color.black);
  }
  public void paint(Graphics g){
    g.setColor(Color.green);
    g.fillArc(30,30,40,50,60,60);
  }
}
