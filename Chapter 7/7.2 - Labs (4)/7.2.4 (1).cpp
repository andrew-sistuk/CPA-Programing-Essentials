#include <iostream>
#include <string>

using namespace std;

class MyException
{
public:
	string msg;
	MyException(string txt) : msg(txt) {}
};

float square_area(int a)
{
	if (a < 0)
		throw new MyException("Square of area can not be calculated. (a < 0)");

	return a * a;
}

float rectangle_area(int a, int b)
{
	if (a < 0)
		throw new MyException("Square of rectangle can not be calculated. (a < 0)");

	if (b < 0)
		throw new MyException("Square of rectangle can not be calculated. (b < 0)");

	return a * b;
}

int main(void) {
	float a, b;

	cin >> a;
	cin >> b;

	try
	{
		float rsquare = square_area(a);
		float rrectangle = rectangle_area(a, b);
		cout << rsquare << endl << rrectangle << endl;
	}
	catch (MyException *exception)
	{
		cout << exception->msg << endl;
	}

	return 0;
}