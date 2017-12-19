#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Matrix
{
private:
	int values[2][2];
public: void Print()
{
	cout << values[0][0] << values[0][1] <<"\n"<< values[1][0]<< values[1][1]<<endl;
}
		void SetVal()
		{
			cin >> values[0][0] >> values[0][1] >> values[1][0] >> values[1][1];
		}
};



int main()
{
	Matrix matrix;
	matrix.SetVal();
	matrix.Print();
	return 0;
}