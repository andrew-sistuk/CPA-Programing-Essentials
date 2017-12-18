#include <iostream>
#include <string>

using namespace std;

class IPAddress
{
public:
	IPAddress()
	{
		this->ipAdress = "0.0.0.0";
	}
	IPAddress(string ipAdress)
	{
		this->ipAdress = ipAdress;
	}
	IPAddress(IPAddress *ip)
	{
		this->ipAdress = ip->ipAdress;
	}

	virtual void Print()
	{
		cout << "Ip address is: " << this->ipAdress;
	}

protected:
	string ipAdress;
};

class IPAddressChecked : public IPAddress
{
public:
	IPAddressChecked()
	{
		isCorrect = true;
	}
	IPAddressChecked(string ipAdress) : IPAddress(ipAdress)
	{
		this->isCorrect = this->CheckValidity();
	}
	IPAddressChecked(IPAddressChecked *ip) : IPAddress(ip)
	{
		isCorrect = ip->isCorrect;
	}

	void Print()
	{
		IPAddress::Print();
		cout << " -" << (this->isCorrect ? " " : " Not ") << "correct";
	}
private:
	bool isCorrect;

	bool CheckValidity()
	{
		string currentOctet;
		int index = -1;
		int dotsCount = 0;

		while ((index = this->ipAdress.find('.', index + 1)) != -1)
			dotsCount++;

		if (dotsCount < 3)
			return false;

		index = -1;

		for (int i = 0; i < 4; i++)
		{
			if (i == 3)
			{
				currentOctet = this->ipAdress.substr(index + 1);
			}
			else
			{
				currentOctet = this->ipAdress.substr(index + 1,
					this->ipAdress.find('.', index + 1) - index - 1);
			}

			index = this->ipAdress.find('.', index + 1);

			try
			{
				if (stoi(currentOctet) < 0 || stoi(currentOctet) > 255)
					return false;
			}
			// if can't convert octet to int 
			catch (invalid_argument)
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	IPAddress **ips = new IPAddress*[3];
	string input;

	getline(cin, input);
	ips[0] = new IPAddress(input);

	getline(cin, input);
	ips[1] = new IPAddressChecked(input);

	getline(cin, input);
	ips[2] = new IPAddressChecked(input);


	for (int i = 0; i < 3; i++)
	{
		ips[i]->Print();
		cout << endl;
	}

	return 0;
}