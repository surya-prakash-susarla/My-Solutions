import java.awt.*;
import java.applet.*;
public class student{
  public student(){
    Frame f = new Frame("Student Registration Form");
    f.setLayout(new GridLayout(10,2));
    f.add(new Label("ENTER THE DETAILS OF THE STUDENT"));
    f.add(new Label(""));
    f.add(new Label("Enter the name of the student"));
    f.add(new TextField("Enter the name here"));
    f.add(new Label("Enter the address"));
    f.add(new TextField("Enter the address",30));
    f.add(new Label("Enter the age of the student"));
    f.add(new TextField("Enter age",2));
    f.add(new Label("Enter the phone number"));
    f.add(new TextField("Enter mobile number",10));
    f.add(new Label("Select the gender of the student"));
    Panel p = new Panel();
    p.add(new Checkbox("Male"));
    p.add(new Checkbox("Female"));
    f.add(p);
    f.add(new Label("Select the branch of engineering"));
    List branch = new List(4);
    branch.add("CSE");
    branch.add("Mechanical");
    branch.add("Civil");
    branch.add("Electrical");
    f.add(branch);
    f.add(new Label("Enter the type of degree"));
    Choice type = new Choice();
    type.add("Bachelor of Technology");
    type.add("Master of Technology");
    f.add(type);
    f.add(new Label("Enter residence type"));
    Panel h = new Panel();
    CheckboxGroup a= new CheckboxGroup();
    Checkbox day = new Checkbox("Day Scholar",a,true);
    Checkbox hos = new Checkbox("Hostler",a,false);
    h.add(day);
    h.add(hos);
    f.add(h);
    f.setSize(500,500);
    f.setVisible(true);
  }
  public static void main(String[] args){
    new student();
  }
}
