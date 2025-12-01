#include <iostream>
using namespace std;
class sample{
    public:
    int x;
    void display(){
        cout<<"Value of x: "<<x<<endl;
    }
};
int main(){
    sample s;
    sample *p;//initialize pointer
    int sample::*ptr=&sample::x;//pointer to member
    s.x=100;
    p=&s;//declared pointer to object
    cout<<"Accessing member using object: "<<p->*ptr<<endl;//using pointer to object
    cout<<"Accessing member using object: "<<s.*ptr<<endl;//using object
    p->display();
    s.display();
    return 0;
}