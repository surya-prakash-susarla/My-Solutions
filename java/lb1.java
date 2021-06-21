class lb1{
  public static void main(String[] args){
    char[] a = args[0].toCharArray();
    int i,j;
    boolean res=false;
    for(i=0,j=(a.length)-1; i<(a.length)/2&&j>=(a.length)/2;i++,j--)
      if(a[i]!=a[j]){
        System.out.println("Not palindrome");
        res=true;
        break;
      }
    if(!res)  
    System.out.println("Palindrome");
  }
}
