package quad2;

import quad1.lb4_interface;
import java.util.Scanner;
import java.lang.Math;

public class lb4_impl implements lb4_interface{

    public void calculate_roots(){
      System.out.println("Enter the co-efficients of the quadratic equation");
      Scanner s = new Scanner (System.in);
      int a,b,c;
      a = s.nextInt();
      b = s.nextInt();
      c = s.nextInt();
      double z = (-b)+t;
      double y = (-b)-t;
      z = z/(2*a);
      y = y/(2*a);
      System.out.println("The roots of the equation are "+z+" and "+y);
    }

    public static void main(String[] args){
      lb4_impl temp = new lb4_impl();
      temp.calculate_roots();
    }

}
