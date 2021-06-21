import java.util.Scanner;
class process{
  static float avgw,avgt;
  int burst,wait,turn,back;
  static int q;
}
public class robin{
  public static void main(String[] args){
    int n;
    System.out.println("Enter the number of processes");
    Scanner s = new Scanner(System.in);
    n = s.nextInt();
    process[] a = new process[n];
    System.out.println("Enter the burst times of processes");
    for(int i=0;i<n;i++){0
      a[i]= new process();
      a[i].burst = s.nextInt();
      a[i].back = a[i].burst;
    }
    System.out.println("Enter the value of time quantum");
    process.q = s.nextInt();
    int ti=0;
    while(ti<n-1)
    for(int i=0;i<n;i++){
      if(a[i].burst>0){
        int t=0;
        while(t<process.q&&a[i].burst>0){
          a[i].burst-=1;
          t+=1;
          for(int j=0;j<n;j++)
            if(j!=i&&a[j].burst>0){
              a[j].wait+=1;
            }
        }
      }
      if(a[i].burst==0){
        ti+=1;
        a[i].burst=-2;
      }
      for(process k: a)
        System.out.println(k.wait+" "+k.turn+" "+k.burst);
      System.out.println();
    }
    for(int i=0;i<n;i++){
      a[i].turn=a[i].wait+a[i].back;
      process.avgw+=a[i].wait;
      process.avgt+=a[i].turn;
    }
    System.out.println("wait\tTurn");
    for(process i: a){
      System.out.println(i.wait+"\t"+i.turn);
    }
    System.out.println("Average waiting time is "+(process.avgw/n)+"\nAverage turn time is "+(process.avgt/n));
  }
}
