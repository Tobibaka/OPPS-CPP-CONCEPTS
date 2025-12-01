#include <iostream>
using namespace std;
template <class T>
T maxx(T a, T b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}
//Derived comparision for string as follows 
string maxx(string s1, string s2) {
	int sum1 = 0, sum2 = 0;
	for (char c : s1) {
		sum1 += (int)c;
	}
	for (char c : s2) {
		sum2 += (int)c;
	}
	if (sum1 > sum2) {
		return s1;
	} else {
		return s2;
	}
}

int main() {
	char ch1, ch2;
	cout << "enter two characters:";
	cin >> ch1 >> ch2;
	cout << maxx(ch1, ch2);

	int a, b;
	cout << "enter a,b:";
	cin >> a >> b;
	cout << maxx(a, b);

	float p, q;
	cout << "enter p,q:";
	cin >> p >> q;
	cout << maxx(p, q);

	string str1, str2;
	cout << "enter two strings:";
	cin >> str1 >> str2;
	cout << maxx(str1, str2);

	return 0;
}