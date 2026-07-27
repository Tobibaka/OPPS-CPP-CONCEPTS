#include <iostream>
using namespace std;
class FLOAT{
    float num; 
public:
    FLOAT(float n) : num(n) {}
    void getValue(FLOAT n) {
        cout << "Value: " << n.num << endl;
    }
    FLOAT operator+(FLOAT n) {
        return FLOAT(num + n.num);
    }
    FLOAT operator-(FLOAT n) {
        return FLOAT(num - n.num);
    }
    friend FLOAT operator*(FLOAT a, FLOAT b);
    FLOAT operator/(FLOAT n) {
        return FLOAT(num / n.num);
    }
};

FLOAT operator*(FLOAT a, FLOAT b) {
    return FLOAT(a.num * b.num);
}

int main() {
    FLOAT num1(5), num2(3);
    FLOAT sum = num1 + num2;
    sum.getValue(sum);
    FLOAT diff = num1 - num2;
    diff.getValue(diff);
    FLOAT prod = num1 * num2;
    prod.getValue(prod);
    FLOAT quot = num1 / num2;
    quot.getValue(quot);
    return 0;
}

