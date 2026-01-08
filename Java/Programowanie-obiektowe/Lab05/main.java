class Punkt2D {
    private double x;
    private double y;

    public Punkt2D() {
        this.x = 0;
        this.y = 0;
    }

    public Punkt2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public String pobierzWspolrzedne() {
        return "(" + x + ", " + y + ")";
    }

    // Przesłonięcie metody toString
    @Override
    public String toString() {
        return "Obiekt klasy Punkt2D: " + pobierzWspolrzedne();
    }
}

class Punkt3D extends Punkt2D {
    private double z;

    public Punkt3D(double x, double y, double z) {
        super(x, y);
        this.z = z;
    }

    public double getZ() {
        return z;
    }

    public void setZ(double z) {
        this.z = z;
    }

    @Override
    public String pobierzWspolrzedne() {
        return "(" + getX() + ", " + getY() + ", " + z + ")";
    }

    @Override
    public String toString() {
        return "Obiekt klasy Punkt3D: " + pobierzWspolrzedne();
    }
}

class Punkt3DzEtykieta extends Punkt3D {
    private String etykieta;

    public Punkt3DzEtykieta(double x, double y, double z, String etykieta) {
        super(x, y, z);
        this.etykieta = etykieta;
    }

    public String getEtykieta() {
        return etykieta;
    }

    public void setEtykieta(String etykieta) {
        this.etykieta = etykieta;
    }

    @Override
    public String pobierzWspolrzedne() {
        return super.pobierzWspolrzedne() + " [" + etykieta + "]";
    }

    @Override
    public String toString() {
        return "Obiekt klasy Punkt3DzEtykieta: " + pobierzWspolrzedne();
    }
}

public class Main {
    public static void main(String[] args) {

        Punkt2D[] tablicaPunktow = new Punkt2D[3];

        // Polimorfizm: Do zmiennej typu Punkt2D przypisujemy obiekty różnych klas pochodnych.
        tablicaPunktow[0] = new Punkt2D(1.5, 2.0);
        tablicaPunktow[1] = new Punkt3D(3.0, 4.0, 5.0);
        tablicaPunktow[2] = new Punkt3DzEtykieta(10.0, 20.0, 30.0, "Przykladowa etykieta");


        for (Punkt2D p : tablicaPunktow) {
            // Polimorfizm: Mimo że zmienna p jest typu Punkt2D, wywołana jest metoda
            // odpowiednia dla typu obiektu (2D, 3D lub Etykieta).
            System.out.println(p.toString());
        }
    }
}