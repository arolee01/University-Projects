import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

public class FTask<T> extends FutureTask<T> {
    private String taskName;

    public FTask(Callable<T> callable, String taskName) {
        super(callable);
        this.taskName = taskName;
    }

    @Override
    protected void done() {
        try {
            if (isCancelled()) {
                System.out.println("[Słuchacz] Zadanie " + taskName + " ANULOWANE");
                return;
            }

            T result = this.get();
            System.out.println("[Słuchacz] Zadanie " + taskName + " WYKONANE Gotowy wynik: " + result);

        } catch (InterruptedException | ExecutionException e) {
            System.out.println("[Słuchacz] Zadanie " + taskName + " zakończone z błędem.");
        }
    }
}