#include <iostream>
#include <string>
#include <regex>

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(std::string input) = 0;
};


class MinLengthValidator : public StringValidator
{
private:
	int min;
public:
	MinLengthValidator(int min);
	bool isValid(std::string);
};

MinLengthValidator::MinLengthValidator(int min)
{
	this->min = min;
}

bool MinLengthValidator::isValid(std::string input)
{
	if (input.length() < this->min)
		return false;

	return true;
}


class MaxLengthValidator : public StringValidator
{
private:
	int max;
public:
	MaxLengthValidator(int max);
	bool isValid(std::string);
};

MaxLengthValidator::MaxLengthValidator(int max)
{
	this->max = max;
}

bool MaxLengthValidator::isValid(std::string input)
{
	if (input.length() > this->max)
		return false;

	return true;
}


class PatternValidator : public StringValidator
{
private:
	std::string pattern;
public:
	PatternValidator(std::string pattern);
	bool isValid(std::string input);
};

PatternValidator::PatternValidator(std::string pattern)
{
	this->pattern = pattern;
}

bool PatternValidator::isValid(std::string input)
{
	// good way is using regex
	// there are no code :(
	return false;
}

class ExactValidator : public StringValidator
{
private:
	std::string word;
public:
	ExactValidator(std::string word);
	bool isValid(std::string);
};

ExactValidator::ExactValidator(std::string word)
{
	if (word != "")
		this->word = word;
}

bool ExactValidator::isValid(std::string input)
{
	if (input == this->word)
		return true;

	return false;
}


void printValid(StringValidator &validator, std::string input)
{
	std::cout << "The string '" << input << "' is "
		<< (validator.isValid(input) ? "valid" : "invalid");
}

int main()
{
	std::cout << "MinLengthValidator" << std::endl;
	MinLengthValidator min(6);

	printValid(min, "hello");
	std::cout << std::endl;
	printValid(min, "welcome");
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "MaxLengthValidator" << std::endl;
	MaxLengthValidator max(6);

	printValid(max, "hello");
	std::cout << std::endl;
	printValid(max, "welcome");
	std::cout << std::endl;
	std::cout << std::endl;

	//std::cout << "PatternValidator" << std::endl;
	//PatternValidator digit("D");

	//printValid(digit, "there are 2 types of sentences in the world");
	//std::cout << std::endl;
	//printValid(digit, "valid and invalid ones");
	//std::cout << std::endl;
	//std::cout << std::endl;

	return 0;
}