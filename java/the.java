class it extends Thread{
  it(){
    start();
  }
  public void run(){
    for(int i=0;i<100;i++)
    System.out.println("Running");
    for(int i=0;i<3;i++)
      System.out.println();
    Thread.currentThread().setName("Killer");
    Thread.currentThread().setPriority(6);
    System.out.println(Thread.currentThread().getState()+" "+Thread.currentThread().getName()+" "+Thread.currentThread().getPriority());
  }
}

public class the{
  public static void main(String[] args) {
    new it();
  }
}
