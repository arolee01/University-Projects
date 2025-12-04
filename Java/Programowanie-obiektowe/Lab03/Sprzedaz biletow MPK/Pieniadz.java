import java.math.BigDecimal;
import java.util.Arrays;
import java.util.List;



//POLIMORFIZM: Klasa bazowa dla środków płatniczych.
abstract class Pieniadz {
    protected BigDecimal wartosc;

    public Pieniadz(BigDecimal wartosc) {
        this.wartosc = wartosc;
    }

    public BigDecimal getWartosc() {
        return wartosc;
    }

    public abstract String getTypPlatnosci();
}

// DZIEDZICZENIE: Gotowka dziedziczy po klasie Pieniadz
class Gotowka extends Pieniadz {
    private static final List<BigDecimal> NOMINALY_PLN = Arrays.asList(
            new BigDecimal("0.01"),
            new BigDecimal("0.02"),
            new BigDecimal("0.05"),
            new BigDecimal("0.10"),
            new BigDecimal("0.20"),
            new BigDecimal("0.50"),
            new BigDecimal("1.00"),
            new BigDecimal("2.00"),
            new BigDecimal("5.00"),
            new BigDecimal("10.00"),
            new BigDecimal("20.00"),
            new BigDecimal("50.00"),
            new BigDecimal("100.00"),
            new BigDecimal("200.00"),
            new BigDecimal("500.00")
    );

    public Gotowka(BigDecimal wartosc) {
        super(wartosc);
    }

    @Override
    public String getTypPlatnosci() {
        return "Gotówka";
    }
}

// DZIEDZICZENIE: Płatność bezgotówkowa dziedziczy po klasie Pieniadz
class PlatnoscBezgotowkowa extends Pieniadz {
    public PlatnoscBezgotowkowa(BigDecimal kwotaDoZaplaty) {
        super(kwotaDoZaplaty);
    }

    @Override
    public String getTypPlatnosci() {
        return "Karta/BLIK";
    }
}