#include <string>
#include <iostream>
using namespace std;
bool Check(char c1, char c2)
{
	if (c1 == ' ') return false;
	if (c1 == 'D')
	{
		if (c2 >= '0'&&c2 <= '9') return true;
		else return false;
	}
	if (c1 == 'A')
	{
		if (c2 >= 'A'&&c2 <= 'Z') return true;
		if (c2 >= 'a'&&c2 <= 'z') return true;
		return false;
	}
	if (c1 == '?') return true;
	if (c1 >= 'a' && c1 <= 'z')
	{
		if (c1 == c2 || c1 == (c2 - 'A' + 'a')) return true;
		return false;
	}
	if (c1 == c2) return true;
	return false;
}
string Reg(string str1, string str2)
{
	string str;
	int i = str1.length();
	int j = 0;
	int k = -1;
	for (; j < str2.length();)
	{
		for (int a = 0; a < i; )
		{
			if (j >= (str2.length())) return str;
			if (Check(str1.at(a), str2.at(j)))
			{
				a++;
				if (k == -1) k = j;
				j++;
			}
			else
			{
				j++;
				k = -1;
				a = 0;
			}
		}
		str += str2.substr(k, j - k)+"\n";
		j = k + 1;
		k = -1;
	}
}
int main()
{
	string pattern;// = "DDDD";
	getline(cin, pattern);
	string sentence;// = "The combination for the safe is 2380, but please keep it a secret!";
	getline(cin, sentence);

	// match pattern against sentence
	sentence = Reg(pattern, sentence);
	cout << sentence << "\n";
}