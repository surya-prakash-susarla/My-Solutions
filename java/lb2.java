class lb2{
  public static void main(String[] args){
    int[] c;
    int[] a = {2,5,7,8,9};
    int[] b = {1,3,4,6,11};
    c = new int[(a.length+b.length)];
    for(int i=0;i<a.length;i++)         c[i]=a[i];  
    for(int i=a.length,j=0;j<b.length;i++,j++)  c[i]=b[j];
    int s = a.length+b.length;
    for(int i=0;i<s;i++)
    for(int j=0;j<s-1;j++)
    if(c[j]>c[j+1]){
      int temp=c[j];
      c[j]=c[j+1];
      c[j+1]=temp;
    }
    for(int t : c)
      System.out.println(t);
  }
}
