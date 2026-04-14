import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class ONP {

    public static double evaluate(String eq) {
        eq = eq.replace("=", "").trim();

        eq = eq.replace("(", " ( ").replace(")", " ) ")
                .replace("+", " + ").replace("-", " - ")
                .replace("*", " * ").replace("/", " / ")
                .replace("^", " ^ ");

        String[] tokens = eq.trim().split("\\s+");

        List<String> output = new ArrayList<>();
        Stack<String> ops = new Stack<>();

        for (String t : tokens) {
            if (t.isEmpty()) continue;

            if (t.matches("\\d+(\\.\\d+)?")) { // Liczby
                output.add(t);
            } else if (t.equals("(")) {
                ops.push(t);
            } else if (t.equals(")")) {
                while (!ops.isEmpty() && !ops.peek().equals("(")) {
                    output.add(ops.pop());
                }
                ops.pop();
            } else {
                while (!ops.isEmpty() && precedence(ops.peek()) >= precedence(t)) {
                    output.add(ops.pop());
                }
                ops.push(t);
            }
        }
        while (!ops.isEmpty()) {
            output.add(ops.pop());
        }

        Stack<Double> eval = new Stack<>();
        for (String t : output) {
            if (t.matches("\\d+(\\.\\d+)?")) {
                eval.push(Double.parseDouble(t));
            } else {
                double b = eval.pop();
                double a = eval.pop();
                switch (t) {
                    case "+": eval.push(a + b); break;
                    case "-": eval.push(a - b); break;
                    case "*": eval.push(a * b); break;
                    case "/": eval.push(a / b); break;
                    case "^": eval.push(Math.pow(a, b)); break;
                }
            }
        }
        return eval.pop();
    }

    private static int precedence(String op) {
        if (op.equals("+") || op.equals("-")) return 1;
        if (op.equals("*") || op.equals("/")) return 2;
        if (op.equals("^")) return 3;
        return -1;
    }
}