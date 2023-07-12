import  java.util.Scanner;
class pro{
  int arr,bur,wai,turn,pno;
  static float avgt=0,avgw=0;
}
public class fcfs{
    public static void main(String[] args){
      int n;
      System.out.println("Enter the value of n");
      Scanner s = new Scanner(System.in);
      n = s.nextInt();
      pro[] a = new pro[n];
      System.out.println("Enter the arrival and burst times of the processes");
      for(int i=0;i<n;i++){
        a[i] = new pro();
        a[i].arr = s.nextInt();
        a[i].bur = s.nextInt();
        a[i].pno=i+1;
      }
      for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++)
          if(a[j].arr>a[j+1].arr){
            pro temp = a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
          }
      int ti=0;
      for(int i=0;i<n;i++){
        a[i].wai=ti;
        a[i].wai-=a[i].arr;
        ti+=a[i].bur;
        a[i].turn = a[i].wai+a[i].bur;
        pro.avgt+=a[i].turn;
        pro.avgw+=a[i].wai;
      }
      pro.avgt/=n;
      pro.avgw/=n;
      System.out.println("P | W | T");
      for(pro i:a){
        System.out.println(i.pno+" | "+i.wai+" | "+i.turn);
      }
      System.out.println("Average turn time "+pro.avgt+"\nAverage wait time "+pro.avgw);
    }
  }
