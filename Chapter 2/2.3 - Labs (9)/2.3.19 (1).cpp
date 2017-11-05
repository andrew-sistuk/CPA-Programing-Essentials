#include <iostream>

using namespace std;

int main(void) {

	int number, counter = 0;
	cout << "Input a natural number: ";
	cin >> number;

	while (number != 1)
	{
		if (number % 2 == 1) number = number * 3 + 1;
		else number /= 2;
		cout << number << endl;
		counter++;
	}

	cout << "steps: " << counter << endl;

	system("pause");
	return 0;
}