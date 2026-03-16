import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Seans seans = new Seans("Avatar", "Poniedziałek", "18:00", 12, 5, 10);
        Klient k1 = new Klient("Kowalski", "Jan", "jan@mail.com", "123456789", seans);

        k1.dodajMiejsce('A', 3);
        k1.dodajMiejsce('A', 4);
        k1.dodajMiejsce('A', 3);

        System.out.println("\nStan miejsc w sali:");
        seans.pokazMiejsca();

        ArrayList<Klient> klienci = new ArrayList<>();
        klienci.add(k1);

        Utils.saveToXmlFile(klienci, "klienci.xml");

        String xml = Utils.objectToXml(klienci);
        System.out.println("\n=== XML ===\n" + xml);
    }
}
