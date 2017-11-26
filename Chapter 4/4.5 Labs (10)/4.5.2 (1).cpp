#include <string>
#include <iostream>

using namespace std;

int main()
{
	string sentence;
	int index = -1;

	cout << "Enter the sentence: ";
	getline(cin, sentence);

	while ((index = sentence.find("  ")) != -1)
		sentence = sentence.replace(index, 2, " ");

	cout << sentence << "\n";
}