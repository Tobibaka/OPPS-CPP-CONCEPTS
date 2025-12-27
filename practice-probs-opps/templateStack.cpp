#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;
public:
    Stack(int size = 10) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }
    
    ~Stack() {
        delete[] arr;
    }
             
    void push(T value) {
        if (top >= capacity - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack." << endl;
    }
    
    T pop() {
        if (top < 0) {
            cout << "Stack underflow!" << endl;
           // return T();
        }
        return arr[top--];
    }
    
    bool isEmpty() {
        return top < 0;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Integer stack
    Stack<int> intStack(5);
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();
    cout << "Popped: " << intStack.pop() << endl;
    intStack.display();
    
    cout << "\n";
    
    // Float stack
    Stack<float> floatStack(3);
    floatStack.push(1.5);
    floatStack.push(2.7);
    floatStack.display();
    cout << "Popped: " << floatStack.pop() << endl;
    
    return 0;
}
