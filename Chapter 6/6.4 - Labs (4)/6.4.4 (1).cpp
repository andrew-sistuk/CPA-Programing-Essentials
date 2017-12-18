#include <iostream>
#include <string>

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(std::string input) = 0;
};

class ExactValidator : public StringValidator
{
private:
	std::string word;
public:
	ExactValidator(std::string word) { this->word = word; }
	bool isValid(std::string);
};

bool ExactValidator::isValid(std::string input)
{
	if (input == this->word)
		return true;

	return false;
}

class DummyValidator : public StringValidator
{
public:
	virtual bool isValid(std::string input);
};

bool DummyValidator::isValid(std::string input)
{
	return true;
}

void printValid(StringValidator &validator, std::string input)
{
	std::cout << "The string '" << input << "' is "
		<< (validator.isValid(input) ? "valid" : "invalid");
}

int main()
{
	DummyValidator dummy;
	ExactValidator exact("secret");

	printValid(dummy, "hello");
	std::cout << std::endl;

	printValid(exact, "hello");
	std::cout << std::endl;

	printValid(exact, "secret");
	std::cout << std::endl;

	return 0;
}