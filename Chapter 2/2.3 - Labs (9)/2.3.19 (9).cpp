#include <iostream>

using namespace std;

int main(void) {

	int n;
	cout << "Input odd number: ";
	cin >> n;

	if (n % 2 == 0) cout << "Wrong number!" << endl;
	else cout << n * (n - 2) + 2 << endl;

	return 0;
}