class din implements Runnable{
  public void run(){
    System.out.println("This is before the waiting state of the thread");
    try{wait();}
    catch(Exception e){}
    System.out.println("This is after the waiting is completed");
  }
}
public class test{
  public static void main(String[] r){
    Thread t = new Thread(new din());
    t.start();
    Thread t1 = Thread.currentThread();
    System.out.println("IN main thread before notify");
try{   t1.wait(1000);}
catch(Exception e){}
    System.out.println("After the wait method of main method ");
    t1.notify();
    System.out.println("after calling the notifyall method of the main thread");
  }
}
