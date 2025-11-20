package pl.kalkulator.logika;

import pl.kalkulator.struktury.StosString;

public class KalkulatorONP {

    public static double obliczONP(String onp) {
        StosString stos = new StosString(100);
        String[] tokeny = onp.trim().split("\\s+");

        for (String token : tokeny) {
            if (isOperator(token)) {
                double b = Double.parseDouble(stos.pop());
                double a = Double.parseDouble(stos.pop());
                double wynik = execute(a, b, token);
                stos.push(String.valueOf(wynik));
            } else {
                stos.push(token);
            }
        }

        return Double.parseDouble(stos.pop());
    }

    private static boolean isOperator(String token) {
        return (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/"));
    }

    private static double execute(double a, double b, String op) {
        switch (op) {
            case "+": return a + b;
            case "-": return a - b;
            case "*": return a * b;
            case "/": return a / b;
            default: return 0;
        }
    }
}
