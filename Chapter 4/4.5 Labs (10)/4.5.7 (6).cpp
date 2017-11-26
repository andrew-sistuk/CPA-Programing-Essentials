#include <string>
#include <iostream>

bool AnalyzeByASCIITable(std::string str, int firstIndex, int lastIndex) {

	for (int i = firstIndex; i < lastIndex + 1; i++)
		if (str.find((char)i) != -1)
			return true;

	return false;
}

bool ContainsSpecChar(std::string str) {
	// spec chars in ASCII: 33-47, 58-64, 91-96, 123-126
	return AnalyzeByASCIITable(str, 33, 47) || AnalyzeByASCIITable(str, 58, 64)
		|| AnalyzeByASCIITable(str, 91, 96) || AnalyzeByASCIITable(str, 123, 126);
}

bool ContainsDigit(std::string str) {
	// 48-57 are digits in ASCII
	return AnalyzeByASCIITable(str, 48, 57);
}

bool ContainsLowerCase(std::string str) {
	// lowercase chars is ASCII are 97-122
	return AnalyzeByASCIITable(str, 97, 122);
}

bool ContainsUpperCase(std::string str) {
	// lowercase chars is ASCII are 65-90
	return AnalyzeByASCIITable(str, 65, 90);
}

int main()
{
	bool isValid = true;
	std::string password;
	std::string message = "";
	std::getline(std::cin, password);

	if (password.length() < 8) {
		message += "The password must be 8 characters long\n";
		isValid = false;
	}

	if (!ContainsSpecChar(password)) {
		message += "The password must have at least one special character\n";
		isValid = false;
	}

	if (!ContainsDigit(password)) {
		message += "The password must have at least one digit\n";
		isValid = false;
	}

	if (!ContainsLowerCase(password)) {
		message += "The password must have at least one lower case character.\n";
		isValid = false;
	}

	if (!ContainsUpperCase(password)) {
		message += "The password must have at least one upper case character.\n";
		isValid = false;
	}

	std::cout << (isValid ? "The password is valid" : message) << std::endl;

	return 0;
}