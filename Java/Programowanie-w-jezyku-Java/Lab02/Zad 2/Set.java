import java.util.Arrays;

public class Set<T extends Comparable<T>> {
    private T[] set;
    private int pojemnosc;
    private int rozmiar;


    public Set(int pojemnosc) {
        this.pojemnosc = pojemnosc;
        this.rozmiar = 0;
        this.set = (T[]) new Comparable[pojemnosc];
    }

    public int szukaj(T obiekt) {
        for (int i = 0; i < rozmiar; i++) {
            if (set[i].compareTo(obiekt) == 0) return i;
        }
        return -1;
    }

    public void dodajElement(T element) throws Exception {
        if (szukaj(element) != -1) return;
        if (rozmiar >= pojemnosc) throw new Exception("Zbior jest pelny!");

        int i = rozmiar - 1;
        while (i >= 0 && set[i].compareTo(element) > 0) {
            set[i + 1] = set[i];
            i--;
        }
        set[i + 1] = element;
        rozmiar++;
    }

    public void usunElement(T element) {
        int index = szukaj(element);
        if (index != -1) {
            for (int i = index; i < rozmiar - 1; i++) {
                set[i] = set[i + 1];
            }
            set[rozmiar - 1] = null;
            rozmiar--;
        }
    }

    public static <T extends Comparable<T>> Set<T> dodajElementy(Set<T> s1, Set<T> s2) throws Exception {
        Set<T> wynik = new Set<>(s1.pojemnosc + s2.pojemnosc);
        for (int i = 0; i < s1.rozmiar; i++) wynik.dodajElement(s1.set[i]);
        for (int i = 0; i < s2.rozmiar; i++) wynik.dodajElement(s2.set[i]);
        return wynik;
    }

    public static <T extends Comparable<T>> Set<T> odejmijElementy(Set<T> s1, Set<T> s2) throws Exception {
        Set<T> wynik = new Set<>(s1.pojemnosc);
        for (int i = 0; i < s1.rozmiar; i++) {
            if (s2.szukaj(s1.set[i]) == -1) {
                wynik.dodajElement(s1.set[i]);
            }
        }
        return wynik;
    }

    public static <T extends Comparable<T>> Set<T> przeciecie(Set<T> s1, Set<T> s2) throws Exception {
        Set<T> wynik = new Set<>(Math.min(s1.pojemnosc, s2.pojemnosc));
        for (int i = 0; i < s1.rozmiar; i++) {
            if (s2.szukaj(s1.set[i]) != -1) {
                wynik.dodajElement(s1.set[i]);
            }
        }
        return wynik;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Zbiór [Rozmiar: ").append(rozmiar).append(", Pojemność: ").append(pojemnosc).append("]\n");
        sb.append("Elementy: ");
        for (int i = 0; i < rozmiar; i++) {
            sb.append(set[i]).append(i == rozmiar - 1 ? "" : ", ");
        }
        return sb.toString();
    }
}