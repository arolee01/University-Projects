import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class TicketReservationTest {
    public static void main(String[] args) throws InterruptedException {
        int numberOfTickets = 3;
        int numberOfThreads = 8;

        TicketPool pool = new TicketPool(numberOfTickets);

        ExecutorService executor = Executors.newFixedThreadPool(numberOfThreads);
        List<Future<?>> futures = new ArrayList<>();

        System.out.println("Uruchamianie systemu rezerwacji...");

        for (int i = 1; i <= numberOfThreads; i++) {
            Future<?> future = executor.submit(new ClientTask(i, pool));
            futures.add(future);
        }

        Thread.sleep(2000);

        System.out.println("\n--- Próba przerwania pojedynczego wątku (wątek nr 1) ---");
        futures.get(0).cancel(true);

        Thread.sleep(1000);

        System.out.println("\n--- Przerywanie wszystkich pozostałych wątków ---");
        executor.shutdownNow();
    }
}