/*Ariya Tangrojanakul
 * 6609520108
 */
public class Triangle {
    private int a, b, c;

    // Constructor
    public Triangle(int a, int b, int c) {
        if (isValidTriangle(a, b, c)) {
            this.a = a;
            this.b = b;
            this.c = c;
        } else {
            throw new IllegalArgumentException("Invalid triangle sides.");
        }
    }

    // Setter Methods
    public void setSides(int a, int b, int c) {
        if (isValidTriangle(a, b, c)) {
            this.a = a;
            this.b = b;
            this.c = c;
        } else {
            System.out.println("Invalid triangle sides.");
        }
    }

    // Getter Methods
    public int getA() { return a; }
    public int getB() { return b; }
    public int getC() { return c; }

    // ตรวจสอบว่าด้านทั้ง 3 สามารถเป็นสามเหลี่ยมได้หรือไม่
    private boolean isValidTriangle(int a, int b, int c) {
        return (a > 0 && b > 0 && c > 0) &&
               (a + b > c) && (a + c > b) && (b + c > a);
    }

    // คำนวณพื้นที่สามเหลี่ยมโดยใช้สูตรเฮรอน (Heron's formula)
    public double getArea() {
        double s = (a + b + c) / 2.0;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    // ตรวจสอบว่าสามเหลี่ยมเป็นมุมฉากหรือไม่
    public boolean isRightTriangle() {
        int longest = Math.max(a, Math.max(b, c));
        int x, y;

        if (longest == a) {
            x = b; y = c;
        } else if (longest == b) {
            x = a; y = c;
        } else {
            x = a; y = b;
        }

        return Math.pow(longest, 2) == Math.pow(x, 2) + Math.pow(y, 2);
    }
}
