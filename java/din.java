class stick{
  boolean taken = false;
  public synchronized void take(){
    while(taken){
    try{ wait();}
    catch(Exception e){}
    }
    taken=true;
  }
  public synchronized void drop(){
    taken=false;
    notifyAll();
  }
}

class phil implements Runnable{
  int num;
  stick left;
  stick right;
  phil(int a, stick left , stick right){
    num = a;
    this.left = left;
    this.right = right;
  }
  public void run(){
    while(!Thread.interrupted()){
      if(left.taken==false&&right.taken==false)
      left.take();
      System.out.println("---Left Stick taken by +"+num+" Philosopher ---");
      right.take();
      System.out.println("---Right Stick taken by +"+num+" Philosopher ---");
      System.out.println("###Both sticks taken by Philosopher #"+num+" ###");
      try{wait(150);}
      catch(Exception e){}
      left.drop();
      right.drop();
      System.out.println(num+" Philosopher has dropped both the sticks and is back in the queue");
    }
  }
}
public class din {
  public static void main(String[] args){
    stick[] sticks = new stick[5];
    phil[] phils = new phil[5];
    for(int i=0;i<5;i++)  sticks[i] = new stick();
    for(int i=0;i<5;i++) phils[i] = new phil(i+1,sticks[i],sticks[(i+1)%5]);
    Thread[] t = new Thread[5];
    for(int i=0;i<5;i++){
      t[i] = new Thread(phils[i]);
      t[i].start();
    }
  }
}
