#include <iostream>

using namespace std;

int main(void) {

	int number;
	cout << "Input number: ";
	cin >> number;

	int arr[5] = { 50, 20, 10, 5, 1 };

	while (number != 0)
	{
		if (number >= 50) {
			number -= arr[0];
			cout << arr[0] << " ";
		}
		else if (number >= 20) {
			number -= arr[1];
			cout << arr[1] << " ";
		}
		else if (number >= 10) {
			number -= arr[2];
			cout << arr[2] << " ";
		}
		else if (number >= 5) {
			number -= arr[3];
			cout << arr[3] << " ";
		}
		else {
			number -= arr[4];
			cout << arr[4] << " ";
		}
	}
	cout << endl;

	return 0;
}