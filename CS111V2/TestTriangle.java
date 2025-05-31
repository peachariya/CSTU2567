/*Ariya Tangrojanakul
 * 6609520108
 */
public class TestTriangle {
    public static void main(String[] args) {
        Triangle t1 = new Triangle(3, 4, 5);

        System.out.printf("Area of Triangle with sides (%.2f, %.2f, %.2f) = %.2f\n",
                (double) t1.getA(), (double) t1.getB(), (double) t1.getC(), t1.getArea());

        if (t1.isRightTriangle()) {
            System.out.println("The triangle is a right triangle.");
        } else {
            System.out.println("The triangle is NOT a right triangle.");
        }
    }
}0

