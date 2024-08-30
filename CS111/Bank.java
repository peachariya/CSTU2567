/**
 *  name    :
 *  stdid   :
 */
import java.util.ArrayList;

public class Bank {

  ArrayList<Account> accountList;

  public Bank() {
    accountList = new ArrayList<Account>();
  }

  public ArrayList<Account> getAccountList() {
    return accountList;
  }

  public void addAccount(Account account) {
    accountList.add(account);
  }

  public Account getAccount(int index) {
    if (index < 0 || index >= accountList.size()) {
        System.err.println("Invalid index");
        return null;
    }
    return accountList.get(index);
  }

  public ArrayList<Account> findAccounts(double amount) {
    ArrayList<Account> accounts = new ArrayList<Account>();
    for (Account account : accountList) {
      if (account.getBalance() >= amount) {
        accounts.add(account);
      }
    }
    return accounts.isEmpty() ? null : accounts;
  }

  public Account findMin() {
    if (accountList.isEmpty()) return null;

    double min = Double.MAX_VALUE;
    Account minAccount = null;
    for (Account account : accountList) {
      if (account.getBalance() < min) {
        min = account.getBalance();
        minAccount = account;
      }
    }
    return minAccount;
  }

  public Account findMax() {
    if (accountList.isEmpty()) return null;

    double max = Double.MIN_VALUE;
    Account maxAccount = null;
    for (Account account : accountList) {
      if (account.getBalance() > max) {
        max = account.getBalance();
        maxAccount = account;
      }
    }
    return maxAccount;
  }

  public void addInterest() {
    for (Account account : accountList) {
      account.deposit(account.getBalance() * 0.03);
    }
  }

  public double getTotal() {
    double total = 0;
    for (Account account : accountList) {
      total += account.getBalance();
    }
    return total;
  }

  public double getAverage() {
    return getTotal() / accountList.size();
  }
}
