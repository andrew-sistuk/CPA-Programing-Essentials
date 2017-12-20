#include <iostream>
#include <string>
using namespace std;

string findStop(string str, string stop)
{
	string foo = "";
	int a = 0, b = 0, c, d;
	while ((str.substr(a)).find(" ") != string::npos)
	{
		b = (str.substr(a)).find(" ");
		foo = str.substr(a, b);

		for (auto& c : foo)
		{
			c = tolower(c);
		}

		if (foo == stop)
		{
			str.erase(a, b + 1);
			a = 0;
			b = 0;
		}
		else
		{
			a += b + 1;
			b = 0;
		}
	}
	return str;
}

int main()
{
	string stop_words;
	getline(std::cin, stop_words);
	string sentence;
	getline(std::cin, sentence);
	// remove stop_words from sentence here
	int a = 0, b = 0;
	do
	{
		b = (stop_words.substr(a)).find(",");
		sentence = findStop(sentence, stop_words.substr(a, b));
		a += b + 1;
		b = 0;
		
	}
	while ((stop_words.substr(a)).find(",") != string::npos);
	sentence = findStop(sentence, stop_words.substr(a));

	cout << sentence << "\n";
}