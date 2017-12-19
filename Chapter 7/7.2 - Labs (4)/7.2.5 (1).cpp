#include <iostream>
#include <string>

using namespace std;

class MyException
{
public:
	string mes;
	MyException(string mes) { this->mes = mes; }
};


class Matrix
{
private:
	int **elements;
	int rowsCount;
	int columnsCount;

public:
	Matrix();
	Matrix(int rows, int columns);
	void FillCell(int row, int column, int value);
	void Print();
	void Add(Matrix *matrix);
	// void Add(int val);
};

Matrix::Matrix()
{
	*elements = new int[1];
	elements[0] = new int[1];

	rowsCount = 1;
	columnsCount = 1;
}

Matrix::Matrix(int rows, int columns)
{
	if (rows <= 0)
		throw new MyException("Rows count can not be lower or equal to zero!");

	if (columns <= 0)
		throw new MyException("Columns count can not be lower or equal to zero!");

	this->elements = new int*[rows];

	for (int i = 0; i < rows; ++i)
		this->elements[i] = new int[columns];

	this->rowsCount = rows;
	this->columnsCount = columns;
}

void Matrix::FillCell(int row, int column, int value)
{
	if (row >= rowsCount || column >= columnsCount)
		throw new MyException("Non existing cell!");

	if (row < 0 || column < 0)
		throw new MyException("There are no indexes below zero!");

	this->elements[row][column] = value;
}

void Matrix::Print()
{
	for (int i = 0; i < this->rowsCount; i++)
	{
		for (int j = 0; j < this->columnsCount; j++)
		{
			cout << this->elements[i][j] << ' ';
		}
		cout << endl;
	}
}

void Matrix::Add(Matrix *matrix)
{
	if (matrix->columnsCount != this->columnsCount
		|| matrix->rowsCount != this->rowsCount)
		throw new MyException("Can not add matrices with different sizes!");

	for (int i = 0; i < this->rowsCount; i++)
		for (int j = 0; j < this->columnsCount; j++)
			this->elements[i][j] += matrix->elements[i][j];
}

// maybe, i didn't unerstand the task, but we can't add
// the value to the matrix in mathematics ?
// function below is stupid
// void Matrix::Add(int val)
// {
//	 throw new MyException("We can't add any values to matrix");
// }

Matrix* CreateMatrix(int matrixNumber)
{
	Matrix* matrix;
	int rows, columns;
	int val;

	cout << "Matrix " << matrixNumber << ": " << endl;
	cout << "Enter number of rows: ";
	cin >> rows;

	cout << "Enter number of columns: ";
	cin >> columns;

	matrix = new Matrix(rows, columns);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> val;
			try
			{
				matrix->FillCell(i, j, val);
			}
			catch (MyException *e)
			{
				cout << e->mes << endl;
			}
		}
	}

	return matrix;
}

int main()
{
	try
	{
		Matrix *matrix1 = CreateMatrix(1);
		Matrix *matrix2 = CreateMatrix(2);
		Matrix *matrix3 = CreateMatrix(3);

		cout << "Matrix 1: " << endl;
		matrix1->Print();
		cout << endl;

		cout << "Matrix 2: " << endl;
		matrix2->Print();
		cout << endl;

		cout << "Matrix 3: " << endl;
		matrix3->Print();
		cout << endl;

		try
		{
			matrix1->Add(matrix2);
			matrix1->Print();
		}
		catch (MyException *e)
		{
			cout << e->mes << endl;
		}

		try
		{
			matrix1->Add(matrix3);
			matrix1->Print();
		}
		catch (MyException *e)
		{
			cout << e->mes << endl;
		}
	}
	catch (MyException *e)
	{
		cout << e->mes << endl;
	}

	return 0;
}