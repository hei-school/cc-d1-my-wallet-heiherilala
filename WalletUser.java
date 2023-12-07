package java;
import java.util.ArrayList;
import java.util.List;

class WalletUser {
    String username;
    String password;
    double balance;
    List<String> transactions;

    public WalletUser(String username, String password) {
        this.username = username;
        this.password = password;
        this.balance = 0.0;
        this.transactions = new ArrayList<>();
    }
}
