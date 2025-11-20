package pl.kalkulator.logika;

import pl.kalkulator.struktury.StosString;

public class KonwerterONP {

    public static String konwertujNaONP(String infix) {
        StringBuilder wynik = new StringBuilder();
        StosString stos = new StosString(100);

        infix = infix.replaceAll("\\s+", "");

        int i = 0;
        while (i < infix.length()) {
            char c = infix.charAt(i);

            if (Character.isDigit(c)) {
                while (i < infix.length() && Character.isDigit(infix.charAt(i))) {
                    wynik.append(infix.charAt(i));
                    i++;
                }
                wynik.append(" ");
            } else if (c == '(') {
                stos.push("(");
                i++;
            } else if (c == ')') {
                while (!stos.isEmpty() && !stos.peek().equals("(")) {
                    wynik.append(stos.pop()).append(" ");
                }
                stos.pop();
                i++;
            } else if (isOperator(c)) {
                while (!stos.isEmpty() && !stos.peek().equals("(") &&
                        priority(stos.peek()) >= priority(String.valueOf(c))) {
                    wynik.append(stos.pop()).append(" ");
                }
                stos.push(String.valueOf(c));
                i++;
            } else {
                i++;
            }
        }

        while (!stos.isEmpty()) {
            wynik.append(stos.pop()).append(" ");
        }

        return wynik.toString().trim();
    }

    private static boolean isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    private static int priority(String op) {
        if (op.equals("+") || op.equals("-")) return 1;
        if (op.equals("*") || op.equals("/")) return 2;
        return 0;
    }
}