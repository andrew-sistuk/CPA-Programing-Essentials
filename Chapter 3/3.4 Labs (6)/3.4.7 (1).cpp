#include <iostream>

using namespace std;

bool isLeap(int year) {
	return year % 4 ==0 ;
	// Insert your code here
}
int main(void) {
	for (int yr = 1995; yr < 2017; yr++)
		cout << yr << " -> " << isLeap(yr) << endl;
	return 0;
}