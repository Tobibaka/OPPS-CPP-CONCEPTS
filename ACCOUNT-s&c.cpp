#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string name;
    int accNo;
    char accType;
    double balance;

public:
    Account(string n, int no, char type, double bal) {
        name = n;
        accNo = no;
        accType = type;
        balance = bal;
    }

    void deposit(double amt) {
        balance += amt;
        cout << "Deposited " << amt << ". New balance: " << balance << endl;
    }

    void displayBalance() {
        cout << "\nAccount Details\n";
        cout << "Name: " << name << "\nAccount No: " << accNo
             << "\nType: " << accType << "\nBalance: " << balance << "\n";
    }

    virtual void withdraw(double amt) = 0; // pure virtual, to be overridden
};

class Sav_Acct : public Account {
public:
    Sav_Acct(string n, int no, double bal) : Account(n, no, 'S', bal) {}

    void computeInterest() {
        double rate = 0.05; // 5%
        double interest = balance * rate; // simple interest for 1 year
        balance += interest;
        cout << "Interest of " << interest << " added. New balance: " << balance << endl;
    }

    void withdraw(double amt) override {
        if (amt > balance)
            cout << "Insufficient balance!\n";
        else {
            balance -= amt;
            cout << "Withdrew " << amt << ". New balance: " << balance << endl;
        }
    }
};

class Curr_Acct : public Account {
public:
    Curr_Acct(string n, int no, double bal) : Account(n, no, 'C', bal) {}

    void withdraw(double amt) override {
        if (amt > balance)
            cout << "Insufficient balance!\n";
        else {
            balance -= amt;
            cout << "Withdrew " << amt << ". New balance: " << balance << endl;
            checkMinBalance();
        }
    }

    void checkMinBalance() {
        double minBal = 500, penalty = 50;
        if (balance < minBal) {
            balance -= penalty;
            cout << "Penalty of " << penalty << " imposed. Balance: " << balance << endl;
        }
    }
};

int main() {
    char type;
    string name;
    int no, choice;
    double bal;

    cout << "Enter customer name : ";
    cin >> name;
    cout << "Enter account number: ";
    cin >> no;
    cout << "Enter account type (S for Savings / C for Current): ";
    cin >> type;
    cout << "Enter initial balance: ";
    cin >> bal;

    if (type == 'S' || type == 's') {
        Sav_Acct acc(name, no, bal);
        do {
            cout << "\n--- Savings Account Menu ---\n";
            cout << "1. Deposit\n2. Withdraw\n3. Compute Interest\n4. Display Balance\n5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            double amt;
            switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amt;
                acc.deposit(amt);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amt;
                acc.withdraw(amt);
                break;
            case 3:
                acc.computeInterest();
                break;
            case 4:
                acc.displayBalance();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
            }
        } while (choice != 5);
    }
    else if (type == 'C' || type == 'c') {
        Curr_Acct acc(name, no, bal);
        do {
            cout << "\n--- Current Account Menu ---\n";
            cout << "1. Deposit\n2. Withdraw\n3. Display Balance\n4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            double amt;
            switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amt;
                acc.deposit(amt);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amt;
                acc.withdraw(amt);
                break;
            case 3:
                acc.displayBalance();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
            }
        } while (choice != 4);
    }
    else {
        cout << "Invalid account type entered!\n";
    }

    return 0;
}
