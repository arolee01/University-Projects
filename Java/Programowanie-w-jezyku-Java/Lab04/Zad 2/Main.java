import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Main {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(3);
        List<FTask<Integer>> tasks = new ArrayList<>();

        System.out.println("\nZLECANIE ZADAŃ DO WYKONAWCY\n");
        for (int i = 1; i <= 4; i++) {
            String name = "Task_" + i;
            TimerCallable callable = new TimerCallable(name, i * 10);
            FTask<Integer> fTask = new FTask<>(callable, name);
            tasks.add(fTask);

            executor.execute(fTask);
        }

        try {
            Thread.sleep(700);

            System.out.println("\nANULOWANIE WYBRANEGO ZADANIA\n");
            System.out.println("Sygnał anulowania do: Task_2...\n");
            tasks.get(1).cancel(true);

            executor.shutdown();
            executor.awaitTermination(5, TimeUnit.SECONDS);

        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
}