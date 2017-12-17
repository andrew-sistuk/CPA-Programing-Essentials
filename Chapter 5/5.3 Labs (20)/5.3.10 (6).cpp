#include <iostream>
#include <string>

class Fraction
{
public:
	Fraction(int numerator, int denominator);
	std::string ToString();
	double ToDouble();

	Fraction plus(Fraction that);
	Fraction minus(Fraction that);
	Fraction times(Fraction that);
	Fraction by(Fraction that);

private:
	int numerator;
	int denominator;
	void reduce();
};

Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
}

std::string Fraction::ToString()
{
	std::string result = "";
	// saving original values
	int numerator = this->numerator, denominator = this->denominator;
	int wholePart = 0;

	if (denominator < 0 && numerator < 0)
	{
		denominator = -denominator;
		numerator = -numerator;
	}
	else if (numerator < 0 && denominator > 0)
	{
		result += "-";
		numerator = -numerator;
	}
	else if (denominator < 0 && numerator > 0)
	{
		result += "-";
		denominator = -denominator;
	}

	while (numerator >= denominator)
	{
		wholePart++;
		numerator -= denominator;
	}

	if (wholePart != 0)
		result += std::to_string(wholePart) + " ";

	if (numerator != 0)
		result += std::to_string(numerator)
		+ "/" + std::to_string(denominator);

	return result;
}

double Fraction::ToDouble()
{
	return (double)this->numerator / this->denominator;
}

Fraction Fraction::times(Fraction that)
{
	int num = this->numerator * that.numerator;
	int den = this->denominator * that.denominator;

	Fraction result(num, den);
	result.reduce();

	return result;
}

Fraction Fraction::plus(Fraction that)
{
	int num = this->numerator * that.denominator + that.numerator * this->denominator;
	int den = this->denominator * that.denominator;

	Fraction result(num, den);
	result.reduce();

	return result;
}

Fraction Fraction::minus(Fraction that)
{
	int num = this->numerator * that.denominator - that.numerator * this->denominator;
	int den = this->denominator * that.denominator;

	Fraction result(num, den);
	result.reduce();

	return result;
}

Fraction Fraction::by(Fraction that)
{
	int num = this->numerator * that.denominator;
	int den = this->denominator * that.numerator;

	Fraction result(num, den);
	result.reduce();

	return result;
}

void Fraction::reduce()
{
	int a = std::abs(this->numerator), b = std::abs(this->denominator);

	while (a != b)
		if (a > b)
			a -= b;
		else
			b -= a;

	this->numerator /= a;
	this->denominator /= a;
}

int main(void)
{
	int num1, den1, num2, den2;
	std::string input = "";

	std::cout << "Enter first fractional [numerator] / [denominator]: ";
	std::getline(std::cin, input);

	num1 = std::stoi(input.substr(0, input.find(' ')));
	den1 = std::stoi(input.substr(input.find(' ', input.find(' ') + 1)));

	std::cout << "Enter first fractional [numerator] / [denominator]: ";
	std::getline(std::cin, input);

	num2 = std::stoi(input.substr(0, input.find(' ')));
	den2 = std::stoi(input.substr(input.find(' ', input.find(' ') + 1)));

	Fraction fraction1(num1, den1);
	Fraction fraction2(num2, den2);

	std::cout << fraction1.ToString() << " * " << fraction2.ToString()
		<< " = " << fraction1.times(fraction2).ToString() << std::endl;

	std::cout << fraction1.ToString() << " / " << fraction2.ToString()
		<< " = " << fraction1.by(fraction2).ToString() << std::endl;

	std::cout << fraction1.ToString() << " + " << fraction2.ToString()
		<< " = " << fraction1.plus(fraction2).ToString() << std::endl;

	std::cout << fraction1.ToString() << " - " << fraction2.ToString()
		<< " = " << fraction1.minus(fraction2).ToString() << std::endl;

	return 0;
}