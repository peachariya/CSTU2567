/*Ariya Tangrojanakul
 * 6609520108
 */
import java.math.BigInteger;

public class SimpleArithmeticExpression {
    private BigInteger operand1;
    private BigInteger operand2;
    private char operator;

    public SimpleArithmeticExpression(String op1, String op2, char operator) {
        this.operand1 = new BigInteger(op1);
        this.operand2 = new BigInteger(op2);
        this.operator = operator;
    }

    public String computeExpression() {
        BigInteger result;
        if (operator == '+') {
            result = operand1.add(operand2);
        } else {
            result = operand1.subtract(operand2);
        }
        return formatResult(result);
    }

    private String formatResult(BigInteger result) {
        String str = result.toString();
        boolean isNegative = str.startsWith("-");

        if (isNegative) {
            str = str.substring(1);
        }

        StringBuilder sb = new StringBuilder();
        int count = 0;
        for (int i = str.length() - 1; i >= 0; i--) {
            sb.append(str.charAt(i));
            count++;
            if (count % 3 == 0 && i > 0) {
                sb.append(",");
            }
        }
        String formatted = sb.reverse().toString();
        return isNegative ? "-(" + formatted + ")" : formatted;
    }
}
