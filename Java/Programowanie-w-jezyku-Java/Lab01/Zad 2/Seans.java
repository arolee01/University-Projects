import java.util.HashMap;

public class Seans {
    private String tytul;
    private String dzien;
    private String godzina;
    private int ograniczenieWiekowe;
    private HashMap<Character, HashMap<Integer, Boolean>> miejsca;

    public Seans(String tytul, String dzien, String godzina, int ograniczenieWiekowe,
                 int liczbaRzedow, int miejscaWRzedzie) {
        this.tytul = tytul;
        this.dzien = dzien;
        this.godzina = godzina;
        this.ograniczenieWiekowe = ograniczenieWiekowe;
        this.miejsca = new HashMap<>();

        for (int i = 0; i < liczbaRzedow; i++) {
            char rzad = (char) ('A' + i);
            HashMap<Integer, Boolean> rzadMap = new HashMap<>();
            for (int j = 1; j <= miejscaWRzedzie; j++) {
                rzadMap.put(j, false);
            }
            miejsca.put(rzad, rzadMap);
        }
    }

    public boolean zarezerwujMiejsce(char rzad, int numer) {
        if (miejsca.containsKey(rzad) && !miejsca.get(rzad).get(numer)) {
            miejsca.get(rzad).put(numer, true);
            return true;
        }
        return false;
    }

    public void pokazMiejsca() {
        for (Character rzad : miejsca.keySet()) {
            System.out.print(rzad + ": ");
            for (Integer m : miejsca.get(rzad).keySet()) {
                boolean zajete = miejsca.get(rzad).get(m);
                System.out.print(m + "(" + (zajete ? "X" : "O") + ") ");
            }
            System.out.println();
        }
    }

    public String getTytul() { return tytul; }
    public String getDzien() { return dzien; }
    public String getGodzina() { return godzina; }
    public int getOgraniczenieWiekowe() { return ograniczenieWiekowe; }
    public HashMap<Character, HashMap<Integer, Boolean>> getMiejsca() { return miejsca; }
}
