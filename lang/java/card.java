import java.awt.*;
import java.applet.*;
import java.awt.event.*;
/*
<applet code="card.class" width=500 height=500>
</applet>
*/
public class card extends Applet implements MouseListener{
  Panel p1,p2,main;
  CardLayout ol;
  public void init(){
    addMouseListener(this);
    ol = new CardLayout();
    Button b1=new Button("Fuck");
    Button b2 = new Button("Kick");
    p1 = new Panel();
    p2 = new Panel();
    p1.add(b1);
    p2.add(b2);
    main = new Panel();
    main.setLayout(ol);
    main.add(p1);
    main.add(p2);
    add(main);
  }
  public void mouseEntered(MouseEvent me){}
  public void mouseExited(MouseEvent me){}
  public void mousePressed(MouseEvent me){
    ol.next(main);
  }
  public void mouseClicked(MouseEvent me){}
  public void mouseReleased(MouseEvent me){}
  public void paint(Graphics g){
    g.drawString("Hello world",50,50);
  }
}
