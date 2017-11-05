#include <iostream>

using namespace std;

int main(void) {

	int n;
	cout << "Input number: ";
	cin >> n;

	long long factorial = 1;
	if (n == 0) factorial = 1;
	else {
		for (int i = 1; i <= n; i++) {
			factorial *= i;
		}
	}

	cout << factorial << endl;

	return 0;
}