public class Trapez implements Figura {
    private double a, b, c, d, h;

    public Trapez(double a, double b, double c, double d, double h) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.h = h;
    }

    @Override
    public double obliczObwod() {
        return a + b + c + d;
    }

    @Override
    public double obliczPowierzchnie() {
        return 0.5 * (a + b) * h;
    }
}