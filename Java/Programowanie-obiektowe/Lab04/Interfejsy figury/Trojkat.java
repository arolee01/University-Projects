public class Trojkat implements Figura {
    private double a, b, c; // Boki
    private double h;       // Wysokość opuszczona na a

    public Trojkat(double a, double b, double c, double h) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.h = h;
    }

    @Override
    public double obliczObwod() {
        return a + b + c;
    }

    @Override
    public double obliczPowierzchnie() {
        return 0.5 * a * h;
    }
}