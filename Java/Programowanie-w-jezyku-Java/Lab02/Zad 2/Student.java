class Student implements Comparable<Student> {
    private String nazwisko;
    private int album;

    public Student(String nazwisko, int album) {
        this.nazwisko = nazwisko;
        this.album = album;
    }

    @Override
    public int compareTo(Student inny) {
        return Integer.compare(this.album, inny.album);
    }

    @Override
    public String toString() {
        return nazwisko + " (" + album + ")";
    }
}
