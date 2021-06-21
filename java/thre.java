public class thre implements Runnable{
  public void run(){
    System.out.println("FUCK!!!!!!!!!!!!!!");
  }
  public static void main(String[] args) throws Exception{
    Thread t1 = new Thread(new thre());
    Thread t2 = new Thread(new thre());
    Thread t = Thread.currentThread();
    t1.start();
    t2.start();
    t.join();
    System.out.println("After the completion of execution of the child threads");
  }
}
