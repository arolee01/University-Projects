import java.io.Serializable;
import java.util.HashMap;

public class Klient implements Serializable {
    private String nazwisko;
    private String imie;
    private String mail;
    private String telefon;
    private Seans seans;
    private HashMap<Character, HashMap<Integer, Boolean>> miejscaKlienta;

    public Klient(String nazwisko, String imie, String mail, String telefon, Seans seans) {
        this.nazwisko = nazwisko;
        this.imie = imie;
        this.mail = mail;
        this.telefon = telefon;
        this.seans = seans;
        this.miejscaKlienta = new HashMap<>();
    }

    public boolean dodajMiejsce(char rzad, int numer) {
        if (seans.zarezerwujMiejsce(rzad, numer)) {
            miejscaKlienta.putIfAbsent(rzad, new HashMap<>());
            miejscaKlienta.get(rzad).put(numer, true);
            System.out.println("Miejsce " + rzad + numer + " zarezerwowane dla " + imie + " " + nazwisko);
            return true;
        } else {
            System.out.println("Miejsce " + rzad + numer + " jest już zajęte!");
            return false;
        }
    }

    public HashMap<Character, HashMap<Integer, Boolean>> getMiejscaKlienta() { return miejscaKlienta; }

    @Override
    public String toString() {
        return imie + " " + nazwisko + " | Seans: " + seans.getTytul() + " | Miejsca: " + miejscaKlienta;
    }
}
