#include <iostream>
using namespace std;

int main(){
    int n,l;
    int a=0;
    cin >> n; 
    for (int i=0 ; i<n ; i++){
        l=i+a;
        a=l;
    }
    cout<< l;

}
