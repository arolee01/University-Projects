public class Main {
    public static void main(String[] args) {
        try {
            Set<Student> grupaA = new Set<>(5);
            grupaA.dodajElement(new Student("Kowalski", 101));
            grupaA.dodajElement(new Student("Nowak", 105));
            grupaA.dodajElement(new Student("Zieliński", 103));

            Set<Student> grupaB = new Set<>(5);
            grupaB.dodajElement(new Student("Nowak", 105));
            grupaB.dodajElement(new Student("Wiśniewski", 110));

            System.out.println("Grupa A: " + grupaA);
            System.out.println("Grupa B: " + grupaB);

            System.out.println("\n--- Przecięcie (część wspólna) ---");
            System.out.println(Set.przeciecie(grupaA, grupaB));

            System.out.println("\n--- Różnica (A - B) ---");
            System.out.println(Set.odejmijElementy(grupaA, grupaB));

            System.out.println("\n--- Test usuwania (usuwamy 103 z A) ---");
            grupaA.usunElement(new Student("Zieliński", 103));
            System.out.println(grupaA);

        } catch (Exception e) {
            System.err.println("Błąd: " + e.getMessage());
        }

        try {
            Set<Produkt> grupaA = new Set<>(5);
            grupaA.dodajElement(new Produkt("Maslo", 10));
            grupaA.dodajElement(new Produkt("Chleb", 4));
            grupaA.dodajElement(new Produkt("Maka", 5));

            Set<Produkt> grupaB = new Set<>(5);
            grupaB.dodajElement(new Produkt("Ryba", 50));
            grupaB.dodajElement(new Produkt("Kurczak", 30));

            System.out.println("Grupa A: " + grupaA);
            System.out.println("Grupa B: " + grupaB);

            System.out.println("\n--- Przecięcie (część wspólna) ---");
            System.out.println(Set.przeciecie(grupaA, grupaB));

            System.out.println("\n--- Różnica (A - B) ---");
            System.out.println(Set.odejmijElementy(grupaA, grupaB));

            System.out.println("\n--- Test usuwania (usuwamy 103 z A) ---");
            grupaA.usunElement(new Produkt("Zieliński", 103));
            System.out.println(grupaA);

        } catch (Exception e) {
            System.err.println("Błąd: " + e.getMessage());
        }
    }
}