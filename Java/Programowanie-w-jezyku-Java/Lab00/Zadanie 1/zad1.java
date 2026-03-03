public class Main {

    private static final int MAX_VALUE = 100;

    public static class TooLargeValueException extends RuntimeException {

        public TooLargeValueException(String message) {
            super(message);
        }
    }

    public static void checkValue(int value) {
        if (value > MAX_VALUE) {
            throw new TooLargeValueException(
                    "Błąd: podana wartość (" + value +
                            ") przekracza dozwolone maksimum (" + MAX_VALUE + ")."
            );
        }
        System.out.println("Wartość poprawna: " + value);
    }

    public static void main(String[] args) {
        checkValue(50);

        checkValue(150);
    }
}