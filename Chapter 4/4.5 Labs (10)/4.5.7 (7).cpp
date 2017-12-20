#include <string>
#include <iostream>
using namespace std;



bool isLong(string str)
{
	if (str.length() >= 8)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool isUpper(string str)
{
	for (auto c : str)
	{
		if (c >= 'A' && c <= 'Z')
		{
			return true;
		}
	}
	return false;
}

bool isLower(string str)
{
	for (auto c : str)
	{
		if (c >= 'a' && c <= 'z')
		{
			return true;
		}
	}
	return false;
}

bool isDigit(string str)
{
	for (auto c : str)
	{
		if (c >= '0' && c <= '9')
		{
			return true;
		}
	}
	return false;
}

bool isSpecial(string str)
{
	for (auto c : str)
	{
		if (c == '~' || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '_' || c == '+' || c == '`' || c == '-' || c == '=' || c == '{' || c == '}' || c == '[' || c == ']' || c == ':' || c == ';' || c == '<' || c == '>' || c == '.' || c == '/' || c == '\\')
		{
			return true;
		}
	}
	return false;
}

string Validate(string str)
{
	string answ = "";
	if (!isLong(str))
	{
		answ += "The password must be 8 characters long\n";
	}
	if (!isLower(str))
	{
		answ += "The password must have at least one lower case letter\n";
	}
	if (!isUpper(str))
	{
		answ += "The password must have at least one upper case letter\n";
	}
	if (!isDigit(str))
	{
		answ += "The password must have at least one digit\n";
	}
	if (!isSpecial(str))
	{
		answ += "The password must have at least one special character\n";
	}
	if (answ == "")
	{
		answ = "The password is valid\n";
	}
	return answ;

}

int main()
{
	string password;
	getline(cin, password);
	// manipulate the password here
	// and print validation result
	cout << Validate(password);
	return 0;
}