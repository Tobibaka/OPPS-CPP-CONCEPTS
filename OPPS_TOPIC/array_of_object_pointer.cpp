#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int roll;

    Student(string n = "", int r = 0) : name(n), roll(r) {}

    void display() const {
        cout << "Name: " << name << ", Roll: " << roll << endl;
    }
};

int main() {
    int numStudents = 2;

     // Allocate memory for an array of Student objects using a pointer
    // The new operator returns a pointer to the first element of the array.
    Student* studentArrayPtr = new Student[numStudents]{
        Student("Priya", 101),
        Student("Rajesh", 102)};

    cout << "--- Students Array (Using Pointer) ---" << endl;
    // Access array elements using array notation [] (pointer arithmetic)
    studentArrayPtr[0].display();
    studentArrayPtr[1].display();

    // Access array elements using pointer arithmetic
    (studentArrayPtr + 0)->display(); // Same as studentArrayPtr[0].display()
    (studentArrayPtr + 1)->display(); // Same as studentArrayPtr[1].display()

    // Loop through the array
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ": ";
        studentArrayPtr[i].display();
    }

    // Free the dynamically allocated memory
    delete[] studentArrayPtr;

    return 0;
}
