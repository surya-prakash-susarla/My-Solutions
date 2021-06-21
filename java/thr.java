class ter implements Runnable{
  public void start(){
    System.out.println("In start method");
  }
  public void run(){
    start();
    System.out.println("In run method");
    stop();
  }
  public void stop(){
    System.out.println("In stop method "+Thread.currentThread().getName());
  }
}

public class thr{
  public static void main(String[] args) {
    Thread t1 = new Thread(new ter());
    t1.start();
    Thread t2 = new Thread(new ter());
    //t2.start();
  }
}
