#include <iostream>
#include <string>

using namespace std;

// Base Class 1
class Teacher {
public:
    void teach() const {
        cout << "Teacher is teaching." << endl;
    }
};

// Base Class 2
class Researcher {
public:
    void research() const {
        cout <<"Researcher is conducting research." << endl;
    }
};

// Derived Class (inherits from two base classes)
class Professor : public Teacher, public Researcher {
private:
    string name;

public:
// Constructor with parameter to initialize name and display creation message
    Professor(string n) { 
        name=n;
        cout << "Professor " << name << " created." << endl;
    }

    void work() const {
        cout << name << " is a Professor and performs both roles:" << endl;
        teach();
        research();
    }
};

int main() {
    Professor prof("Dr. Kalita");
    prof.work();

    return 0;
}
