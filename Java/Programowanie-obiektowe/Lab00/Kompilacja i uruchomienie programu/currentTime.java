import java.time.LocalTime;
import java.time.LocalDate;

public class currentTime {
    public static void main(String[] args) {
        LocalDate todaysDate = LocalDate.now();
        LocalTime actualTime = LocalTime.now();

        System.out.println("Aktualna data: " + todaysDate);
        System.out.println("Aktualny czas: " + actualTime);
    }
}