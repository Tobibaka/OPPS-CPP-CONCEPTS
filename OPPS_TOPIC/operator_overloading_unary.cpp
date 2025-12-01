#include <iostream>
using namespace std;
// What is unary operator overloading?
// Unary operators operate on a single operand. Common unary operators include negation (-), increment (++
// and decrement (--). By overloading these operators, you can define custom behavior for your classes
class Number {
private:
    int num;
public:
    Number(int n = 0) : num(n) {}
    // Overloading unary minus (-) operator
    // This makes a number negative
    Number operator-() {
        return Number(-num);
    }
    void display() {
        cout << "Number: " << num << endl;
    }
};
int main() {
    int x;
    cout << "Enter an integer: ";
    cin >> x;
    Number n1(x);
    
    cout << "Original number: ";
    n1.display();  // Prints: Number: 10

    // Using unary minus operator
    Number n2 = -n1;  // Makes it negative
    
    cout << "After using (-) operator: ";
    n2.display();  // Prints: Number: -10

    return 0;
}
