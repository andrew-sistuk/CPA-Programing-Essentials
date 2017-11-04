#include <iostream>

using namespace std;

int main(void) {

	int year, month, day;
	cout << "Input any year from 1900: " << endl;
	cin >> year;
	cout << "Input number of month(1-12): " << endl;
	cin >> month;
	cout << "Input number of day of the month: " << endl;
	cin >> day;
	cout << endl;

	month -= 2;
	if (month <= 0) {
		month += 12;
		year--;
	}
	month = month * 83 / 32;
	month += day;
	month += year;
	month += year / 4;
	month -= year / 100;
	month += year / 400;
	month %= 7;

	cout << "This is " << month << " day of the week." << endl;

	return 0;
}