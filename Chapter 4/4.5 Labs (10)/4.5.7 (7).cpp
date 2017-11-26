#include <string>
#include <iostream>

int main()
{
	std::string values;
	std::string template;

	std::getline(std::cin, values);
	std::getline(std::cin, template);

	// Put values into the template

	std::cout << template << "\n";
}