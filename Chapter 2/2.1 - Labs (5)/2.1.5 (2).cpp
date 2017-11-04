#include <iostream>
using namespace std;
int main(void) {
	float grossprice, taxrate, netprice, taxvalue;
	cout << "Enter a gross price: ";
	cin >> grossprice;
	cout << "Enter a tax rate: ";
	cin >> taxrate;
	if (grossprice > 0 && taxrate > 0 && taxrate < 100)
	{
		netprice = grossprice / (1 + taxrate / 100);
		taxvalue = grossprice - netprice;
		cout << "Net price: " << netprice << endl;
		cout << "Tax value: " << taxvalue << endl;
	}
	else { cout << "Invalid value." << endl; }
	return 0;
}