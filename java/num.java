import java.awt.*;
import java.applet.*;
import java.awt.event.*;
public class num extends Frame{
  public num(){
    setLayout(new FlowLayout());
    TextField a,b;
    a = new TextField("Enter the number");
    Button submit = new Button("Submit");
    add(a);
    add(submit);
    b = new TextField(10);
    TextField status = new TextField(20);
    add(status);
    add(b);
    submit.addActionListener(new ActionListener(){
      public void actionPerformed(ActionEvent ae){
        int x = Integer.parseInt(a.getText());
        int fact=1;
        for(int i=1;i<=x;i++)
          fact = fact*i;
        b.setText(String.valueOf(fact));
        int back=x;
        fact=0;
        while(back>0){
          fact = fact*10 +(back%10);
          back = back/10;
        }
        if(fact==x) status.setText("Palindrome");
        else status.setText("Not Palindrome");
      }
    });
    setTitle("Windows");
    setSize(500,500);
    setVisible(true);
  }
  public static void main(String[] args){
    new num();
  }
}
