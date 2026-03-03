import java.util.Scanner;


class PierwiastekLiczby {
   public static void main(String[] args) {
       Scanner scanner = new Scanner(System.in);
       int proby = 3;


       while (proby > 0) {
           try {
               System.out.print("Podaj liczbę: ");
               double liczba = scanner.nextDouble();


               if (liczba < 0) {
                   throw new IllegalArgumentException("Nie można obliczyć pierwiastka z liczby ujemnej");
               }


               double wynik = Math.sqrt(liczba);
               System.out.println("Pierwiastek podanej liczby : " + wynik);
               break;


           }
           catch (IllegalArgumentException e)
           {
               proby--;
               System.out.println("Błąd: " + e.getMessage());


           }
           catch (Exception e)
           {
               proby--;
               System.out.println("Nieprawidłowe dane");
               scanner.next();
           }


           if (proby > 0) {
               System.out.println("Pozostałe próby: " + proby);
           }
           else
           {
               System.out.println("Wykorzystano limit prób.");
           }
       }
       scanner.close();
   }
}
