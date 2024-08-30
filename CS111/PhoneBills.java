/**
 *  name    :Ariya Tangrojanakul
 *  stdid   :6609520108
 */
import java.util.Scanner;

public class PhoneBills {

  public static double billing(double minutes) {
    if (minutes <= 0) {
      return 0;
    }

    if (minutes < 10) {
      return minutes * 3.50;
    } else if (minutes >= 10 && minutes < 60) {
      if (minutes > 20) {
        return 60 + minutes - 20;
      } else {
        return minutes * 3;
      }
    } else {
      return minutes * 1.5;
    }
  }

  // if invalid number it will return -1 
  public static double toDouble(String str) {
    if (str.matches("[0-9]+.?[0-9]+")){
      return Double.parseDouble(str);
    }else{
      return -1;
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter minutes(Q= Quit): ");
    String minutes_string;
    double minutes;
    while (!(minutes_string = sc.next()).equalsIgnoreCase("Q")) {
      minutes = Math.ceil(toDouble(minutes_string));
      System.err.println("You have to pay " + billing(minutes));
      System.out.print("\nEnter minutes(Q= Quit): ");
    }
    sc.close();
  }
}
