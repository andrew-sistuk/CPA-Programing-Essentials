#include <string>
#include <iostream>

int main()
{
	std::string pattern;
	std::string sentence;

	std::getline(std::cin, pattern);
	std::getline(std::cin, sentence);

	// match pattern against sentence

	std::cout << sentence << "\n";
}