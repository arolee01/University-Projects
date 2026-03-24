public class ClientTask implements Runnable {
    private final int id;
    private final TicketPool pool;

    public ClientTask(int id, TicketPool pool) {
        this.id = id;
        this.pool = pool;
    }

    @Override
    public void run() {
        // Główna pętla wątku - działa dopóki nie zostanie przerwana
        while (!Thread.currentThread().isInterrupted()) {
            pool.tryReserve(id);

            // Odpoczynek przed kolejną próbą rezerwacji
            try {
                Thread.sleep(150);
            } catch (InterruptedException e) {
                // Koniec pracy wątku poprzez zakończenie jego kodu
                Thread.currentThread().interrupt();
                System.out.println("Wątek nr " + id + " został przerwany i kończy pracę.");
                return;
            }
        }
    }
}