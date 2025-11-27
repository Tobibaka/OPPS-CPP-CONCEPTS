#include <iostream>
using namespace std;

class Number {
private:
    int value;
public:
    Number(int v) {value = v;}
    friend int add(Number a, Number b);
};

int add(Number a, Number b) {
    return a.value + b.value;  
}
int main() {
    cout << "=== ADD TWO NUMBERS USING FRIEND FUNCTION ===" << endl;
    
    cout << "Enter both numbers: ";
    int x, y;
    cin >> x >> y;
    Number num1(x), num2(y);
    int result = add(num1, num2);
    cout << "\nSum using friend function: " << result << endl;
    return 0;
}