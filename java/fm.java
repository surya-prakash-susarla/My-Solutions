import java.awt.*;
import java.applet.*;
import java.awt.event.*;
public class fm extends Frame{
  public fm(){
    super();
    MenuBar mb = new MenuBar();
    Menu m1,m2;
    m1 = new Menu("M1");
    m2 = new Menu("M2");
    mb.add(m1);
    mb.add(m2);
    MenuItem it1 = new MenuItem("Save");
    MenuItem it2 = new MenuItem("Open");
    m1.add(it1);
    m2.add(it2);
    setMenuBar(mb);
    setSize(500,500);
    setVisible(true);
  }
  public static void main(String[] args){
    fm temp = new fm();
  }
}
