import java.util.Scanner;

public class ONPCalculator {

   private static void wyswietlInstrukcje() {
       System.out.println("KALKULATOR ONP ");
       System.out.println();
       System.out.println("Obsługiwane operatory:");
       System.out.println("  +  : dodawanie");
       System.out.println("  -  : odejmowanie");
       System.out.println("  *  : mnożenie");
       System.out.println("  /  : dzielenie");
       System.out.println("  ^  : potęgowanie");
       System.out.println("  %  : modulo (reszta z dzielenia)");
       System.out.println("  !  : silnia (umieścić PRZED liczbą, np: 5!)");
       System.out.println("  r  : pierwiastek (w ONP: liczba stopień r, np: 16 2 r)");
       System.out.println();
       System.out.println("Przykładowe równania:");
       System.out.println("  (2+3)*(6-2)^2=");
       System.out.println("  (7+1)*((4-2)^2)=");
       System.out.println("  (8+1)/((4-2)^2)=");
       System.out.println("  (2+3)*(2-3)+8=");
       System.out.println();
       System.out.println("Wpisz 'stop' aby wyjść z programu");
       System.out.println();
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
       Scanner scanner = new Scanner(System.in);
       ONP onp = new ONP();


       wyswietlInstrukcje();


       while (true) {
           System.out.print("Podaj równanie: ");
           String rownanie = scanner.nextLine().trim();


           if (rownanie.equalsIgnoreCase("stop")) {
               System.out.println("Koniec działania kalkulatora!");
               break;
           }


           if (rownanie.isEmpty()) {
               System.out.println("Równanie nie może być puste!");
               System.out.println();
               continue;
           }


           try {
               String rownanieOnp = onp.przeksztalcNaOnp(rownanie);


               String wynik = onp.obliczOnp(rownanieOnp);


               wyswietlWynik(rownanie, rownanieOnp, wynik);


           } catch (ONP.InvalidEquationException e) {
               wyswietlBlad(new Exception("Nieprawidłowa postać równania: " + e.getMessage()));
           } catch (ONP.UnsupportedOperatorException e) {
               wyswietlBlad(new Exception("Nieobsługiwany operator: " + e.getMessage()));
           } catch (ONP.DivisionByZeroException e) {
               wyswietlBlad(new Exception("Błąd operacji: " + e.getMessage()));
           } catch (TabStack.StackUnderflowException e) {
               wyswietlBlad(new Exception("Błąd stosu: " + e.getMessage()));
           } catch (TabStack.StackOverflowException e) {
               wyswietlBlad(new Exception("Błąd stosu: " + e.getMessage()));
           } catch (Exception e) {
               wyswietlBlad(new Exception("Nieznany błąd: " + e.getMessage()));
           }


           System.out.println();
       }


       scanner.close();
   }
}
