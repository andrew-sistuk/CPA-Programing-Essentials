#include <string>
#include <iostream>
using namespace std;
int main()
{
	string from;
	getline(std::cin, from);
	string to;
	getline(std::cin, to);
	string sentence;
	getline(std::cin, sentence);
	// change all occurrences of 'from' into 'to' in the sentence
	sentence.replace(sentence.find(from), from.length(), to);
	cout << sentence << "\n";
}