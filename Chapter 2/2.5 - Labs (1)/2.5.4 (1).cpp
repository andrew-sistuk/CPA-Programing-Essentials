#include <iostream>

using namespace std;
int main(void) {
	int choice;
	double x1, x2;
	do 
	{
		cout << "MENU:" << endl << "0 - exit" << endl << "1 - addition" << endl <<
			"2 - subtraction" << endl << "3 - multiplication" << endl << "4 - division" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter two numbers \n";
			cin >> x1 >> x2;
			cout <<"Result: " << x1 + x2 << endl;
			break;
		case 2:
			cout << "Enter two numbers \n";
			cin >> x1 >> x2;
			cout << "Result: " << x1 - x2 << endl;
			break;
		case 3:
			cout << "Enter two numbers \n";
			cin >> x1 >> x2;
			cout << "Result: " << x1 * x2 << endl;
			break;
		case 4:
			cout << "Enter two numbers \n";
			cin >> x1 >> x2;
			if (x2 == 0) cout << "Error. Second number is zero \n";
			else	cout << "Result: "  << x1 / x2 << endl;
			break;
		default: "Error. No number \n";
		}
	} while (choice != 0);

	cout << "Bye \n";
	return 0;
}
