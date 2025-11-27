#include <iostream>
using namespace std;

class student {
private:
    int roll;
    char name;   

public:
    void get_data() {
        cout << "Enter roll number and name : ";
        cin >> roll >> name;
    }
    friend void put_data(student s);
};
void put_data(student s) {
        cout << "Roll number: " << s.roll << endl;
        cout << "Name       : " << s.name << endl;
    }

int main() {
    student s;

    s.get_data(); 
    put_data(s);

    return 0;
}
