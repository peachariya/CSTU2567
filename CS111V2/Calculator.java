/*Ariya Tangrojanakul
 * 6609520108
 */
import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter expression (or type 'quit' to exit): ");
            String input = scanner.nextLine().trim();

            if (input.equalsIgnoreCase("quit") || input.equalsIgnoreCase("q")) {
                break;
            }

            if (!isValidExpression(input)) {
                System.out.println("Invalid expression. Try again.");
                continue;
            }

            String operand1 = extractOperand1(input);
            String operand2 = extractOperand2(input);
            char operator = extractOperator(input);

            SimpleArithmeticExpression expr = new SimpleArithmeticExpression(operand1, operand2, operator);
            System.out.println("Result: " + expr.computeExpression());
        }
        scanner.close();
    }

    private static boolean isValidExpression(String expr) {
        return expr.matches("\\d+\\s*[+-]\\s*\\d+");
    }

    private static String extractOperand1(String expr) {
        return expr.split("[+-]")[0].trim();
    }

    private static String extractOperand2(String expr) {
        return expr.split("[+-]")[1].trim();
    }

    private static char extractOperator(String expr) {
        return expr.contains("+") ? '+' : '-';
    }
}
