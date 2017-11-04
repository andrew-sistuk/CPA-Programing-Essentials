#include <iostream>

using namespace std;

int main(void) {

	int year, a, b, c, d, e;
	cout << "Input any year from 1900: ";
	cin >> year;
	cout << endl;

	if (year < 1900) {
		cout << "Year is wrong!\n";
	}
	else {
		a = year % 19;
		b = year % 4;
		c = year % 7;
		d = (a * 19 + 24) % 30;
		e = (2*b + 4*c + 6*d + 5) % 7;
		if (d + e < 10) cout << "March " << d + e + 22 << endl;
		else cout << "April " << d + e - 9 << endl;
	}


	return 0;
}