class Produkt implements Comparable<Produkt> {
    private String nazwa;
    private double cena;

    public Produkt(String nazwa, double cena) {
        this.nazwa = nazwa;
        this.cena = cena;
    }

    @Override
    public int compareTo(Produkt inny) {
        return Double.compare(this.cena, inny.cena);
    }

    @Override
    public String toString() {
        return nazwa + ": " + cena + "zl";
    }
}