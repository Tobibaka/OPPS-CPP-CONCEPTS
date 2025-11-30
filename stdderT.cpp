#include<iostream>
#include<Cstring>
using namespace std;
template<class T>
T maxValue(T a,T b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
char* maxValue(char s1[],char s2[]) {
    if (strcmp(s1,s2)>0)
        return s1;
    else
        return s2;
}
int main() {
	int x,y;
	cout<<"Enter two integers:";
	cin>>x>>y;
	cout<<"Maximum : "<<maxValue(x,y)<<endl;
    char s1[100],s2[100];
	cout<<"Enter two strings:";
	cin>>s1>>s2;
    cout<<"Maximum : "<<maxValue(s1,s2)<<endl;
    return 0;
}