//stack using template class array
//no use of vector
#include <iostream>
using namespace std;
template <class T>
class Stack {
private:
    T arr[100];
    int top;
    int capacity;
public:
    // default capacity is 100 (size of arr)
    Stack() {
        top = -1;
        capacity = 100;
    }
    // constructor that accepts capacity
    Stack(int cap) {
        capacity = cap;
        top = -1;
    }
    void push(const T& item) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = item;
    }
    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return 0 ;
        }
        return arr[top--];
    }
    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return 0;
        }
        return arr[top];
    }
    T display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return T();
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool isEmpty() {
        return top == -1;
    }
    int size() {
        return top + 1;
    }
};
int main() {
    Stack<int> s(5);
    s.push(10);
    s.push(20);
    s.display();
    cout << "Top element is: " << s.peek() << endl; // 20
    cout << "Stack size is: " << s.size() << endl; // 2
    cout << "Popped element is: " << s.pop() << endl; // 20
    cout << "Stack size after pop: " << s.size() << endl; // 1
    
    Stack<string> sc(5);
    sc.push("Hello");
    sc.push("World");
    cout << "Top element is: " << sc.peek() << endl; // World
    cout << "Stack size is: " << sc.size() << endl; // 2
    cout << "Popped element is: " << sc.pop() << endl; // World
    cout << "Stack size after pop: " << sc.size() << endl; // 1
    
    return 0;
}

