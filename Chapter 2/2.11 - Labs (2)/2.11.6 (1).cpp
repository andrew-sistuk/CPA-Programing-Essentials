#include <iostream>

using namespace std;

struct Time {
	int hours;
	int minutes;
};

int main(void) {

	struct Time time;
	int n;
	cout << "Input hours: ";
	cin >> time.hours;
	cout << "Input minutes: ";
	cin >> time.minutes;
	
	if (time.hours >= 24 || time.minutes > 60) {
		cout << "Your input is wrong" << endl;
	}
	else {
		cout << "Input number: ";
		cin >> n;
		time.hours += (n + time.minutes) / 60;
		time.hours %= 24;
		time.minutes = (n + time.minutes) % 60;
	
		cout << time.hours << ":" << time.minutes << endl;
	}

	return 0;
}