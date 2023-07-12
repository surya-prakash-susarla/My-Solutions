import java.io.*;
import java.util.*;

public class hc {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        int nr;
        Scanner s = new Scanner(System.in);
        nr = s.nextInt();
        int p=0,n=0,z=0;
        for(int i=0;i<nr;i++){
            int temp = s.nextInt();
            if(temp<0)
                n+=1;
            else if(temp>0)
                p+=1;
            else if(temp==0)
                z+=1;
                }
        System.out.println(n+"\t"+p+"\t"+z+"\t"+nr);
        System.out.println(Double.parseDouble(Integer.toString(p/nr))+"\n"+(n/nr)+"\n"+(z/nr));
        }
    }
