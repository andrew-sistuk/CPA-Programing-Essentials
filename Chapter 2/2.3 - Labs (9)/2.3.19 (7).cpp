#include <iostream>

using namespace std;

int main(void) {

	int n;
	cout << "Input number: ";
	cin >> n;

	long long current = 0;
	long long previous = 0;
	long long preprevoius = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) current = 1;
		else {
			preprevoius = previous;
			previous = current;
			current = preprevoius + previous;
		}
	}
	cout << current << endl;

	return 0;
}