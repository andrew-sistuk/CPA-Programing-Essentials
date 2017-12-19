#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sys/stat.h>

using namespace std;

class Matrix {
private:
	int matrix[2][2];
public:
	int GetMatrixElement(int arrayIndex, int elementIndex);
	void LoadMatrix(string path);
	void SaveMatrix(string path);
};

bool IsFileExists(string path) {
	struct stat buffer;
	return (stat(path.c_str(), &buffer) == 0);
}

void Matrix::LoadMatrix(string path) {
	if (!IsFileExists(path))
		throw runtime_error("File not found at: " + path);

	ifstream iFile(path);

	if (!iFile)
		throw runtime_error("No rights to read from file: " + path);

	iFile >> matrix[0][0] >> matrix[0][1] >> matrix[1][0] >> matrix[1][1];

	iFile.close();
}

void Matrix::SaveMatrix(string path) {
	if (!IsFileExists(path))
		throw runtime_error("File not found at: " + path);

	ofstream oFile(path);

	if (!oFile) {
		throw runtime_error("No rights to write to file: " + path);
	}

	oFile << matrix[0][0] << " " << matrix[0][1] << endl << matrix[1][0] << " " << matrix[1][1];

	oFile.close();
}

int Matrix::GetMatrixElement(int arrayIndex, int elementIndex) {
	if (arrayIndex < 0 || arrayIndex >= 2 || elementIndex < 0 || elementIndex >= 2)
		throw invalid_argument("Index out of range");

	return this->matrix[arrayIndex][elementIndex];
}

int main()
{
	string path;
	Matrix matrix;

	cout << "Enter path to file for read matrix:" << endl;
	getline(cin, path);

	try {
		matrix.LoadMatrix(path);

		cout << "Matrix:" << endl << matrix.GetMatrixElement(0, 0) << " " << matrix.GetMatrixElement(0, 1) <<
			endl << matrix.GetMatrixElement(1, 0) << " " << matrix.GetMatrixElement(1, 1) << endl;

		cout << "Enter path to file for save matrix:" << endl;
		getline(cin, path);

		matrix.SaveMatrix(path);
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}