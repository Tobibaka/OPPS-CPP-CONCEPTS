#include <iostream>
using namespace std;

double divide(int a, int b) {
    if (b == 0) {
        throw "Division by zero error!";
    }
    return a / b;
}

int main() {
    int num1, num2;
    
    cout << "Enter numerator: ";
    cin >> num1;
    cout << "Enter denominator: ";
    cin >> num2;
    
    try {
        double result = divide(num1, num2);
        cout << "Result: " << result << endl;
    }
    catch (const char* msg) {
        cout << "Exception caught: " << msg << endl;
    }
    
    cout << "Program continues after exception handling." << endl;
    
    return 0;
}
