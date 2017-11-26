#include <iostream>
#include <string>

int main()
{
	std::string first, second;
	bool result = true;
	int letterCountInFirst = 0, letterCountInSecond = 0, index = -1;

	std::cout << "Enter first word: ";
	std::cin >> first;

	std::cout << "Enter second word: ";
	std::cin >> second;

	if (first.length() != second.length()) {
		result = false;
	}
	else {
		for (int i = 0; i < first.length(); i++) {

			while ((index = first.find(first[i], index + 1)) != -1)
				letterCountInFirst++;

			while ((index = second.find(first[i], index + 1)) != -1)
				letterCountInSecond++;

			if (letterCountInFirst != letterCountInSecond) {
				result = false;
				break;
			}
		}
	}

	std::cout << (result ? "" : "not ") << "anagrams" << std::endl;

	return 0;
}