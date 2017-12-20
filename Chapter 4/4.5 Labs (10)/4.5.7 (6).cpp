#include <string>
#include <iostream>
using namespace std;



string ToUpper(string str)
{
	for (auto& c : str)
	{
		c = toupper(c);
	}
	return str;

}

string ToSpecy(string str) 
{
	string str1 = " ";
	//cout << str << endl;
	for (int i = 0; i < str.length(); i += 2)
	{
		str.insert(i + 1, 1, ' ');
	}
	//cout << str <<"|"<< endl;
	return (str1+str);
}

string MakeGood(string str)
{
	int j = 0;
	string answ = "";
	for (int i = 0; i < str.length(); i++)
	{
		j = 0;
		if (str[i] == '_')
		{
			if (str.substr(i + 1).find("_") < str.substr(i + 1).find("*"))
			{
				j = str.substr(i + 1).find("_") + i;
				answ += ToSpecy(str.substr(i + 1, j - i));
				i = j + 1;
			}
		}
		else if (str[i] == '*')
		{
			if (str.substr(i + 1).find("*") < str.substr(i + 1).find("_"))
			{
				j = str.substr(i + 1).find("*") + i;
				answ += ToUpper(str.substr(i + 1, j - i));
				i = j + 1;
			}
		}
		else answ += str[i];
	}
	return answ;
}
int main()
{
	string sentence;
	getline(cin, sentence);
	cout << MakeGood(sentence) << endl;
	// manipulate the sentence here


	//cout << Calsub(sentence) << endl;
	//cout << sentence << "\n";
}