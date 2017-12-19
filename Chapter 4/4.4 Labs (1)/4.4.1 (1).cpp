#include <string>
#include <iostream>

using namespace std;

int CountSpecChar(string str, char chr) {

	int charCount = 0;
	int currentIndex = -1;

	while ((currentIndex = str.find(chr, currentIndex + 1)) != -1)
		charCount++;

	return charCount;
}

int *CountAllChars(string str) {

	int *countedChars = new int[26];

	for (int i = 0; i <= 25; i++)
		countedChars[i] = CountSpecChar(str, (char)(i + 97)) + CountSpecChar(str, (char)(i + 65));

	return countedChars;
}

bool IsPangram(int*chars) {

	bool isPangram = true;

	for (int i = 0; i <= 25; i++)
		if (chars[i] == 0) {
			isPangram = false;
			break;
		}

	return isPangram;
}

int main(void) {

	string input;
	int *countedChars;
	bool isPangram;

	cout << "Enter your string: ";
	getline(cin, input);

	countedChars = CountAllChars(input);
	isPangram = IsPangram(countedChars);

	cout << (isPangram ? "" : "Not ") << "Pangram" << endl;

	for (int i = 0; i <= 25; i++)
		cout << (char)(i + 97) << " - " << countedChars[i] << endl;

	return 0;
}