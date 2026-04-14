public class Main {
    public static void main(String[] args) {
        // Inicjalizacja monitora
        FileCoordinator coordinator = new FileCoordinator("dane.txt");

        // Inicjalizacja wątków
        Pisarz pisarz = new Pisarz(coordinator);
        Czytelnik czytelnik = new Czytelnik(coordinator);

        // Uruchomienie wątków
        czytelnik.start();
        pisarz.start();

        try {
            // Czekanie na zakończenie pracy obu wątków
            pisarz.join();
            czytelnik.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Koniec działania programu.");
    }
}