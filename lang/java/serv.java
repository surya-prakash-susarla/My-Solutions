import java.net.*;
import java.util.Scanner;
class writer implements Runnable {
  int port;
  private boolean running = true;
  int size=1024;
  DatagramSocket ds;
  byte[] buffer = new byte[size];
  InetAddress add ;
  public void run(){
    while(running){
    int pos=0;
    port = 898;
    System.out.println("Enter the ip address of the receiver");
    String addr = (new Scanner(System.in)).nextLine();
    try{
     add =InetAddress.getByName(addr);
    ds = new DatagramSocket(port);}
    catch(Exception f)
    {};
    while(true){
      int c=-1;
      try{
      c = System.in.read();}
      catch(Exception e){};
      switch(c){
        case -1:
          System.out.println("The application's reader is quitting");
          stop();
        case 'r':
          break;
        case '\n':
        try{
          ds.send(new DatagramPacket(buffer,pos,add,port));}
          catch(Exception e ){};
          pos=0;
          break;
        default:
          buffer[pos++] = (byte) c;
      }
    }}
    System.out.println("Thread terminated");
  }
  public void stop(){
    running=false;
  }
}
class reader implements Runnable{
  int port;
  DatagramSocket ds;
  int size = 0124;
  byte[] buffer = new byte[size];
  public void run(){
    port=899;
    try{
    ds = new DatagramSocket(port);}
    catch(Exception e ){};
    while(true){
      DatagramPacket p =  null;
      try{
    p = new DatagramPacket(buffer, buffer.length);
    ds.receive(p);}
    catch(Exception e ){};
    System.out.println("SENT :  "+ new String(p.getData(),0,p.getLength()));
  }}
}

public class serv{
  public static void main(String[] args) throws Exception  {
    Thread send = new Thread(new writer() , "send");
    send.start();
    Thread rec = new Thread (new reader() , "rec");
    rec.start();
  }
}
