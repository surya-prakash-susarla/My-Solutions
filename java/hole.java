import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="hole.class" width=500 height=500>
</applet>
*/
public class hole extends Applet implements ActionListener{
  Button submit;
  TextArea t1,t2;
  String s;
  public void init(){
    submit = new Button("Submit");
    t1 = new TextArea("Enter values");
    t2 = new TextArea("");
    submit.addActionListener(this);
    add(t1);
    add(t2);
    add(submit);
  }
  public void actionPerformed(ActionEvent ae){
    if(ae.getSource()==submit){
      s = t1.getText();
      high();
    }
  }
  public void high(){
    String[] a = s.split(" ");
    int[] n = new int[a.length];
    for(int i=0;i<n.length;i++)
      n[i] = Integer.parseInt(a[i]);
    int temp;
    if(n[0]>=n[1]) temp=n[0];
    else temp=n[1];
    if(temp<n[2]) temp=n[2];
    t2.setText(String.valueOf(temp));
  }
}
