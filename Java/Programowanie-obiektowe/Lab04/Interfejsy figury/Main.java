import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Kwadrat
        System.out.println("Podaj bok kwadratu:");
        double bok = scanner.nextDouble();
        Figura kwadrat = new Kwadrat(bok);

        // Trójkąt
        System.out.println("Podaj boki trójkąta (a, b, c) oraz wysokość (h):");
        double tA = scanner.nextDouble();
        double tB = scanner.nextDouble();
        double tC = scanner.nextDouble();
        double tH = scanner.nextDouble();
        Figura trojkat = new Trojkat(tA, tB, tC, tH);

        // Trapez
        System.out.println("Podaj podstawy (a, b), ramiona (c, d) oraz wysokość (h) trapezu:");
        double trA = scanner.nextDouble();
        double trB = scanner.nextDouble();
        double trC = scanner.nextDouble();
        double trD = scanner.nextDouble();
        double trH = scanner.nextDouble();
        Figura trapez = new Trapez(trA, trB, trC, trD, trH);

        // Wyniki
        wyswietlWynik("Kwadrat", kwadrat);
        wyswietlWynik("Trójkąt", trojkat);
        wyswietlWynik("Trapez", trapez);

        scanner.close();
    }

    private static void wyswietlWynik(String nazwa, Figura f) {
        System.out.println("\n--- " + nazwa + " ---");
        System.out.println("Obwód: " + f.obliczObwod());
        System.out.println("Pole: " + f.obliczPowierzchnie());
    }
}