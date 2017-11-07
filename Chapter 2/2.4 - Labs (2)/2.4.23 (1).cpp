#include <iostream>
using namespace std;

int main(void) {

	unsigned long n;
	cout << "Input number: ";
	cin >> n;

	unsigned long a = 1;
	int counter = 0;

	for (int i = 0; i < 64; i++) {
		if (n & a) counter++;
		a = a << 1;
	}

	cout << counter << endl;

	return 0;
}