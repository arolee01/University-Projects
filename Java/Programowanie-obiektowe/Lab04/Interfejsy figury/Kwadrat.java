public class Kwadrat implements Figura {
    private double a;

    public Kwadrat(double a) {
        this.a = a;
    }

    @Override
    public double obliczObwod() {
        return 4 * a;
    }

    @Override
    public double obliczPowierzchnie() {
        return a * a;
    }
}