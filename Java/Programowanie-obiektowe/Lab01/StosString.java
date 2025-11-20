package pl.kalkulator.struktury;

public class StosString {
    private String[] tablica;
    private int wierzcholek;

    public StosString(int size) {
        this.tablica = new String[size];
        this.wierzcholek = -1;
    }

    public void push(String value) {
        tablica[++wierzcholek] = value;
    }

    public String pop() {
        return tablica[wierzcholek--];
    }

    public String peek() {
        return tablica[wierzcholek];
    }

    public boolean isEmpty() {
        return wierzcholek == -1;
    }

    public int size() {
        return wierzcholek + 1;
    }

    public String podglądWierzchołka() {
        if (wierzcholek >= 0) {
            return tablica[wierzcholek];
        }
        return null;
    }
}