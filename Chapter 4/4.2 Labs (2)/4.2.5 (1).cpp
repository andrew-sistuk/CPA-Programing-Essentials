#include  <iostream>

using namespace std;

int main(void) {

	int n;
	double result = 0;

	do {
		cout << "Enter N(1 - 100 000): ";
		cin >> n;
	} while (n < 1 || n > 100000);

	for (int i = 1; i <= n; i++) {

		result += i;
	}

	cout.precision(0);
	cout << fixed << result << endl;

	return 0;
}