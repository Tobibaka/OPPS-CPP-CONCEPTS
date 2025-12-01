#include <iostream>
using namespace std;

int main() {
    int a, b;
    char op;

    cout << "Enter first integer (a): ";
    cin >> a;
    cout << "Enter second integer (b): ";
    cin >> b;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    switch (op) {
        case '+':
            cout << "Result: " << (a + b) << "\n";
            break;
        case '-':
            cout << "Result: " << (a - b) << "\n";
            break;
        case '*':
            cout << "Result: " << (a * b) << "\n";
            break;
        case '/':
            if (b != 0)
                cout << "Result: " << (a / b) << "\n";
            else
                cout << "Error is division by zero" ;
            break;
        default:
            cout << "Invalid operator";
    }

    return 0;
}
