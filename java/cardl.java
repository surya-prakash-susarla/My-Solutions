import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class cardl implements ActionListener{
  CardLayout cl = new CardLayout();
  Panel main;
  Button submit;
  public cardl(){
    Panel first = new Panel();
    first.add(new Button("Phani"));
    first.add(new Button("Kumar"));
    first.setBackground(Color.red);
    Panel second = new Panel();
    second.add(new Button("Jagadish"));
    second.add(new Button("Chitturi"));
    second.setBackground(Color.gray);
    Panel third = new Panel();
    third.add(new Button("Surya"));
    third.add(new Button("Prakash"));
    third.setBackground(Color.green);
    main = new Panel();
    main.add(first);
    main.add(second);
    main.add(third);
    main.setLayout(cl);
    Frame f = new Frame("Card");
    f.add(main);
    f.setLayout(new FlowLayout());
    f.setSize(300,300);
    submit = new Button("Change");
    submit.addActionListener(this);
    f.add(submit);
    f.setVisible(true);
  }
  public void actionPerformed(ActionEvent ae){
    cl.next(main);
  }
  public static void main(String[] args) {
    cardl temp = new cardl();
  }
}
