public class Czytelnik extends Thread {
    private final FileCoordinator coordinator;

    public Czytelnik(FileCoordinator coordinator) {
        this.coordinator = coordinator;
    }

    @Override
    public void run() {
        while (true) {
            String line = coordinator.readLine();
            if (line != null) {
                System.out.println("-> Czytelnik odczytał z pliku: " + line);
                if ("koniec".equalsIgnoreCase(line)) {
                    break;
                }
            }
        }
    }
}