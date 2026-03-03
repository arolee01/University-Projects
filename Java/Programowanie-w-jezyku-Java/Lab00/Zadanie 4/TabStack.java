public class TabStack {
   private String[] stack = new String[20];
   private int size = 0;
   private final int MAX_SIZE = 20;


   /**
    * Wyjątek - przepełnienie stosu
    */
   public static class StackOverflowException extends Exception {
       public StackOverflowException(String message) {
           super(message);
       }
   }


   /**
    * Wyjątek - pobranie z pustego stosu
    */
   public static class StackUnderflowException extends Exception {
       public StackUnderflowException(String message) {
           super(message);
       }
   }


   /**
    * Wyjątek - nieprawidłowy indeks
    */
   public static class InvalidIndexException extends Exception {
       public InvalidIndexException(String message) {
           super(message);
       }
   }


   /**
    * Metoda zdejmująca wartość ze stosu
    * @return wartość z góry stosu
    * @throws StackUnderflowException jeśli stos jest pusty
    */
   public String pop() throws StackUnderflowException {
       if (size == 0) {
           throw new StackUnderflowException("Błąd: Stos jest pusty! Nie można pobrać wartości.");
       }
       size--;
       return stack[size];
   }


   /**
    * Metoda dokładająca na stos
    * @param a - wartość dokładana do stosu
    * @throws StackOverflowException jeśli stos jest pełny
    */
   public void push(String a) throws StackOverflowException {
       if (size >= MAX_SIZE) {
           throw new StackOverflowException("Błąd: Stos jest pełny! Nie można dodać wartości.");
       }
       stack[size] = a;
       size++;
   }


   /**
    * Metoda zwraca tekstową reprezentację stosu
    */
   public String toString() {
       String tmp = "";
       for (int i = 0; i < size; i++)
           tmp += stack[i] + " ";
       return tmp;
   }


   /**
    * Metoda zwraca rozmiar stosu
    * @return size rozmiar stosu
    */
   public int getSize() {
       return size;
   }


   /**
    * Ustawia wartość stosu
    * @param i nowy rozmiar stosu
    */
   public void setSize(int i) {
       size = i;
   }


   /**
    * Metoda zwraca wartość z określonej pozycji stosu
    * @param i pozycja parametru do zobaczenia
    * @return wartość stosu lub null jeśli indeks jest poza zakresem
    * @throws InvalidIndexException jeśli indeks jest ujemny lub poza zakresem
    */
   public String showValue(int i) throws InvalidIndexException {
       if (i < 0 || i >= size) {
           throw new InvalidIndexException("Błąd: Indeks " + i + " jest poza zakresem stosu!");
       }
       return stack[i];
   }
}
