import java.util.Scanner;

public class Pisarz extends Thread {
    private final FileCoordinator coordinator;

    public Pisarz(FileCoordinator coordinator) {
        this.coordinator = coordinator;
    }

    @Override
    public void run() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Pisarz gotowy. Wpisz tekst (wpisz 'koniec' aby zakończyć):");

        while (true) {
            String line = scanner.nextLine();
            coordinator.writeLine(line);
            if ("koniec".equalsIgnoreCase(line)) {
                break;
            }
        }
        scanner.close();
    }
}