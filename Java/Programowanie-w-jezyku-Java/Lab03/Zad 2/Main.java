public class Main {
    public static void main(String[] args) throws InterruptedException {
        ManagerZadan manager = new ManagerZadan();


        Zadanie z1 = new Zadanie("Zadanie 1");
        Zadanie z2 = new Zadanie("Zadanie 2");
        Zadanie z3 = new Zadanie("Zadanie 3");


        manager.dodajZadanie(z1);
        manager.dodajZadanie(z2);
        manager.dodajZadanie(z3);


        Thread.sleep(1000);
        manager.pokazZadania();


        System.out.println("\nAnulowanie Zadania 2...\n");
        manager.anulujZadanie(1);


        Thread.sleep(3000);
        manager.pokazZadania();
    }
}
