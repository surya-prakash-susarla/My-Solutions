class lb3{
  public static void main(String[] args){
    String s1 = "hello world";
    String s2 = "THIS IS JAVA";
    System.out.println(" equals() : "+ s1.equals(s2) +
                        "\n compareTo() :"+s1.compareTo(s2)+
                        "\n substring() :"+s1.substring(2,7)+
                        "\n indexOf() :"+s1.indexOf('w')+
                        "\n toLowerCase() :"+s2.toLowerCase());
  }
}
