package composition;

public class CompositionTest {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Person jan = new Person("Jan Kowalski", "Prosta 54","30111","Krakow");
        Person maria = new Person("Maria Kowalska", "Prosta 54","30111","Krakow");

        System.out.println(jan);
        System.out.println(maria.formatForMailing());

        // Add constructor to the Person class so that the following lines compiles correctly
        Address podzamcze22 = new Address("Podzamcze 22","00033","Warszawa");
        Person adam = new Person("Adam Nowak", podzamcze22);
        Person rozalia = new Person("Rozalia Nowak", podzamcze22);
        System.out.println(adam);
        System.out.println(rozalia.formatForMailing());
    }
}