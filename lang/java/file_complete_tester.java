import java.io.*;
import org.apache.tika.parser.pdf.PDFParser;
import org.apache.tika.metadata.Metadata;
import org.apache.tika.parser.ParseContext;
import org.apache.tika.sax.BodyContentHandler;
import org.xml.sax.ContentHandler;
import java.awt.Desktop;
import java.net.URI;
import java.util.*;
import java.util.regex.*;

public class file_complete_tester{

  String search;

  void print_file(File f) throws Exception{
    File[] temp = f.listFiles();
    if(temp!=null){
    for(int i=0;i<temp.length;i++){
      if(temp[i].isDirectory())
        print_file(temp[i]);
      else{
        System.out.println(temp[i].getAbsolutePath());
        //Boolean b=true;
        String ex = temp[i].getAbsolutePath().substring(temp[i].getAbsolutePath().lastIndexOf('.')+1);
        System.out.println(ex);
        if(ex.equals("pdf")||ex.equals("txt"))
        string_Sea(temp[i].getAbsolutePath());
      }
    }
  }
  }

  void string_Sea(String path) throws Exception{

    Pattern pat = Pattern.compile(search);
    InputStream is = null;
    if(new File(path)!=null){
    is = new FileInputStream(new File(path));
    ContentHandler contenthandler = new BodyContentHandler();
    Metadata metadata = new Metadata();
    PDFParser pdfparser = new PDFParser();
    pdfparser.parse(is,contenthandler,metadata,new ParseContext());
    Matcher mat = pat.matcher(contenthandler.toString());
    if(mat.find()){
      System.out.println("The content has been found at index : "+mat.start());
      if(Desktop.isDesktopSupported())
        Desktop.getDesktop().open(new File(path));
    }
    else
      System.out.println("The given string could not be found ");
    if(is!=null)
      is.close();
  }}

    //File opener based on content ended .




  public static void main(String[] args) throws Exception{
    File drive = new File("E:\\");
    System.out.println("Enter the string to be searched");
    file_complete_tester temp = new file_complete_tester();
    temp.search = new Scanner(System.in).next();
    temp.print_file(drive);

  }
}
