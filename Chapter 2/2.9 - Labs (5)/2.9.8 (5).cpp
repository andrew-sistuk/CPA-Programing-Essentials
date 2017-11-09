#include <iostream>

using namespace std;

int main(void) {

	double matrix[][4] = { { 1, 2, 3, 4 },
	{ 2, 2, 3, 1 },
	{ 3, 3, 3, 2 },
	{ 4, 1, 2, 4 } };
	//double matrix[][5] = { { 4, 0, 5, 6, 3 }, { 0, 5, 2, 4, 2 }, { 5, 2, 1, 3, 4 }, { 6, 4, 3, 2, 1 }, { 3, 2, 4, 1, 3 } };
	int side = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	bool issymmetric = true;

	for (int i = 0; i < side; i++) {
		for (int j = i; j < side; j++) {
			if (i == j) continue;
			else {
				if (matrix[i][j] != matrix[j][i]) {
					issymmetric = false;
					break;
				}
			}
		}
		if (!issymmetric) break;
	}

	if (issymmetric)
		cout << "The matrix is symmetric" << endl;
	else
		cout << "The matrix is not symmetric" << endl;

	return 0;
}