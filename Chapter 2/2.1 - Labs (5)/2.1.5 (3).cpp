#include <iostream>
using namespace std;
int main(void) {
	int sys;
	float m, ft, in;

	cout << "Input measurement system (0 - metric, 1 - imperial) : ";
	cin >> sys;

	if (sys == 1) {
		cout << "Input feet: ";
		cin >> ft;
		cout << "Input inches: ";
		cin >> in;
		cout << "In meters: " << ft * 0.3048 + in * 0.0254 << "m" << endl;
	}
	else if (sys == 0) {
		cout << "Input meters: ";
		cin >> m;
		int feet = m / 0.0254 / 12;
		cout << "In feet and inches: " << feet << "'" << m / 0.0254 - feet * 12 << "\"" << endl;
	}
	else cout << "Unavailable measurement system!";
	return 0;
}