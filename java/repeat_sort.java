import java.util.Scanner;
import java.util.Vector;
public class repeat_sort{
public static void main(String[] args){

Vector a = new Vector();
Scanner s  = new Scanner(System.in);
int n;
while((n=s.nextInt())!=-1)
a.addElement(n);
Integer temp,size;
for(int j=0;j<a.size();j++)
for(int i=0;i<a.size()-1;i++){
System.out.println(a.get(i)+"\t"+a.get(i+1));
if(Integer.valueOf(a.get(i).toString())<Integer.valueOf(a.get(i).toString())){
temp=Integer.valueOf(a.get(i).toString());
size=Integer.valueOf(a.get(i).toString());
System.out.println(temp+"\t"+size);
a.set(i,size);
a.set(i+1,temp);
}}
for(int i=0;i<a.size();i++)
System.out.println(a.get(i).toString());
}
}
