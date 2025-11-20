public class Main {
    static void main() {
        Point p1 = new Point();
        Point p2 = new Point(3, 4);
        System.out.println("Point 1: " + p1);
        System.out.println("Point 2: " + p2);

        p1.setX(1);
        p1.setY(2);

        System.out.println("Point 1: " + p1);
    }
}