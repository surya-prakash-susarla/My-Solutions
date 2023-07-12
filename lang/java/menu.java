import java.awt.*;
import java.applet.*;
import java.awt.event.*;
/*
<applet code="menu" width=400 height=500>
</applet>
*/
class sample extends Frame{
  public MenuBar menuBar;
  public Menu menu1,menu2;
  public MenuItem item1,item2,item3,item4,item5;
  public sample(String name){
    super(name);
    menuBar = new MenuBar();
    menu1= new Menu("File");
    menu2= new Menu("Edit");
    item1 = new MenuItem("Save");
    item2 = new MenuItem("open");
    item3 = new MenuItem("save as");
    item4 = new MenuItem("Edit");
    item5 = new MenuItem("Quit");
    setLayout(new FlowLayout());
    menu1.add(item1);
    menu1.add(item2);
    menu2.add(item3);
    menu2.add(item4);
    menu2.add(item5);
    menuBar.add(menu1);
    menuBar.add(menu2);
    setMenuBar(menuBar);
    setLayout(new BorderLayout());
  }
}
public class menu extends Applet{
  Frame f;
  public void init(){
    setSize(1000,1000);
    f = new sample("This is just a new frame");
    f.setSize(500,500);
    f.setVisible(true);
    setLayout
  }
  public void paint(Graphics g){
    showStatus("This is just a tester");

  }
}
