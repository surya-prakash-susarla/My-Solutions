import java.util.Scanner;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.Jsoup;
import java.io.IOException;

public class temp {
  public static void main (String [] args) {
    String temp_input = ( new Scanner(System.in) ) . nextLine() ;
                String final_city = null;
                for ( int i=0 ;i<temp_input.length() ;i ++){
                    if ( final_city==null)
                        final_city = ""+temp_input.charAt(i);
                    else{
                        if ( temp_input.charAt(i)==' ')
                            final_city += "%20";
                        else
                            final_city += temp_input.charAt(i);
                    }
                }
                final String final_query = "https://query.yahooapis.com/v1/public/yql?q=select*from%20geo.places%20where%20text=\""+final_city+"\"&format=xml";
              System.out.println ( final_query );

              Document document = null;
             try {
                 document = Jsoup.connect(final_query).get();
             } catch (IOException e) {
                 e.printStackTrace();
             }
            // System.out.println (document.toString() );
            Element e = document.select ("woeid").first();
            System.out.println ( e.text() );
            String woeid = e.text();
            Document final_doc = null ;
            try {
              System.out.println (  "https://query.yahooapis.com/v1/public/yql?q=select%20item.condition%20from%20weather.forecast%20where%20woeid%20%3D%20"+woeid+"%20and%20u%3D%27c%27&format=xml");
              final_doc= Jsoup.connect ("https://query.yahooapis.com/v1/public/yql?q=select%20item.condition%20from%20weather.forecast%20where%20woeid%20%3D%20"+woeid+"%20and%20u%3D%27c%27&format=xml").get();
            }
            catch ( Exception ef ) {
              ef.printStackTrace();
            }

            System.out.println ( final_doc.toString());

            Element final_element = final_doc . select ( "[xmlns:yweather=\"http://xml.weather.yahoo.com/ns/rss/1.0\"]" ).first();
            String value = final_element.attr ("temp");
            System.out.println (" content inside \n\n\n");
            System.out.println(value);
            //System.out.println (final_element.text());

  }
}
