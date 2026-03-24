import java.util.ArrayList;
import java.util.List;


public class ManagerZadan {
    private final List<Zadanie> zadania = new ArrayList<>();
    private final List<Thread> watki = new ArrayList<>();


    public void dodajZadanie(Zadanie z) {
        zadania.add(z);
        Thread t = new Thread(z);
        watki.add(t);
        t.start();
    }


    public void pokazZadania() {
        System.out.println("\nLista Zadań\n");
        for (int i = 0; i < zadania.size(); i++) {
            Zadanie z = zadania.get(i);
            System.out.println(i + ": " + z.pobierzNazwe() + " | Status: " + z.pobierzStatus() + " | Wynik: " + (z.czyZakonczone() ? z.pobierzWynik() : "W trakcie"));
        }
    }


    public void anulujZadanie(int index) {
        if (index >= 0 && index < zadania.size()) {
            Zadanie z = zadania.get(index);
            z.anuluj();
            watki.get(index).interrupt();
        } else {
            System.out.println("Nieprawidłowy indeks zadania");
        }
    }


    public int liczbaZadan() {
        return zadania.size();
    }


    public Zadanie pobierzZadanie(int index) {
        if (index >= 0 && index < zadania.size()) {
            return zadania.get(index);
        }
        return null;
    }
}
