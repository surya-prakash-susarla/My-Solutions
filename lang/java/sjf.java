import java.util.Scanner;
class process{
  static float avgw,avgt;
  int pno,arrival,burst,wait,turn,back;
}
public class sjf{
  static int n,ti,st;
  static process[] a;
  static void exec(int loc){
    for(process i:sjf.a){
      if(i.pno==loc){
        i.burst-=1;
        ti+=1;
      }
      else if (i.pno!=loc && i.burst>0){
        i.wait+=1;
      }
      if(i.burst==0){
        n-=1;
        i.burst=-2;
      }
    }
  }
  static void calc(){
    for(process i:sjf.a){
      i.wait-=i.arrival;
      i.turn=i.wait+i.back;
      process.avgw+=i.wait;
      process.avgt+=i.turn;
    }
    process.avgw/=sjf.st;
    process.avgt/=sjf.st;
  }
  public static void main(String[] args){
    System.out.println("Enter the number of processes");
    Scanner s = new Scanner(System.in);
    sjf.n = s.nextInt();
    a = new process[sjf.n];
    System.out.println("Enter the arrival and burst times");
    for(int i=0;i<sjf.n;i++){
      a[i]=new process();
      a[i].arrival = s.nextInt();
      a[i].burst = s.nextInt();
      a[i].back= a[i].burst;
      a[i].wait=0;
      a[i].pno = i;
    }
    st=sjf.n;
    while(n>0){
      int loc=-1,burst=99999;
      boolean found=false;
      for(process i:a)
        if(i.burst>0&&i.arrival<=ti&&i.burst<=burst){
          loc = i.pno;
          found=true;
          burst= i.burst;
        }
      System.out.println("PROCESS#"+loc);
      if(found==false&&loc==-1){
        ti+=1;
        continue;
      }
      else if(found==true)
        sjf.exec(loc);
    }
    sjf.calc();
    System.out.println("Wait\tTurn");
    for(process i : sjf.a)
      System.out.println(i.wait+"\t"+i.turn);
    System.out.println("Average wating time is "+process.avgw+"\nAverage turn time is "+process.avgt);
  }
}
