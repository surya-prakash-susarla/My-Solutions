class th implements Runnable{
  public void run(){
    Thread t = Thread.currentThread();
    System.out.println(t.getPriority());
    t.setPriority(Thread.MIN_PRIORITY);
    System.out.println(t.getPriority());

  }
}
public class pri{
  public static void main(String[] args) {
    Thread t = new Thread ( new th());
    t.start();
  }
}
