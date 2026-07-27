//Develop a function which throws a division by zero exception and catch it in catch block. Write a C++ program to demonstrate usage of try, catch and throw to handle exception
#include <iostream>
using namespace std;
double divide(int a, int b) {
    if (b == 0) {
        throw 333333; // throwing an integer exception
    }
    return a / b;
}
int main() {
    int num, denom;
    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> denom;
    try {
        double result = divide(num, denom);
        cout << "Result: " << result << endl;
    } catch (int errorCode) {
        cerr << "Error: Division by zero exception with code " << errorCode << endl;
    } 

    return 0;
}