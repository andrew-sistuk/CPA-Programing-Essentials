#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

	double vector[] = { 1., 2., 3., 4., 5. };
	int n = sizeof(vector) / sizeof(vector[0]);
	double ArithmeticMean = 0;
	double HarmonicMean = 0;
	double GeometricMean = 1;
	double RootMeanSquare = 0;

	for (int i = 0; i < n; i++) {
		ArithmeticMean += vector[i];
		HarmonicMean += 1 / vector[i];
		GeometricMean *= vector[i];
		RootMeanSquare += pow(vector[i], 2);
	}
	cout << GeometricMean << endl;

	ArithmeticMean /= n;
	HarmonicMean = n / HarmonicMean;
	GeometricMean = pow(GeometricMean, 1 / (double)n);
	RootMeanSquare = sqrt(RootMeanSquare / n);

	cout << "Arithmetic Mean = " << ArithmeticMean << endl;
	cout << "Harmonic Mean = " << HarmonicMean << endl;
	cout << "Geometric Mean = " << GeometricMean << endl;
	cout << "RootMean Square = " << RootMeanSquare << endl;
	cout << endl;

	return 0;
}