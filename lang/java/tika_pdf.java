import java.io.*;
import org.apache.tika.parser.pdf.PDFParser;
import org.apache.tika.metadata.Metadata;
import org.apache.tika.parser.ParseContext;
import org.apache.tika.sax.BodyContentHandler;
import org.xml.sax.ContentHandler;
import java.util.Scanner;
import java.util.regex.*;
public class tika_pdf{
  public static void main(String[] r) throws Exception{
    InputStream is = null;
    is = new FileInputStream("JAVA SIZE.pdf");
    ContentHandler contenthandler = new BodyContentHandler();
    Metadata metadata = new Metadata();
    PDFParser pdfparser = new PDFParser();
    pdfparser.parse(is,contenthandler,metadata,new ParseContext());
    System.out.println("Enter any string to be seaerched");
    String temp;
    temp = (new Scanner(System.in)).next();
    Pattern pat = Pattern.compile(temp);
    Matcher mat = pat.matcher(contenthandler.toString());
    if(mat.find()){
      System.out.println("Th content has been found at index : "+mat.start());
    }
    else
      System.out.println("The given string could not be found ");
    if(is!=null)
      is.close();
  }
}
