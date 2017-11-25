#include <iostream>
#include <cmath>

using namespace std;

void increment(int &value, int incrementValue = 1) {
	value += incrementValue;
}

void increment(float &value, int incrementValue = 1) {
	value += incrementValue;
}

int main(void) {

	int intvar = 0;
	float floatvar = 1.5;

	for (int i = 0; i < 10; i++) {
		if (i % 2) {
			increment(intvar);
			increment(floatvar, sqrt(intvar));
		}
		else {
			increment(intvar, i);
			increment(floatvar);
		}
	}
	cout << intvar * floatvar << endl;
	return 0;
}