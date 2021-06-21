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
class se{
  Vector<String> v = new Vector<String>();
  public void findFile(String name, File file) throws Exception{
    File[] list = file.listFiles();
    if(list!=null)
    for(File fil:list){
      if(fil.isDirectory())
        findFile(name,fil);
      else if(name.equalsIgnoreCase(fil.getName())){
        System.out.println(fil.getParentFile());
        v.add(fil.getParentFile().getAbsolutePath()+"\\"+name);
      }
    }
}

void string_Sea() throws Exception{
  //File opener based on content begins here
    String search;
    System.out.println("Enter the string to be searched");
    Scanner s = new Scanner(System.in);
    search = s.next();
    Pattern pat = Pattern.compile(search);
    for(int i=0;i<v.size();i++){
      InputStream is = null;
      is = new FileInputStream(v.get(i));
      ContentHandler contenthandler = new BodyContentHandler();
      Metadata metadata = new Metadata();
      PDFParser pdfparser = new PDFParser();
      pdfparser.parse(is,contenthandler,metadata,new ParseContext());
      Matcher mat = pat.matcher(contenthandler.toString());
      if(mat.find()){
        System.out.println("The content has been found at index : "+mat.start());
        if(Desktop.isDesktopSupported())
          Desktop.getDesktop().open(new File(v.get(i)));
      }
      else
        System.out.println("The given string could not be found ");
      if(is!=null)
        is.close();
    }

    //File opener based on content ended .
  }
  public static void main(String[] a) throws Exception{
    se ff = new se();
    Scanner s = new Scanner(System.in);
    System.out.println("Enter the file to be searched..");
    String name = s.next();
    System.out.println("Enter the directory where to search ");
    String directory = s.next();
    ff.findFile(name,new File(directory));
    ff.string_Sea();
  }
}
