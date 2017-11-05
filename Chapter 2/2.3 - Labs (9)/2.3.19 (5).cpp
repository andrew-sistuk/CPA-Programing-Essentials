#include <iostream>
using namespace std;
int main(void) {

	int n;
	cout << "Enter a positive integer value greater than 1: ";
	cin >> n;

	if (n <= 1) cout << "Your number is <= 1";
	else if (n > 20) cout << "Sorry, the side size is too big";
	else {
		cout << '+';

		for (int i = 0; i < n; i++)
			cout << '-';

		cout << '+' << endl;

		for (int i = 0; i < n; i++) {
			cout << '|';
			for (int j = 0; j < n; j++)
				cout << ' ';
			cout << '|' << endl;
		}

		cout << '+';

		for (int i = 0; i < n; i++)
			cout << '-';

		cout << '+' << endl;
	}

	return 0;
}