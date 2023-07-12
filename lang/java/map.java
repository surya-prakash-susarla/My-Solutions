import java.util.Scanner;
class stacker{
  static int[] x,y;
  static int count,top;
  stacker(){
    x=new int[50];
    y=new int[50];
    count=0;
    top=0;
  }
  void push(int a,int b){
    x[top]=a;
    y[top]=b;
    top+=1;
    count+=1;
  }
  int[] pop(){
    top-=1;
    int[] arr={x[top],y[top]};
    return arr;
  }
}
public class map{
  static int curx=0,cury=0,n;
  static boolean check(int a,int b,int[][] ar){
    if(a>=0&&b>=0&&a<map.n&&b<map.n&&ar[a][b]!=1&&ar[a][b]!=2)
      return true;
    return false;
  }
  public static void main(String[] args){
    stacker f= new stacker();
    Scanner s = new Scanner(System.in);
    System.out.println("Enter the size of the map");
    map.n = s.nextInt();
    int[][] a = new int[map.n][map.n];
    System.out.println("Enter the details of the map-Enter 2 for obstacles");
    for(int i=0;i<map.n;i++)
      for(int j=0;j<map.n;j++){a[i][j]=0;
        a[i][j] = s.nextInt();}
    while(curx!=map.n-1&&cury!=map.n-1){
      int bx=curx,by=cury;
      cury+=1;
      if(map.check(curx,cury,a)){
        a[curx][cury]=1;
        f.push(curx,cury);
        continue;
      }
      curx+=1;
      if(map.check(curx,cury,a)){
        a[curx][cury]=1;
        f.push(curx,cury);
        continue;
      }
      curx=bx;cury=by;
      curx+=1;
      if(map.check(curx,cury,a)){
        a[curx][cury]=1;
        f.push(curx,cury);
        continue;
      }
      cury-=1;
      if(map.check(curx,cury,a)){
        a[curx][cury]=1;
        f.push(curx,cury);
        continue;
      }
      curx=bx;cury=by;
      cury-=1;
      if(map.check(curx,cury,a)){
        a[curx][cury]=1;
        f.push(curx,cury);
        continue;
      }
      curx-=1;
      if(map.check(curx,cury,a)){
        a[curx][cury]=1;
        f.push(curx,cury);
        continue;
      }
      cury=by;
      if(map.check(curx,cury,a)){
        a[curx][cury]=1;
        f.push(curx,cury);
        continue;
      }
      cury=by+1;
      if(map.check(curx,cury,a)){
        a[curx][cury]=1;
        f.push(curx,cury);
        continue;
      }
      int[] arr=f.pop();
      curx=arr[0];
      cury=arr[1];
    }
    System.out.println("The path to be traversed is as follows:");
    for(int i=0;i<stacker.count;i++)
      System.out.println(stacker.x[i]+" "+stacker.y[i]);
  }
}
