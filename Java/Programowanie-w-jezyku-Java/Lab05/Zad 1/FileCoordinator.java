import java.io.*;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class FileCoordinator {
    private boolean isNewData = false;
    private final Lock lock = new ReentrantLock();
    // Warunki (Conditions) do koordynacji wątków
    private final Condition dataWritten = lock.newCondition();
    private final Condition dataRead = lock.newCondition();
    private final File file;
    private int linesRead = 0;

    public FileCoordinator(String fileName) {
        this.file = new File(fileName);
        // Czyszczenie pliku przy starcie programu
        if (file.exists()) {
            file.delete();
        }
    }

    // Metoda dla Pisarza
    public void writeLine(String text) {
        lock.lock();
        try {
            // Czekaj, dopóki nowa linia nie zostanie odczytana
            while (isNewData) {
                dataRead.await();
            }

            // Zapisz do pliku
            try (PrintWriter out = new PrintWriter(new FileWriter(file, true))) {
                out.println(text);
            } catch (IOException e) {
                e.printStackTrace();
            }

            // Ustaw flagę i powiadom Czytelnika
            isNewData = true;
            dataWritten.signal();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        } finally {
            lock.unlock();
        }
    }

    // Metoda dla Czytelnika
    public String readLine() {
        lock.lock();
        try {
            // Czekaj, dopóki nie ma nowej linii do odczytu
            while (!isNewData) {
                dataWritten.await();
            }

            String text = null;
            // Odczytaj z pliku z pominięciem starych linii
            try (BufferedReader br = new BufferedReader(new FileReader(file))) {
                for (int i = 0; i <= linesRead; i++) {
                    text = br.readLine();
                }
                linesRead++;
            } catch (IOException e) {
                e.printStackTrace();
            }

            // Zmień flagę i powiadom Pisarza
            isNewData = false;
            dataRead.signal();
            return text;
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            return null;
        } finally {
            lock.unlock();
        }
    }
}