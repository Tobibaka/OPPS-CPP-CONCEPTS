//add 2 complex number using friend function 
#include <iostream>
using namespace std;
class Complex {
private:
    float real;
    float imag;
public:
    Complex(float r=0 , float i=1 ) : real(r), imag(i) {}
    float getReal()  { return real; }
    float getImag()  { return imag; }   
    Complex operator+( Complex other){
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
        //here real is using "this" and other.real is using parameter object...
    }
    friend Complex addComplex(Complex c1,  Complex c2);
    friend Complex operator-( Complex c1,  Complex c2);
};
Complex operator-( Complex c1,  Complex c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
    //it cannot use "this" pointer because it's a friend function, not a member function
}
Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}
int main() {
    //input from user 
    Complex c;
    cout<< c.getReal()<< c.getImag();
    float r1, i1, r2, i2;
    cout << "Enter real and imaginary parts of first complex number: ";
    cin >> r1 >> i1;
    cout << "Enter real and imaginary parts of second complex number: ";
    cin >> r2 >> i2;
    Complex c1(r1, i1);
    Complex c2(r2, i2);
    Complex c3 = addComplex(c1, c2);
    Complex c4 = c1 + c2; // Using overloaded + operator
    if ( i1+i2 >= 0)
        cout << "Sum of Complex Numbers (using friend function): " << c3.getReal() << " + " << c3.getImag() << "i" << endl;
     else
        cout << "Sum of Complex Numbers (using friend function): " << c3.getReal() << " - " << -c3.getImag() << "i" << endl;
    if ( i1+i2 >= 0)
        cout << "Sum of Complex Numbers (using operator+): "  << c4.getReal() << " + " << c4.getImag() << "i" << endl;
    else
        cout << "Sum of Complex Numbers (using operator+): " << c4.getReal() << " - " << -c4.getImag() << "i" << endl;
    if ( i1-i2 >= 0)
        cout << "Difference of Complex Numbers (using operator-): " << (c1 - c2).getReal() << " + " << (c1 - c2).getImag() << "i" << endl;
    else
        cout << "Difference of Complex Numbers (using operator-): " << (c1 - c2).getReal() << " - " << -(c1 - c2).getImag() << "i" << endl;
    return 0;
}