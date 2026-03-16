import java.util.Scanner;

public class ONPCalculator {
    private static void wyswietlInstrukcje() {
        System.out.println("KALKULATOR ONP ");
        System.out.println("Wpisz 'stop' aby wyjść z programu\n");
    }

    private static void wyswietlBlad(Exception e) {
        System.out.println("Blad: " + e.getMessage());
    }

    private static void wyswietlWynik(String rownanie, String onp, String wynik) {
        System.out.println("Wejście:      " + rownanie);
        System.out.println("Postać ONP:   " + onp);
        System.out.println("Wynik:        " + wynik);
    }

    public static void main(String[] args) {
        OperationHistory history = new OperationHistory();
        Scanner scanner = new Scanner(System.in);
        ONP onp = new ONP();

        wyswietlInstrukcje();

        while (true) {
            System.out.print("Podaj równanie: ");
            String rownanie = scanner.nextLine().trim();

            if (rownanie.equalsIgnoreCase("stop")) {
                try {
                    history.saveBinary("historia.dat");
                    history.saveXML("historia.xml");
                    System.out.println("Historia została zapisana do plików.");
                } catch (Exception e) {
                    System.out.println("Błąd zapisu historii: " + e.getMessage());
                }
                System.out.println("Koniec działania kalkulatora!");
                break;
            }

            if (rownanie.isEmpty()) {
                System.out.println("Równanie nie może być puste!\n");
                continue;
            }

            try {
                String rownanieOnp = onp.przeksztalcNaOnp(rownanie);
                String wynik = onp.obliczOnp(rownanieOnp);

                wyswietlWynik(rownanie, rownanieOnp, wynik);
                Operation op = new Operation(rownanie, rownanieOnp, wynik);
                history.add(op);

            } catch (Exception e) {
                wyswietlBlad(new Exception("Nieznany błąd/Błąd operacji: " + e.getMessage()));
            }
            System.out.println();
        }
        scanner.close();
    }
}
