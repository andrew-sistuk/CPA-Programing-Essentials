#include <iostream>

using namespace std;

int main(void) {

	int vector1[7] = { 4, 7, 2, 8, 1, 3, 0 };
	int vector2[7];

	for (int i = 0; i < sizeof(vector1)/sizeof(vector1[0]); i++) {
		if (i == 0) vector2[i] = vector1[sizeof(vector1)/sizeof(*vector1) - 1];
		else vector2[i] = vector1[i - 1];
	}

	for (int i = 0; i < sizeof(vector1) / sizeof(*vector1); i++)
		cout << vector2[i] << ' ';

	cout << endl;

	return 0;
}