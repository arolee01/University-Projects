import java.io.Serializable;

public class Operation implements Serializable {
    private String equation;
    private String onp;
    private String result;

    public Operation() {}

    public Operation(String equation, String onp, String result) {
        this.equation = equation;
        this.onp = onp;
        this.result = result;
    }

    public String getEquation() { return equation; }
    public void setEquation(String equation) { this.equation = equation; }
    public String getOnp() { return onp; }
    public void setOnp(String onp) { this.onp = onp; }
    public String getResult() { return result; }
    public void setResult(String result) { this.result = result; }

    public String toString() {
        return equation + " -> " + onp + " = " + result;
    }
}
