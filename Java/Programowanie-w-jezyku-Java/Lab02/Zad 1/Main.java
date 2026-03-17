public class Main {
    public static void main(String[] args) {
        CustomStack<Integer> myStack = new CustomStack<>();

        System.out.println("Testowanie dodawania");
        myStack.push(10);
        myStack.push(20);
        myStack.push(30);

        System.out.println(myStack.toString());
        System.out.println("Rozmiar stosu: " + myStack.size());

        System.out.println("\nTestowanie podgladania");
        System.out.println("Na szczycie jest: " + myStack.peek());
        System.out.println("Rozmiar po peek(): " + myStack.size());

        System.out.println("\nTestowanie zdejmowania");
        System.out.println("Zdjeto: " + myStack.pop());
        System.out.println(myStack.toString());
        System.out.println("Rozmiar po pop(): " + myStack.size());

        System.out.println("\nTestowanie zabezpieczen");
        myStack.pop();
        myStack.pop();

        try {
            System.out.println("Proba zdjecia z pustego stosu...");
            myStack.pop();
        } catch (Exception e) {
            System.out.println("Blad: " + e.getClass().getSimpleName() + " - Nie mozna pobrac elementu z pustego stosu!");
        }
    }
}