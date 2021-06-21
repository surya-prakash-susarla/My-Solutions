import java.util.Scanner;
class pro{
  int pno,a,b,w,t,bu;
  static float avgt=0,avgw=0;
}
public class sjfpre{
  static int n,ti;
  static void exec(pro[] a,int loc){
    for(int i=0;i<sjfpre.n;i++){
      if(a[i].pno==loc&&a[i].b>0){
        a[i].b-=1;
        sjfpre.ti+=1;
      }
      else{
        a[i].w+=1;
      }
      if(a[i].b==0){
        sjfpre.n-=1;
        a[i].b=-2;
      }
    }
  }
  public static void main(String[] args){
    Scanner s = new Scanner(System.in);
    System.out.println("Enter the number of processes");
    n = s.nextInt();
    int q=n;
    pro[] a = new pro[n];
    System.out.println("Enter the arrival and burst times of the processes");
    for(int i=0;i<n;i++){
      a[i] = new pro();
      a[i].pno = i;
      a[i].a = s.nextInt();
      a[i].b = s.nextInt();
      a[i].bu = a[i].b;
    }
    while(n>0){
      System.out.println(n+" "+ti);
      int burst=9999;
      int loc=-1;
      boolean found=false;
      for(int i=0;i<n;i++)
        if(a[i].a<=ti&&a[i].b>0&&a[i].b<burst){
          loc=a[i].pno;
          found=true;
          burst=a[i].b;
        }
      if(loc==-1){
        ti+=1;
        continue;
      }
      else if(found==false&&loc!=-1){
        sjfpre.exec(a,loc);
      }
      else
        sjfpre.exec(a,loc);
    }
    for(int i=0;i<n;i++){
      a[i].w=a[i].w-a[i].a;
      a[i].t=a[i].w+a[i].bu;
      pro.avgt+=a[i].w;
      pro.avgw+=a[i].t;
    }
    pro.avgw/=q;
    pro.avgt/=q;
    System.out.println("P | W | T");
    for(pro i:a)
      System.out.println(i.pno+" | "+i.w+" | "+i.t);
    System.out.println("The average waiting time is "+pro.avgw+"\nThe average turn time is "+pro.avgt);
  }
}
