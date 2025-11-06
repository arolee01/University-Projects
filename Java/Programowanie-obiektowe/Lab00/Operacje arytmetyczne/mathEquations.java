import java.util.Scanner;

public class mathEquations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Podaj x: ");
        double x = scanner.nextDouble();

        System.out.println("Podaj y: ");
        double y = scanner.nextDouble();

        double sum = x + y;
        System.out.println("Dodawanie: x + y = " + sum);

        double difference = x - y;
        System.out.println("Odejmowanie: x - y = " + difference);

        double product = x * y;
        System.out.println("Mnożenie: x * y = " + product);

        double quotient = x / y;
        System.out.println("Dzielenie: x / y = " + quotient);

        double modulo = x % y;
        System.out.println("Reszta z dzielenia: x % y = " + modulo);

        double power = Math.pow(x,y);
        System.out.println("Reszta z dzielenia: x ^ y = " + power);

        double root = Math.pow(x,1/y);
        System.out.println("Reszta z dzielenia: x ^ y = " + root);

    }
}