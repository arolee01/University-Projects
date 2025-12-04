import java.math.BigDecimal;

public enum RodzajBiletu {
    NORMALNY_20MIN(new BigDecimal("4.00")),
    ULGOWY_20MIN(new BigDecimal("2.00")),
    NORMALNY_60MIN(new BigDecimal("6.00")),
    ULGOWY_60MIN(new BigDecimal("3.00"));

    private final BigDecimal cena;

    RodzajBiletu(BigDecimal cena) {
        this.cena = cena;
    }

    public BigDecimal getCena() {
        return cena;
    }
}