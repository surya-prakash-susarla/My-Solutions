class cloner implements Cloneable{
  String name;
  cloner(String name){
    this.name = name;
  }
  void getName(){
    System.out.println(name);
  }
  public Object clone() throws CloneNotSupportedException{
    return this;
  }
}
public class cl{
  public static void main(String[] args) throws Exception{
    cloner name = new cloner("sura prakash susarla");
    cloner n1 = (cloner)name.clone();
    cloner n2 = (cloner) name.clone();
    n1.getName();
    n2.getName();
  }
}
