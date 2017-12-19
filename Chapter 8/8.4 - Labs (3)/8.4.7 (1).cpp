#include "string"
#include "iostream"
#include "vector"
using namespace std;

class Matric {
	vector <vector<int>> mat;
	const int dimy = 0;
	const int dimx = 0;
public:
	Matric(int const y = 1, int x = 1, int start_va = 0) :dimx(x), dimy(y) {

		for (int i = 0; i < y; i++) {
			mat.insert(mat.end(), vector <int>(x));
			for (int j = 0; j < x; ++j)
				mat[i][j] = start_va;
		}
	}
	
	Matric operator-(int q) {
		if (q == NULL)
			throw string("value is empty");
		Matric n(dimy, dimy);
		for (int i = 0; i < dimy; i++)
		{
			for (int j = 0; j < dimx; j++) {
				n.mat[i][j] = mat[i][j] - q;
			}

		}
		return n;
	}
	Matric operator+(int q) {
		if (q == NULL)
			throw string("value is empty");
		Matric n(dimy, dimy);
		for (int i = 0; i < dimy; i++)
		{
			for (int j = 0; j < dimx; j++) {
				n.mat[i][j] = mat[i][j] + q;
			}

		}
		return n;
	}
	Matric operator*(int q) {
		if (q == NULL)
			throw string("value is empty");
		Matric n(dimy, dimy);
		for (int i = 0; i < dimy; i++)
		{
			for (int j = 0; j < dimx; j++) {
				n.mat[i][j] = mat[i][j] * q;
			}

		}
		return n;
	}
	Matric operator-(Matric c) {
		if (c.dimx != dimx || c.dimy != dimy)
			throw string("Matrices don't fit.\n");
		Matric n(dimy, dimy);
		for (size_t i = 0; i < dimy; i++)
		{

			for (size_t j = 0; j < dimx; j++) {
				n.mat[i][j] = this->mat[i][j] - c.mat[i][j];
			}

		}
		return n;
	}
	void operator=(Matric c) {

		Matric n(dimy, dimy);
		for (size_t i = 0; i < dimy; i++)
			for (size_t j = 0; j < dimx; j++) {
				//n.mat[i][j] = c.mat[i][j];
				this->mat[i][j] = c.mat[i][j];
			}
		//return n;
	}
	Matric operator*(Matric c) {
		if (dimy != c.dimx)
			throw string("Matrices don't fit.\n");
		Matric n(dimy, c.dimy);
		for (size_t i = 0; i < dimy; i++)
		{
			for (size_t j = 0; j < c.dimx; j++) {
				n.mat[i][j] = this->mat[j][i] * c.mat[i][j];
			}

		}
		return n;
	}
	Matric operator+(Matric c) {
		if (c.dimx != dimx || c.dimy != dimy)
			throw string("Matrices don't fit.\n");
		Matric n(dimy, dimy);
		for (size_t i = 0; i < dimy; i++)
		{

			for (size_t j = 0; j < dimx; j++) {
				n.mat[i][j] = this->mat[i][j] + c.mat[i][j];
			}

		}
		return n;
	}
	void print() {
		for (size_t i = 0; i < this->dimy; i++)
		{
			for (size_t j = 0; j < this->dimx; j++) {
				cout << this->mat[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	int x, y;
	cout << "MATRIC A:" << endl;
	Matric a(2, 2, 1);
	a.print();
	cout << "MATRIC B:" << endl;
	Matric b(2, 2, 3);
	b.print();
	cout << "Matrix A + 1:" << endl;
	try { a = (a + 1); a.print(); }
	catch (string e) { cout << e; }

	cout << "Matrix A * 2:" << endl;
	try { a = a * 2; a.print(); }
	catch (string e) { cout << e; }

	cout << "Matrix A - 1:" << endl;
	try { a = (a - 1); a.print(); }
	catch (string e) { cout << e; }
	


	cout << "Matrix A + Matrix B:" << endl;
	try { (a + b).print(); }
	catch (string e) { cout << e; }

	cout << "Matrix A - Matrix B:" << endl;
	try { (a - b).print(); }
	catch (string e) { cout << e; }

	cout << "Matrix A * Matrix B:" << endl;
	try { (a * b).print(); }
	catch (string e) { cout << e; }
	cout << "MATRIC A:" << endl;
	Matric aa(2, 2, 1);
	aa.print();
	cout << "MATRIC C:" << endl;
	Matric c(2, 3, 3);
	c.print();
	cout << "Matrix A + Matrix C:" << endl;
	try { (aa + c).print(); }
	catch (string e) { cout << e; }

	cout << "Matrix A - Matrix C:" << endl;
	try { (aa - c).print(); }
	catch (string e) { cout << e; }

	cout << "Matrix A * Matrix C:" << endl;
	try { (aa * c).print(); }
	catch (string e) { cout << e; }
	return 0;
}