#include <iostream>

using namespace std;

int main(void) {

	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]);
	int *currentElement = vector;
	int minimum = 0;

	for (int i = 0; i < n; i++) {
		if (minimum > *currentElement) {
			minimum = *currentElement;
		}
		currentElement++;
	}

	cout << "Minimum element is " << minimum << endl;

	return 0;
}