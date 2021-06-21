import java.util.Scanner;
public class bin{
int[] a;
int n,search,found_index;
public bin(){
Scanner s = new Scanner(System.in);
System.out.println("Enter the size");
n = s.nextInt();
a = new int[n];
System.out.println("Enter the elements");
for(int i=0;i<n;i++)
	a[i] = s.nextInt();
System.out.println("Enter the element to be searched");
search = s.nextInt();
}

public void se(int s , int f){
if(s+f>2){
int middle = (s+f)/2;
if(a[middle]<search)	se(middle+1,a.length);
if(a[middle]>search)	se(0,middle);
else if(a[middle]==search){
	found_index=middle;
	return;
}}
else{
if(search == a[s])
	found_index=s;
if(search==a[f-1])
	found_index=f-1;
}}
	

public static void main(String[] args){
bin temp = new bin();
temp.se(0,temp.a.length);
System.out.println("Index is "+temp.found_index);
}}

