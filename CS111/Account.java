/**
 *  name    :Ariya Tangrojanakul
 *  stdid   :6609520108
 */
public class Account {

  private double balance;
  private int accountNumber;
  private static int lastAccountNumber = 0;

  public Account(double initialBalance) {
    balance = initialBalance;
    accountNumber = lastAccountNumber + 1;
    lastAccountNumber = accountNumber;
  }

  public void deposit(double depositAmount) {
    balance += depositAmount;
  }

  public boolean withdraw(double withdrawAmount) {
    if (withdrawAmount > balance) {
      System.out.println("Insufficient Funds!!!");
      return false;
    } else {
      balance -= withdrawAmount;
      return true;
    }
  }

  public double getBalance() {
    return balance;
  }

  public int getAccountNumber() {
    return accountNumber;
  }
}
