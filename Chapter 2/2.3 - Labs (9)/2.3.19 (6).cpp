#include <iostream>

using namespace std;

int main(void) {

	int h;
	cout << "Input height of pyramides (2 < h < 9): ";
	cin >> h;
	cout << endl;

	int a = 48;
	int c1 = a / 6;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < a; j++) {

			if (i == h - 1) {
				if (j < c1 + h && j > c1 - h || j < c1 + h + 16 && j > c1 - h + 16 || j < c1 + h + 32 && j > c1 - h + 32)
					cout << "*";
				else cout << " ";
			}
			else if (j == c1 - i || j == c1 + i || j == c1 - i + 16 || j == c1 + i + 16 || j == c1 - i + 32 || j == c1 + i + 32) cout << "*";
			else cout << " ";	

		}
		cout << endl;
	}

	cout << endl;
	return 0;
}