import java.math.BigDecimal;
import java.time.LocalDateTime;
import java.util.List;

/**
 * Klasa reprezentująca pojedynczą transakcję.
 */
public class Transakcja {
    private final LocalDateTime dataCzas;
    // KOMPOZYCJA: Transakcja składa się z listy Biletów
    private final List<Bilet> bilety;
    private final BigDecimal calkowityKoszt;

    public Transakcja(List<Bilet> bilety) {
        this.dataCzas = LocalDateTime.now();
        this.bilety = bilety;
        this.calkowityKoszt = bilety.stream()
                .map(Bilet::getCena)
                .reduce(BigDecimal.ZERO, BigDecimal::add);
    }

    public LocalDateTime getDataCzas() {
        return dataCzas;
    }

    public List<Bilet> getBilety() {
        return bilety;
    }

    public BigDecimal getCalkowityKoszt() {
        return calkowityKoszt;
    }
}