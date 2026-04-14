import java.io.PrintWriter;
import java.util.concurrent.*;

class EquationData {
    int id;
    String equation;

    public EquationData(int id, String equation) {
        this.id = id;
        this.equation = equation;
    }
}

class ReaderTask implements Callable<EquationData> {
    private final FileMonitor monitor;

    public ReaderTask(FileMonitor monitor) {
        this.monitor = monitor;
    }

    @Override
    public EquationData call() {
        return monitor.readNext();
    }
}

class CalcFutureTask extends FutureTask<Double> {
    private final int lineIndex;
    private final FileMonitor monitor;

    public CalcFutureTask(Callable<Double> callable, int lineIndex, FileMonitor monitor) {
        super(callable);
        this.lineIndex = lineIndex;
        this.monitor = monitor;
    }

    @Override
    protected void done() {
        try {
            double result = this.get();
            monitor.writeResult(lineIndex, result);
        } catch (InterruptedException | ExecutionException e) {
            e.printStackTrace();
        }
    }
}



public class Main {
    public static void main(String[] args) {
        String fileName = "rownania.txt";

        FileMonitor monitor = new FileMonitor(fileName);
        ExecutorService exec = Executors.newFixedThreadPool(4);

        System.out.println("Rozpoczynam przetwarzanie pliku...");

        while (true) {
            try {
                Future<EquationData> readerFuture = exec.submit(new ReaderTask(monitor));
                EquationData data = readerFuture.get();

                if (data == null) {
                    break;
                }

                System.out.println("Odczytano równanie (linia " + data.id + "): " + data.equation);

                Callable<Double> calcCallable = () -> ONP.evaluate(data.equation);

                CalcFutureTask calcTask = new CalcFutureTask(calcCallable, data.id, monitor);
                exec.execute(calcTask);

            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        exec.shutdown();
        try {
            exec.awaitTermination(5, TimeUnit.SECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Wszystkie zadania zostały zakończone. Sprawdź plik " + fileName);
    }
}