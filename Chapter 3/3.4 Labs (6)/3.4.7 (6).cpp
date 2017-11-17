#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {

	int iterationsCount;

	if (num < 2)
{
		return false;
}

	iterationsCount = ceil(sqrt(num));

	for (int i = 2; i < iterationsCount; i++)
 {
		if (num % i == 0) return false;
	}

	return true;
}

int main(void) {

	for (int i = 0; i <= 21; i++){
		if (isPrime(i))
			cout << i << " ";}
	cout << endl;

	return 0;
}