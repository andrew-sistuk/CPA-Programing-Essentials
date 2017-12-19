#include <iostream>
#include <string>

using namespace std;


class IPAdress
{
private:
	int range;
	string address;

public:
	IPAdress(string address, int range);
};

IPAdress::IPAdress(string address, int range)
{
	int octetcsCount = 0;
	int index = -1;

	while (address.find(address, index + 1) != -1)
		octetcsCount++;

	// adding last octet
	octetcsCount++;

	// out of range exception throwing
	if (octetcsCount != 4)
		throw;


}


int main()
{


    return 0;
}