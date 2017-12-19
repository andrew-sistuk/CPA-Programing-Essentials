#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int a = 0, b = 0, c = 0;

	cin >> a;
	cin >> b;

	try
	{
		if (b == 0)
			throw string("Your input is not valid, you can't divide by zero.");

		c = a / b;
		cout << c << endl;
	}
	catch (string &mes)
	{
		cout << mes << endl;
	}

	return 0;
}