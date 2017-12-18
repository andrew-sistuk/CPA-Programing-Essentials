#include <iostream>
#include <string>

using namespace std;


class IPAddress
{
private:
	string ipAdress;

public:
	IPAddress();
	IPAddress(string ipAdress);
	string ToString();
};

IPAddress::IPAddress()
{
	this->ipAdress = "0.0.0.0";
}

IPAddress::IPAddress(string ipAdress)
{
	this->ipAdress = ipAdress;
}

string IPAddress::ToString()
{
	return this->ipAdress;
}


struct Collection {
	int elno;
	IPAddress *elements;
};


class Network
{
private:
	Collection addresses;
public:
	Network();
	Network(Collection addresses);
	void PrintAdressses();
	void AddAddress(IPAddress newAddress);
};

Network::Network()
{
	this->addresses = Collection();
}

Network::Network(Collection addresses)
{
	this->addresses = addresses;
}

void Network::AddAddress(IPAddress newAddress)
{
	IPAddress *copied;

	copied = new IPAddress[this->addresses.elno + 1];

	for (int i = 0; i < this->addresses.elno; i++) {
		copied[i] = this->addresses.elements[i];
	}

	delete[] this->addresses.elements;

	copied[this->addresses.elno] = newAddress;
	this->addresses.elements = copied;
	this->addresses.elno++;
}

void Network::PrintAdressses()
{
	for (int i = 0; i < this->addresses.elno; i++)
		cout << this->addresses.elements[i].ToString() << endl;
}


int main()
{
	string input;
	Network *net1 = new Network();
	Network *net2 = new Network();

	cin >> input;
	net1->AddAddress(IPAddress(input));

	cin >> input;
	net1->AddAddress(IPAddress(input));

	cin >> input;
	net1->AddAddress(IPAddress(input));
	net2->AddAddress(IPAddress(input));

	cin >> input;
	net2->AddAddress(IPAddress(input));

	cin >> input;
	net2->AddAddress(IPAddress(input));

	cout << "Network 1: " << endl;
	net1->PrintAdressses();

	cout << "Network 2: " << endl;
	net2->PrintAdressses();

	return 0;
}