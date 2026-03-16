import com.thoughtworks.xstream.XStream;
import com.thoughtworks.xstream.io.xml.DomDriver;
import java.io.FileWriter;

public class Utils {
    public static String objectToXml(Object obj) {
        XStream xstream = new XStream(new DomDriver());
        xstream.allowTypesByWildcard(new String[] {"*"});
        return xstream.toXML(obj);
    }

    public static void saveToXmlFile(Object obj, String filename) {
        try (FileWriter writer = new FileWriter(filename)) {
            writer.write(objectToXml(obj));
            System.out.println("Dane zapisane do pliku XML: " + filename);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
