import java.io.*;
import java.beans.XMLEncoder;
import java.util.ArrayList;

public class OperationHistory {
    private ArrayList<Operation> history = new ArrayList<>();

    public void add(Operation op) {
        history.add(op);
    }

    public void saveBinary(String filename) throws IOException {
        ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(filename));
        out.writeObject(history);
        out.close();
    }

    public void saveXML(String filename) throws IOException {
        XMLEncoder encoder = new XMLEncoder(new BufferedOutputStream(new FileOutputStream(filename)));
        encoder.writeObject(history);
        encoder.close();
    }
}
