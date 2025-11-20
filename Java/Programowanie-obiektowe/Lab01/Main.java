package pl.kalkulator.main;
import pl.kalkulator.logika.KalkulatorONP;
import pl.kalkulator.logika.KonwerterONP;

public class Main {

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Komenda do przykładowego wywołania programu: java pl.kalkulator.main.Main \"3*(11-9)/4=\"");
            return;
        }

        for (String arg : args) {
            if (!arg.endsWith("=")) {
                System.err.println("Błąd: Równanie \"" + arg + "\" nie kończy się znakiem '='");
                continue;
            }

            String wyrazenie = arg.substring(0, arg.length() - 1).trim();

            try {
                String onp = KonwerterONP.konwertujNaONP(wyrazenie);
                double wynik = KalkulatorONP.obliczONP(onp);

                System.out.println("Wyrażenie: " + wyrazenie);
                System.out.println("ONP: " + onp);
                System.out.println("Wynik: " + wynik);
                System.out.println();
            } catch (Exception e) {
                System.err.println("Błąd: " + e.getMessage());
            }
        }
    }
}
