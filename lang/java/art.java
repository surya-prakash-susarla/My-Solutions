import java.applet.*;
import java.awt.*;
import java.awt.event.*;
//<applet code="art.class" height=500 width=500></applet>
public class art extends Applet implements ActionListener{
  Button add,sub,mul,div,mod;
  TextField a,b;
  public void init(){
    add = new Button("+");
    sub = new Button("-");
    mul = new Button("*");
    div = new Button("/");
    mod = new Button("%");
    a = new TextField("Enter the number seperated by space");
    b = new TextField();
    add(a);
    add(b);
    add(add);
    add(sub);
    add(mul);
    add(div);
    add(mod);
    add.addActionListener(this);
    sub.addActionListener(this);
    mul.addActionListener(this);
    div.addActionListener(this);
    mod.addActionListener(this);
  }
  public void actionPerformed(ActionEvent ae){
    String[] f = a.getText().split(" ");
    int x = Integer.parseInt(f[0]);
    int y = Integer.parseInt(f[1]);
    if(ae.getSource()==add){
      b.setText(String.valueOf(x+y));
    }
    else if(ae.getSource()==sub){
      b.setText(String.valueOf(x-y));
    }

    else if(ae.getSource()==mul){
      b.setText(String.valueOf(x*y));
    }
    else if(ae.getSource()==div){
      b.setText(String.valueOf((float)x/y));
    }
    else if(ae.getSource()==mod){
      b.setText(String.valueOf(x%y));
    }
  }
}
