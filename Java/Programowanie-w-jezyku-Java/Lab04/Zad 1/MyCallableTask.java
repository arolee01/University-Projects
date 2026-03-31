import java.util.concurrent.Callable;

public class MyCallableTask implements Callable<Integer> {
    private String name;
    private int value;

    public MyCallableTask(String name, int value) {
        this.name = name;
        this.value = value;
    }

    @Override
    public Integer call() throws Exception {
        int result = 0;
        System.out.println("Rozpoczynam zadanie: " + name);

        for (int i = 1; i <= 5; i++) {
            if (Thread.currentThread().isInterrupted()) {
                System.out.println(name + " zostało przerwane (isInterrupted)!");
                return null;
            }

            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(name + " przerwane podczas uśpienia (sleep interrupted)!");
                return null;
            }

            result += value * i;
        }

        System.out.println("Zakończono zadanie: " + name);
        return result;
    }

    @Override
    public String toString() {
        return name;
    }
}