import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class FileMonitor {
    private final Lock lock = new ReentrantLock();
    private final String filePath;
    private int currentLine = 0;

    public FileMonitor(String filePath) {
        this.filePath = filePath;
    }

    public EquationData readNext() {
        lock.lock();
        try {
            List<String> lines = Files.readAllLines(Paths.get(filePath));
            if (currentLine < lines.size()) {
                String equation = lines.get(currentLine);
                int id = currentLine;
                currentLine++;
                return new EquationData(id, equation);
            }
            return null;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        } finally {
            if (((ReentrantLock) lock).isHeldByCurrentThread()) {
                lock.unlock();
            }
        }
    }

    public void writeResult(int lineIndex, double result) {
        lock.lock();
        try {
            List<String> lines = Files.readAllLines(Paths.get(filePath));
            String equation = lines.get(lineIndex);

            if (equation.trim().endsWith("=")) {
                lines.set(lineIndex, equation + " " + result);
                Files.write(Paths.get(filePath), lines);
                System.out.println("Zapisano wynik do pliku dla linii " + lineIndex + ": " + result);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (((ReentrantLock) lock).isHeldByCurrentThread()) {
                lock.unlock();
            }
        }
    }
}