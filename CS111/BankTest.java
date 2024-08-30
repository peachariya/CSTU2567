import java.util.ArrayList;
import java.util.Scanner;

public class BankTest {

    public static void printAccount(Account account){
        if (account == null) return;
        System.out.println("\tAccount number: " + account.getAccountNumber());
        System.out.println("\tAccount balance: " + account.getBalance() + '\n');
    }
    
    public static void printAccount(ArrayList<Account> account){
        if (account == null) return;
        for (Account acc : account) {
            printAccount(acc);
        }
    }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Bank bank = new Bank();
    String text = "Choosing number :\n" +
                    "1 : Add account\n" +
                    "2 : Find account at specified index\n" +
                    "3 : Find min, max and amount of balance that equals or greater\n" +
                    "4 : Add interest to all account\n" +
                    "5 : Show Total and Average balance of all accounts\n" +
                    "Q : Exit";
    System.out.println(text);
    System.out.print("Enter choice: ");
    String choice;
    while (!(choice = sc.next()).equalsIgnoreCase("Q")) {
      if (choice.matches("[1-5]|Q|q")) {
        switch (choice) {
            case "1":
                System.out.print("\tEnter initial balance: ");
                bank.addAccount(new Account(sc.nextInt()));
                break;
            
            case "2":
                System.out.print("\tEnter index of account: ");
                int index = sc.nextInt();
                printAccount(bank.getAccount(index));
                break;

            case "3":
                System.out.print("\tEnter amount: ");
                double amount = sc.nextDouble();
                System.out.println("\t<===== Account details with balance greater than or equal to the amount =====>");
                printAccount(bank.findAccounts(amount));
                System.out.println("\n\t<===== Account details with min balance  =====>");
                printAccount(bank.findMin());
                System.out.println("\n\t<===== Account details with max balance  =====>");
                printAccount(bank.findMax());
                break;

            case "4":
                bank.addInterest();
                printAccount(bank.getAccountList());
                break;

            case "5":
              System.out.println("\tTotal balance: " + bank.getTotal());
                System.out.println("\tAverage balance: " + bank.getAverage());
                break;

            default:
                break;
        }
      }
      System.out.println(text);
      System.out.print("Enter choice: ");
    }
    sc.close();
  }
}
