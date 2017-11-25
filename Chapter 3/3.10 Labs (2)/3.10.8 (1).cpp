#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void) {

	int maxball;
	int ballsno;
	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> ballsno;

	if (ballsno > maxball) cout << "Error!" << endl;
	else {
		srand(time(NULL));

		int *numbers = new int[ballsno];
		int n = 0, randValue = 0;
		bool notExist = true;

		while (n != ballsno) {
			randValue = rand() % maxball + 1;

			for (int i = 0; i < ballsno; i++) {
				if (randValue == numbers[i]) {
					notExist = false;
					break;
				}
			}
			if (notExist) {
				numbers[n] = randValue;
				n++;
			}
			notExist = true;
		}

		for (int i = 0; i < ballsno; i++) {
			cout << numbers[i] << " ";
		}
		cout << endl;
		delete[] numbers;
	}

	return 0;
}