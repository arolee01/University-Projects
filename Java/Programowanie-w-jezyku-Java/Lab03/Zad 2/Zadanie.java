import java.util.concurrent.atomic.AtomicBoolean;

public class Zadanie implements Runnable {
    private final String nazwa;
    private String wynik = null;
    private StatusZadania status = StatusZadania.NOWE;
    private final AtomicBoolean anulowane = new AtomicBoolean(false);


    public Zadanie(String nazwa) {
        this.nazwa = nazwa;
    }


    @Override
    public void run() {
        status = StatusZadania.W_TRAKCIE;
        try {
            for (int i = 0; i < 5; i++) {
                if (anulowane.get()) {
                    wynik = "Anulowane";
                    status = StatusZadania.ANULOWANE;
                    return;
                }
                System.out.println(nazwa + " pracuje: krok " + (i+1));
                Thread.sleep(500); // symulacja pracy
            }
            wynik = nazwa + " zakończone pomyślnie";
            status = StatusZadania.ZAKONCZONE;
        } catch (InterruptedException e) {
            wynik = "Przerwane";
            status = StatusZadania.ANULOWANE;
        }
    }


    public void anuluj() {
        anulowane.set(true);
    }


    public boolean czyZakonczone() {
        return status == StatusZadania.ZAKONCZONE || status == StatusZadania.ANULOWANE;
    }


    public String pobierzWynik() {
        if (!czyZakonczone()) {
            return "Zadanie nadal w trakcie";
        }
        return wynik;
    }


    public String pobierzNazwe() {
        return nazwa;
    }


    public StatusZadania pobierzStatus() {
        return status;
    }
}
