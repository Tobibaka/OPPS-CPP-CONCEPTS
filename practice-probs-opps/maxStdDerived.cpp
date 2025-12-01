#include <iostream>
#include <string>
using namespace std;

template <class T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Derived data type - String wrapper class with ASCII comparison
class MyString {
public:
    string str;
    MyString(string s = "") { str = s; }
    
    int getAsciiSum() const {
        int sum = 0;
        for (char c : str) {
            sum += (int)c;
        }
        return sum;
    }
        
    bool operator>(const MyString& s) const {
        return getAsciiSum() > s.getAsciiSum();  // Compare by ASCII sum
    }
    
    friend ostream& operator<<(ostream& os, const MyString& s) {
        os << s.str << " (ASCII sum: " << s.getAsciiSum() << ")";
        return os;
    }
};

int main() {
    // Standard data types
    int x = 10, y = 25;
    cout << "Max of " << x << " and " << y << ": " << findMax(x, y) << endl;
    
    float a = 3.5, b = 2.8;
    cout << "Max of " << a << " and " << b << ": " << findMax(a, b) << endl;
    
    // Derived data type - String comparison
    MyString s1("Bbcb"), s2("Bbcax");
    cout << "Max of " << s1 << " and " << s2 << ": " << findMax(s1, s2) << endl;
    
    return 0;
}
