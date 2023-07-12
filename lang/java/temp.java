public class temp implements Runnable {
    public void run () {
        System.out.println ( " hello from the custom thread ");
        try{
            Thread.sleep(100);
            System.out.println("I am awake");
        }
        catch(Exception e){
            System.out.println("damn this thread , exception kills me ");
        }
        return;
    }

    public static void main  ( String[] args ) {
        temp obj = new temp () ;
        Thread new_thread = new Thread ( obj );
        new_thread.start();
        for ( int i=0; i< 100 ; i++)
            System.out.println("this is a tester sentence");
    }
}