import java.math.BigDecimal;

public class Bilet {
    private final RodzajBiletu rodzaj;
    private final BigDecimal cena;

    public Bilet(RodzajBiletu rodzaj) {
        this.rodzaj = rodzaj;
        this.cena = rodzaj.getCena();
    }

    public RodzajBiletu getRodzaj() {
        return rodzaj;
    }

    public BigDecimal getCena() {
        return cena;
    }

    @Override
    public String toString() {
        return "Bilet{" + rodzaj + ", cena=" + cena + "zł}";
    }
}
