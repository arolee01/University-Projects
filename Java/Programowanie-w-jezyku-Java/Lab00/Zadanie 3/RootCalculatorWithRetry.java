import java.util.Scanner;


public class RootCalculatorWithRetry {
  
   public static double calculateRoot(double a, double b) throws IllegalArgumentException {
       // Walidacja stopnia pierwiastka
       if (b == 0) {
           throw new IllegalArgumentException("Blad: Stopien pierwiastka nie może byc rowny 0!");
       }


       if (a < 0 && b % 2 == 0) {
           throw new IllegalArgumentException("Blad: Nie mozna obliczac pierwiastka parzystego stopnia z liczby ujemnej!");
       }


       if (a < 0) {
           return -Math.pow(-a, 1.0 / b);
       }


       return Math.pow(a, 1.0 / b);
   }
  
   public static void main(String[] args) {
       Scanner scanner = new Scanner(System.in);
       final int MAX_ATTEMPTS = 3;
       int attempts = 0;
       boolean success = false;


       System.out.println("=== Kalkulator pierwiastków ===");
       System.out.println("Program oblicza pierwiastek stopnia b z liczby a");
       System.out.println("Masz " + MAX_ATTEMPTS + " próby na wpisanie poprawnych danych.");
       System.out.println();


       while (attempts < MAX_ATTEMPTS && !success) {
           attempts++;
           System.out.println("--- Próba " + attempts + " z " + MAX_ATTEMPTS + " ---");


           try {
               System.out.print("Podaj liczbę a: ");
               if (!scanner.hasNextDouble()) {
                   scanner.nextLine(); // Czyszczenie bufora
                   throw new IllegalArgumentException("Błąd: Podana wartość nie jest liczbą!");
               }
               double a = scanner.nextDouble();
              
               System.out.print("Podaj stopień pierwiastka b: ");
               if (!scanner.hasNextDouble()) {
                   scanner.nextLine(); // Czyszczenie bufora
                   throw new IllegalArgumentException("Błąd: Podana wartość nie jest liczbą!");
               }
               double b = scanner.nextDouble();
              
               double result = calculateRoot(a, b);


               System.out.println();
               System.out.printf("Pierwiastek stopnia %.0f z liczby %.2f = %.6f%n", b, a, result);
               System.out.println("Program zakończył się pomyślnie!");
               success = true;


           } catch (IllegalArgumentException e) {


               System.out.println(e.getMessage());


               if (attempts < MAX_ATTEMPTS) {
                   System.out.println("Spróbuj ponownie. Pozostało " + (MAX_ATTEMPTS - attempts) + " prób(y).");
               }
               System.out.println();


           } catch (Exception e) {


               System.out.println("Błąd: Coś poszło nie tak - " + e.getMessage());


               if (attempts < MAX_ATTEMPTS) {
                   System.out.println("Spróbuj ponownie. Pozostało " + (MAX_ATTEMPTS - attempts) + " prób(y).");
               }
               System.out.println();
           }
       }


       if (!success) {
           System.out.println("Maksymalna liczba prób została wyczerpana.");
           System.out.println("Program zakańczy się z błędem.");
       }


       scanner.close();
   }
}
