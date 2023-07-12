public class inter extends Thread{
  public void run(){
    Thread t = Thread.currentThread();
    System.out.println(t.getName());
  }
  public static void main(String[] args) {
    inter a = new inter();
    a.start();
  }
}
