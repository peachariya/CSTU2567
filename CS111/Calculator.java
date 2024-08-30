public class Calculator {
    public static void main (String args[]) {
        SimpleMath m = new SimpleMath();

        System.out.println("PI =" + m.PI);
        System.out.println("e =" + m.e);
        System.out.println("a+b =" + m.add(10, 20));
        System.out.println("a-b =" + m.substract(10, 20));
    }


}
