import java.util.Random;

public class TicketPool {
    private final boolean[] tickets;

    public TicketPool(int size) {
        tickets = new boolean[size];
    }

    public void tryReserve(int threadId) {
        Random rand = new Random();
        int ticketId = rand.nextInt(tickets.length);

        while (tickets[ticketId]) {
            System.out.println("wątek nr " + threadId + " czeka na zwolnienie biletu nr " + ticketId);
            Thread.yield();

            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return;
            }
        }

        try {
            Thread.sleep(10);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            return;
        }

        // Rezerwacja biletu
        tickets[ticketId] = true;
        System.out.println("wątek nr " + threadId + " zarezerwował bilet nr " + ticketId);

        // Symulacja trwania rezerwacji
        try {
            Thread.sleep(200);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        } finally {
            // Zwolnienie biletu
            tickets[ticketId] = false;
            System.out.println("wątek nr " + threadId + " zwolnił rezerwację biletu nr " + ticketId);
        }
    }
}