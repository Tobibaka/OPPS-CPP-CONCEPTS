#include <iostream>
#include <string>
using namespace std;

// Class definition
class ShoppingList {
private:
    string codes[100];   // Array to store item codes
    float prices[100];   // Array to store item prices
    int count;           // Number of items currently in the list

public:
    // Constructor to initialize count
    ShoppingList() {
        count = 0;
    }

    // Function to add an item
    void addItem(string code, float price) {
        codes[count] = code;
        prices[count] = price;
        count++;
        cout << "Item added successfully.\n";
    }

    // Function to delete an item using its code
    void deleteItem(string code) {
        int index = -1;
        for (int i = 0; i < count; i++) {
            if (codes[i] == code) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Item not found!\n";
            return;
        }

        // Shift items to remove the deleted one
        for (int i = index; i < count - 1; i++) {
            codes[i] = codes[i + 1];
            prices[i] = prices[i + 1];
        }
        count--;
        cout << "Item deleted successfully.\n";
    }

    // Function to display the total value of the list
    void displayTotal() {
        float total = 0;
        for (int i = 0; i < count; i++) {
            total += prices[i];
        }
        cout << "Total price of items in the list: " << total << endl;
    }
};

// Main function with menu
int main() {
    ShoppingList list;
    int choice;
    string code;
    float price;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Item\n";
        cout << "2. Delete Item\n";
        cout << "3. Display Total Price\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item code: ";
            cin >> code;
            cout << "Enter item price: ";
            cin >> price;
            list.addItem(code, price);
            break;

        case 2:
            cout << "Enter item code to delete: ";
            cin >> code;
            list.deleteItem(code);
            break;

        case 3:
            list.displayTotal();
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

