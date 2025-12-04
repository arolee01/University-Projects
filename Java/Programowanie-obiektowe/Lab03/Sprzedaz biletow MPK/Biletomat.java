import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Biletomat {
    private String lokalizacja;
    // KOMPOZYCJA: Biletomat posiada historię transakcji
    private List<Transakcja> historiaTransakcji;

    public Biletomat(String lokalizacja) {
        this.lokalizacja = lokalizacja;
        this.historiaTransakcji = new ArrayList<>();
    }

    public void sprzedajBilety(List<RodzajBiletu> koszyk, Pieniadz wplata) {
        // Obliczanie wartości koszyka
        BigDecimal koszt = koszyk.stream()
                .map(RodzajBiletu::getCena)
                .reduce(BigDecimal.ZERO, BigDecimal::add);

        // Weryfikacja płatności
        if (wplata.getWartosc().compareTo(koszt) < 0) {
            System.out.println("BŁĄD: Za mało środków. Koszt: " + koszt + ", Wpłacono: " + wplata.getWartosc());
            return;
        }

        // Tworzenie biletów (Biletomat tworzy obiekty Bilet)
        List<Bilet> wydrukowaneBilety = new ArrayList<>();
        for (RodzajBiletu r : koszyk) {
            wydrukowaneBilety.add(new Bilet(r));
        }

        // Rejestracja transakcji
        Transakcja nowaTransakcja = new Transakcja(wydrukowaneBilety);
        historiaTransakcji.add(nowaTransakcja);

        // Obsługa reszty (dla gotówki)
        BigDecimal reszta = wplata.getWartosc().subtract(koszt);

        System.out.println("--- DOKONANO ZAKUPU ---");
        System.out.println("Lokalizacja: " + this.lokalizacja);
        System.out.println("Kupiono biletów: " + wydrukowaneBilety.size());
        System.out.println("Kwota do zapłaty: " + koszt + " zł");
        System.out.println("Metoda płatności: " + wplata.getTypPlatnosci());

        if (wplata instanceof Gotowka) {
            System.out.println("Zapłacono: " + wplata.getWartosc() + " zł");
        }

        if (reszta.compareTo(BigDecimal.ZERO) > 0 && wplata instanceof Gotowka) {
            System.out.println("Wydaję resztę: " + reszta + " zł");
        } else if (reszta.compareTo(BigDecimal.ZERO) > 0 && wplata instanceof PlatnoscBezgotowkowa) {
            System.out.println("Pobrano z karty: " + koszt + " zł");
        } else {
            System.out.println("Brak reszty.");
        }
        System.out.println("-----------------------");
    }

    public void wydrukujTransakcje(LocalDate data) {
        System.out.println("Raport z dnia: " + data);
        boolean znaleziono = false;

        for (Transakcja t : historiaTransakcji) {
            if (t.getDataCzas().toLocalDate().equals(data)) {
                znaleziono = true;
                System.out.println("Godz: " + t.getDataCzas().format(DateTimeFormatter.ofPattern("HH:mm:ss"))
                        + " | Kwota: " + t.getCalkowityKoszt() + "zł | Bilety: " + t.getBilety());
            }
        }
        if (!znaleziono) System.out.println("Brak transakcji tego dnia.");
        System.out.println("");
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("PODSUMOWANIE BILETOMATU (").append(lokalizacja).append("):\n");
        sb.append("Data       : Rodzaj          : Liczba : Dochód\n");

        // Grupowanie po dacie i rodzaju biletu
        Map<LocalDate, Map<RodzajBiletu, List<Bilet>>> statystyki = historiaTransakcji.stream()
                .flatMap(t -> t.getBilety().stream().map(b -> Map.entry(t.getDataCzas().toLocalDate(), b)))
                .collect(Collectors.groupingBy(
                        Map.Entry::getKey,
                        Collectors.groupingBy(
                                e -> e.getValue().getRodzaj(),
                                Collectors.mapping(Map.Entry::getValue, Collectors.toList())
                        )
                ));

        statystyki.forEach((data, mapaRodzajow) -> {
            mapaRodzajow.forEach((rodzaj, listaBiletow) -> {
                int liczba = listaBiletow.size();
                BigDecimal dochod = listaBiletow.stream()
                        .map(Bilet::getCena)
                        .reduce(BigDecimal.ZERO, BigDecimal::add);

                sb.append(data).append(" : ")
                        .append(String.format("%-15s", rodzaj)).append(" : ")
                        .append(liczba).append(" szt. : ")
                        .append(dochod).append(" zł\n");
            });
        });

        return sb.toString();
    }

    public static void main(String[] args) {
        Biletomat biletomatKrakow1 = new Biletomat("Kraków, Bronowice");

        // 1. Przypadek: Kupno biletów za Gotówkę (z resztą)
        List<RodzajBiletu> koszyk1 = new ArrayList<>();
        koszyk1.add(RodzajBiletu.NORMALNY_20MIN);
        koszyk1.add(RodzajBiletu.ULGOWY_20MIN);

        Pieniadz wplataGotowka = new Gotowka(new BigDecimal("10.00"));
        biletomatKrakow1.sprzedajBilety(koszyk1, wplataGotowka);


        // 2. Przypadek: Kupno biletów Kartą
        List<RodzajBiletu> koszyk2 = new ArrayList<>();
        koszyk2.add(RodzajBiletu.NORMALNY_60MIN);

        Pieniadz wplataKarta = new PlatnoscBezgotowkowa(new BigDecimal("6.00"));
        biletomatKrakow1.sprzedajBilety(koszyk2, wplataKarta);

        // 3. Przypadek: Kupno kilku biletów (Gotówka z resztą)
        List<RodzajBiletu> koszyk3 = new ArrayList<>();
        koszyk3.add(RodzajBiletu.ULGOWY_20MIN);
        koszyk3.add(RodzajBiletu.ULGOWY_20MIN);

        Pieniadz moneta5zl = new Gotowka(new BigDecimal("5.00"));
        biletomatKrakow1.sprzedajBilety(koszyk3, moneta5zl);

        System.out.println("\nTESTOWANIE RAPORTÓW \n");

        // Wydruk transakcji z dzisiaj
        biletomatKrakow1.wydrukujTransakcje(LocalDate.now());

        // Wydruk transakcji z innej daty
        biletomatKrakow1.wydrukujTransakcje(LocalDate.of(LocalDate.now().getYear(), 12, 4));

        // Podsumowanie toString()
        System.out.println(biletomatKrakow1.toString());
    }
}