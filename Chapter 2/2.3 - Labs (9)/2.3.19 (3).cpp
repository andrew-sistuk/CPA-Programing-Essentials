#include <iostream>

using namespace std;

int main(void) {

	int n;
	unsigned long long number = 1;
	cout << "Input a value of power(0-63): ";
	cin >> n;

	if (n <= 63 && n >= 0) {
		for (int i = 1; i <= n; i++) {
			number *= 2;
		}
	}
	else cout << "Wrong value inputed!" << endl;

	cout << number << endl;

	return 0;
}