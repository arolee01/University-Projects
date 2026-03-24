import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

public class Main {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(3);

        List<MyCallableTask> tasks = new ArrayList<>();
        List<Future<Integer>> futures = new ArrayList<>();
        Random random = new Random();

        System.out.println("TWORZENIE I URUCHAMIANIE ZADAŃ\n");
        for (int i = 1; i <= 5; i++) {
            MyCallableTask task = new MyCallableTask("Task_" + i, random.nextInt(10) + 1);
            tasks.add(task);

            futures.add(executor.submit(task));
            System.out.println("Zlecono do puli: " + task);
        }
        try {
            Thread.sleep(1200);

            System.out.println("\nSTAN ZADAŃ W TRAKCIE PRACY\n");
            checkTasksStatus(tasks, futures);

            System.out.println("\nANULOWANIE ZADANIA");
            System.out.println("Próba anulowania Task_3...");
            futures.get(2).cancel(true);

            executor.shutdown();
            System.out.println("\nZAKOŃCZENIE  ZADAŃ\n");
            executor.awaitTermination(10, TimeUnit.SECONDS);

        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("\nPOBIERANIE WYNIKÓW\n");
        checkTasksStatus(tasks, futures);
    }

    private static void checkTasksStatus(List<MyCallableTask> tasks, List<Future<Integer>> futures) {
        for (int i = 0; i < futures.size(); i++) {
            Future<Integer> future = futures.get(i);
            String taskName = tasks.get(i).toString();
            System.out.print("[" + taskName + "] ");

            if (future.isCancelled()) {
                System.out.println("Stan: ANULOWANE");
            } else if (future.isDone()) {
                try {
                    System.out.println("Stan: ZAKOŃCZONE, Gotowy wynik: " + future.get());
                } catch (InterruptedException | ExecutionException e) {
                    System.out.println("Wystąpił błąd podczas pobierania wyniku.");
                }
            } else {
                System.out.println("Stan: W TRAKCIE WYKONYWANIA (lub w kolejce)");
            }
        }
    }
}