public class fin{
  public void finalize(){
    System.out.println("This is the statement in the finzalize block of the code");
  }
  void prin(){
    System.out.println("This is the block in which some uselesss matter is printed just to make the difference to understand that it is different from the previous block of code which is useful for some other sort of expression\n\n");
  }
  public static void main(String[] args){
    fin n = new fin();
    n.prin();
    System.gc();
  }
}
