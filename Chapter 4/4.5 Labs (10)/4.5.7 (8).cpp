#include <iostream>
#include <string>

using namespace std;

string CheckIP(string address)
{
	string currentOctet;
	int index = -1;
	int dotsCount = 0;

	while ((index = address.find('.', index + 1)) != -1)
		dotsCount++;

	if (dotsCount < 3)
		return "Too many octets";

	index = -1;

	for (int i = 0; i < 4; i++)
	{
		if (i == 3)
		{
			currentOctet = address.substr(index + 1);
		}
		else
		{
			currentOctet = address.substr(index + 1,
				address.find('.', index + 1) - index - 1);
		}

		if (currentOctet.length() > 3)
			return "Too many characters in a part";

		index = address.find('.', index + 1);

		try
		{
			if (stoi(currentOctet) < 0 || stoi(currentOctet) > 255)
				return "Too big a value of a part";
		}
		// if can't convert octet to int 
		catch (invalid_argument)
		{
			return "Only digits and dots allowed";
		}
	}
	return "Correct IP";
}

int main()
{
	std::string ipAddress;
	std::getline(std::cin, ipAddress);

	std::cout << CheckIP(ipAddress) << std::endl;

	return 0;
}