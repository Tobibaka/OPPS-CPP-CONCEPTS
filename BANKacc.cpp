#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string name;
    long long accountNo;
    string type;
    long long balance;

public:
    void assignValues(string n, long long acc, int t, long long bal) {
        name = n;
        accountNo = acc;
        type = (t == 1) ? "Saving" : "Current";
        balance = bal;
    }

    void deposit(long long amount) {
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
    }

    void withdraw(long long amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn " << amount << ". New balance: " << balance << endl;
        }
    }

    void display() {
        cout << "Name: " << name 
             << ", Account No: " << accountNo 
             << ", Type: " << type 
             << ", Balance: " << balance << endl;
    }
};

int main() {
    const int MAX = 10;
    BankAccount customers[MAX];

    int numCustomers;
    cout << "How many customers do you want to enter (1-" << MAX << ")? ";
    cin >> numCustomers;

    if (numCustomers < 1 || numCustomers > MAX) {
        cout << "Invalid number of customers!" << endl;
        return 0;
    }

    // Input only for chosen number of customers
    for (int i = 0; i < numCustomers; i++) {
        string name;
        long long acc, bal;
        int t;

        cout << "\nEnter details for Customer " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Account No: ";
        cin >> acc;
        cout << "Press 1 for Saving, 2 for Current: ";
        cin >> t;
        cout << "Initial Balance: ";
        cin >> bal;

        customers[i].assignValues(name, acc, t, bal);
    }

    int choice, custNo;
    do {
        cout << "\nMenu:\n1. Deposit\n2. Withdraw\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 4) break;

        cout << "Enter customer number (1-" << numCustomers << "): ";
        cin >> custNo;

        if (custNo < 1 || custNo > numCustomers) {
            cout << "Invalid customer number!" << endl;
            continue;
        }

        int index = custNo - 1;
        long long amount;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                customers[index].deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                customers[index].withdraw(amount);
                break;
            case 3:
                customers[index].display();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (true);

    return 0;
}
