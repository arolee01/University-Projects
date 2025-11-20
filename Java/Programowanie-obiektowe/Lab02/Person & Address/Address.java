package composition;

/**
 * Describes a mailing address.
 */
public class Address {

    private String street;
    private String zipcode;
    private String city;

    /**
     * Creates a mailing address.
     * @param street  the street
     * @param zipcode the zip postal code
     * @param city    the city
     */
    public Address(String street, String zipcode, String city){
        this.street = street;
        this.zipcode = zipcode;
        this.city = city;
    }
    public String getStreet() {
        return street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public String getZipcode() {
        return zipcode;
    }

    public void setZipcode(String zipcode) {
        this.zipcode = zipcode;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }
    /**
     * formats the address in single line
     * @return a string containing the address
     */
    @Override
    public String toString() {
        return street + ", " + zipcode + " " + city ;
    }
    /**
     * formats the address for mailing
     * @return a string containing the address in mailing list format
     */
    public String formatForMailing(){
        return street + "\n" + zipcode + " " + city;
    }
}
