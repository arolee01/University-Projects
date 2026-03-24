import java.util.concurrent.Callable;

public class TimerCallable implements Callable<Integer> {
    private String name;
    private int baseValue;

    public TimerCallable(String name, int baseValue) {
        this.name = name;
        this.baseValue = baseValue;
    }

    @Override
    public Integer call() throws Exception {
        System.out.println("[Praca] Rozpoczynam obliczenia w: " + name);
        int result = 0;

        for (int i = 1; i <= 3; i++) {
            // Sprawdzenie flagi przerwania
            if (Thread.currentThread().isInterrupted()) {
                System.out.println("[Praca] " + name + " przerwane (isInterrupted)!");
                return null;
            }

            try {
                Thread.sleep(500); // Symulacja pracy zajmującej czas
            } catch (InterruptedException e) {
                System.out.println("[Praca]" + name + " uśpienie przerwane (sleep interrupted)!");
                return null;
            }

            result += baseValue * i;
        }

        System.out.println("[Praca] Kończę zadanie: " + name);
        return result;
    }
}