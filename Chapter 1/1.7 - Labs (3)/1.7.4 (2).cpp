#include <iostream>
using namespace std;

int main(void) {
	int a, b;
	cout << "Input two numbers:" << endl;
	cin >> a >> b;

	if (1. / a == 1. / b)
	{
		cout << "Results are equal (by 0.000001 epsilon)" << endl;
	}
	else
	{
		cout << "Results are not equal (by 0.000001 epsilon)"<< endl;
	}
	return 0;
}