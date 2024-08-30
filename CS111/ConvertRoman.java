/**
 *  name    :Ariya Tangrojanakul
 *  stdid   :6609520108
 */
import java.util.Scanner;

public class ConvertRoman {

  public static String getRomanInput(Scanner scanner) {
    String roman = scanner.nextLine();
    return roman;
  }

  public static void romanToNumber(String roman) {
    switch (roman) {
      case "I":
        System.err.println("this is One");
        break;
      case "II":
        System.err.println("this is Two");
        break;
      case "III":
        System.err.println("this is Three");
        break;
      case "IV":
        System.err.println("this is Four");
        break;
      case "V":
        System.err.println("this is Five");
        break;
      case "VI":
        System.err.println("this is Six");
        break;
      default:
        System.err.println("Unknown Number");
        break;
    }
  }

  public static void main(String[] args) {
    System.err.print("Input the roman number: ");
    Scanner sc = new Scanner(System.in);
    String roman = "";
    while (!(roman = getRomanInput(sc)).equalsIgnoreCase("Q")) {
      romanToNumber(roman);
      System.out.print("\nInput the roman number: ");
    }
    sc.close();
  }
}
