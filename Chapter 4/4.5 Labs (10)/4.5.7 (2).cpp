#include <string>
#include <iostream>

inline std::string RemoveExtraSpaces(std::string str)
{
	int index = -1;

	// remove space at the beginning of string
	if (str[0] == ' ')
		str.replace(0, 1, "");

	// remove space at the end of string
	if (str[str.length() - 1] == ' ')
		str.replace(str.length() - 1, 1, "");

	// remove multi-spaces
	while ((index = str.find("  ")) != -1)
		str.replace(index, 2, " ");

	return str;
}

inline std::string ToLower(std::string str)
{
	// add space (change index to lower) to upper to get lower
	for (int i = 0; i < str.length(); i++)
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + ' ';

	return str;
}

inline std::string RemoveStopWord(std::string str, std::string word)
{
	int index = -1;

	// toLower because we must replace both (lower and upper) cases
	// spaces in condition 'cause we must replace words, but not their parts
	while ((index = ToLower(str).find(" " + word + " ", index + 1)) != -1 ||
		(index = ToLower(str).find(" " + word, index + 1)) != -1,
		(index = ToLower(str).find(word + " ", index + 1)) != -1)
		str.replace(index, word.length(), "");

	// remove extra spaces before returning
	return RemoveExtraSpaces(str);
}

int main()
{
	std::string stopWords;
	std::string sentence;
	std::string currentStopWord;
	// for getting stop words separatly
	int begin = 0, end;
	int index = -1;

	std::cout << "Enter stop words: ";
	std::getline(std::cin, stopWords);

	std::cout << "Enter sentence: ";
	std::getline(std::cin, sentence);

	while ((end = stopWords.find(',', begin)) != -1) {
		currentStopWord = stopWords.substr(begin, end - begin);
		sentence = RemoveStopWord(sentence, currentStopWord);
		// jump over comma
		begin = end + 1;
	}

	// last word after comma
	currentStopWord = stopWords.substr(begin);
	sentence = RemoveStopWord(sentence, currentStopWord);

	std::cout << sentence << "\n";
}