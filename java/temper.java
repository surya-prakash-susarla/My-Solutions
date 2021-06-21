import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
/*
<applet code="temper.class" width=500 height=500>
</applet>
*/
public class temper extends JApplet implements MouseListener {
	public JButton submit;
	public JLabel entrance,ch,li,ra;
	public JTextArea address;
	public JTextField name;
	public JCheckBox stream1,stream2;
	public JList<String> gender;
	public JRadioButton spec1,spec2;
	public temper(){
		System.out.println("I do nothing");
	}
	public void init(){
		SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				myFunc();
			}
		});
	}
	public void myFunc(){
		setLayout(new GridLayout(12,1));
    //setBackground(Color.black);
    //setForeground(Color.white);
		submit=new JButton("Click here to submit the details..");
		entrance = new JLabel("Enter your details");
		address = new JTextArea();
		address.setText("Enter the details of your address here");
		name = new JTextField();
		name.setText("Enter your name");
		stream1 = new JCheckBox("Computer Science");
		stream2 = new JCheckBox("Mechanical");
		ch = new JLabel("Select your branch:");
		li = new JLabel("Select your gender:");
		ra = new JLabel("Select your degree:");
		String[] gen = {"Male","Female"};
		gender = new JList<String>(gen);
		spec1 = new JRadioButton("B.Tech");
		spec2 = new JRadioButton("M.Tech");
		add(entrance);
		add(name);
		add(address);
		add(ch);
		add(stream1);
		add(stream2);
		add(li);
		add(gender);
		add(ra);
		add(spec1);
		add(spec2);
    add(submit);
	}
	public void mouseClicked(MouseEvent me){
		showStatus("Mouse Clicked");
	}
	public void mousePressed(MouseEvent me){
		showStatus("Mouse Pressed");
	}
	public void mouseDragged(MouseEvent me){
		showStatus("Mouse Dragged");
	}
	public void mouseExited(MouseEvent me){
		showStatus("Mouse Exited");
	}
	public void mouseEntered(MouseEvent me){}
	public void mouseReleased(MouseEvent me){}
}
