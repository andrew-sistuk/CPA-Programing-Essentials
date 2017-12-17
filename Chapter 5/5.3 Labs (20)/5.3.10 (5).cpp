#include <iostream>
#include <string>

class Fraction
{
public:
	Fraction(int numerator, int denominator);
	std::string ToString();
	double ToDouble();

private:
	int numerator;
	int denominator;
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

int main(void)
{
	int num, den;
	std::string input = "";

	std::cout << "Enter fractional [numerator] / [denominator]: ";
	std::getline(std::cin, input);

	num = std::stoi(input.substr(0, input.find(' ')));
	den = std::stoi(input.substr(input.find(' ', input.find(' ') + 1)));

	Fraction fraction(num, den);
	std::cout << fraction.ToString() << " is " << fraction.ToDouble() << " in decimal" << std::endl;

	return 0;
}