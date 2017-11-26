#include <string>
#include <iostream>

int main()
{
	int index = 0;
	std::string from;
	std::string to;
	std::string sentence;

	std::cout << "Enter from: ";
	std::getline(std::cin, from);

	std::cout << "Enter to: ";
	std::getline(std::cin, to);

	std::cout << "Enter sentence: ";
	std::getline(std::cin, sentence);

	// first iteration searches from zero position
	index -= to.length();

	// index + to.length() for start searching from changed word
	// 'cause word to may contain from and cycle never reach end
	while ((index = sentence.find(from, index + to.length())) != -1)
		sentence.replace(index, from.length(), to);

	std::cout << sentence << "\n";