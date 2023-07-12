import java.applet.*;
import java.awt.*;
import java.awt.event.*;
//<applet code="pal.class" height=500 width=500></applet>
public class pal extends Applet implements ActionListener{
  TextField a,b;
  Button submit;
  String msg;
  public void init(){
    a = new TextField("Enter the string");
    b = new TextField("The reversed string is ");
    submit = new Button("Submit");
    add(a);
    add(b);
    add(submit);
    submit.addActionListener(this);
  }
  public void actionPerformed(ActionEvent ae){
    String str  = a.getText();
    String st = new StringBuffer(str).reverse().toString();
    if(str.equals(st))
      msg = "Palindrome";
    else
      msg = "Not Palindrome";
    b.setText(st);
    repaint();
  }
  public void paint(Graphics g){
    g.drawString(msg,50,50);
  }
}
