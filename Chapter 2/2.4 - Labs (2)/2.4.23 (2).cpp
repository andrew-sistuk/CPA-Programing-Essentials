#include <iostream>
#include <bitset> 
using namespace std;
int main(void) {

	unsigned short int val;
	bool ispalindrome = true;
	cout << "value = ";
	cin >> val;

	int counter = 15;
	unsigned short a = 1, b = 1;

	for (int i = 0; i < counter; i++) {
		a = a << i;
		b = b << counter;
		if (((val & a) && (val & b)) || (!(val & a) && !(val & b))) {
			a = 1;
			b = 1;
			counter--;
		}
		else {
			ispalindrome = false;
			break;
		}
	}

	if (ispalindrome)
		cout << val << " is a bitwise palindrome" << endl;
	else
		cout << val << " is not a bitwise palindrome" << endl;

	return 0;
}
