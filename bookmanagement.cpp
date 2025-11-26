#include <iostream>
using namespace std;

class books {
private:
    char* author;
    char* title;
    char* publisher;
    float price;
    int stock;

public:
    // Constructor - using new operator to allocate memory
    books() {
        author = new char[50];
        title = new char[100];
        publisher = new char[50];
        author[0] = 0;
        title[0] = 0;
        publisher[0] = 0;
        price = 0.0;
        stock = 0;
    }

    // Destructor - to free allocated memory
    ~books() {
        delete[] author;
        delete[] title;
        delete[] publisher;
    }

    // Function to input book details
    void getDetails() {
        cout << "\nEnter Book Details:\n";
        cout << "Title: ";
        cin >> title;
        cout << "Author: ";
        cin >> author;
        cout << "Publisher: ";
        cin >> publisher;
        cout << "Price:";
        cin >> price;
        cout << "Stock: ";
        cin >> stock;
    }

    // Function to compare two strings
    bool compareStrings(char* str1, char* str2) {
        int i = 0;
        while (str1[i] != 0 && str2[i] != 0) {
            if (str1[i] != str2[i]) {
                return false;
            }
            i++;
        }
        return (str1[i] == 0 && str2[i] == 0);
    }

    // Function to search book by title and author
    bool search(char* searchTitle, char* searchAuthor) {
        if (compareStrings(title, searchTitle) && compareStrings(author, searchAuthor)) {
            return true;
        }
        return false;
    }

    // Function to display book details
    void displayDetails() {
        cout << "\n--- Book Details ---\n";
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price <<"/-" << endl;
        cout << "Stock Available: " << stock << " copies\n";
    }

    // Function to process purchase    
    void purchaseBook() {
        int required;
        cout << "\nEnter number of copies required: ";
        cin >> required;

        if (required <= stock) {
            float totalCost = price * required;
            cout << "\nBooks available!\n";
            cout << "Total Cost: $" << totalCost << endl;
            stock -= required;
            cout << "Updated Stock: " << stock << " copies\n";
        } else {
            cout << "\nRequired copies not in stock\n";
            cout << "Available copies: " << stock << endl;
        }
    }
};

int main() {
    int totalBooks = 0;
    int maxBooks = 20;
    cout << "==================================\n";
    cout << "  BOOK SHOP INVENTORY SYSTEM\n";
    cout << "==================================\n";

    // Using new operator to allocate memory for array of books
    books* inventory = new books[maxBooks];

    int choice;
    do {
        cout << "\n\n--- MENU ---\n";
        cout << "1. Add Book to Inventory\n";
        cout << "2. Search and Purchase Book\n";
        cout << "3. Display All Books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (totalBooks < maxBooks) {
                    cout << "\n--- Add Book " << (totalBooks + 1) << " ---";
                    inventory[totalBooks].getDetails();
                    totalBooks++;
                    cout << "\nBook added successfully!\n";
                } else {
                    cout << "\nInventory is full!\n";
                }
                break;
            }

            case 2: {
                if (totalBooks == 0) {
                    cout << "\nNo books in inventory. Please add books first.\n";
                    break;
                }

                char* searchTitle = new char[100];
                char* searchAuthor = new char[50];

                cout << "\n--- Search for a Book ---\n";
                cout << "Enter Title: ";
                cin >> searchTitle;
                cout << "Enter Author: ";
                cin >> searchAuthor;

                bool found = false;
                for (int i = 0; i < totalBooks; i++) {
                    if (inventory[i].search(searchTitle, searchAuthor)) {
                        found = true;
                        cout << "\nBook is available!\n";
                        inventory[i].displayDetails();
                        inventory[i].purchaseBook();
                        break;
                    }
                }

                if (!found) {
                    cout << "\nBook is not available in the inventory.\n";
                }

                delete[] searchTitle;
                delete[] searchAuthor;
                break;
            }

            case 3: {
                if (totalBooks == 0) {
                    cout << "\nNo books in inventory.\n";
                } else {
                    cout << "\n--- All Books in Inventory ---\n";
                    for (int i = 0; i < totalBooks; i++) {
                        cout << "\nBook " << (i + 1) << ":";
                        inventory[i].displayDetails();
                    }
                }
                break;
            }

            case 4: {
                cout << "\nThank you for visiting!\n";
                break;
            }

            default: {
                cout << "\nInvalid choice! Please try again.\n";
                break;
            }
        }

    } while (choice != 4);

    // Free allocated memory
    delete[] inventory;

    return 0;
}
