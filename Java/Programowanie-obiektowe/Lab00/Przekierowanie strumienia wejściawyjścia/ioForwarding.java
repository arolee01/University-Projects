import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalTime;
import java.time.LocalDate;

public class ioForwarding {

    public static void main(String[] args) {

        String outputFile = "output.txt";

        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
             PrintWriter writer = new PrintWriter(new FileWriter(outputFile))) {

            writer.println(LocalDate.now());
            writer.println(LocalTime.now());

            String line1 = reader.readLine();
            System.out.println("Pierwsza linia: " + line1);
            writer.println(line1);

            String line2 = reader.readLine();
            System.out.println("Druga linia: " + line2);
            writer.println(line2);

            System.out.println("Zapisano dane do pliku: " + outputFile);

        } catch (IOException e) {
            System.err.println("Wystąpił błąd operacji I/O: " + e.getMessage());
        }
    }
}