#include <iostream>
#include <string>

class Subscription
{
public:
	Subscription()
	{
		this->id = 0;
		this->ownerName = "Unknown";
		this->validityInMonths = 0;
	}
	Subscription(int id, int validityInMonths, std::string ownerName)
	{
		if (id < 0)
			id = 0;

		this->id = id;

		if (validityInMonths < 0)
			validityInMonths = 0;

		this->validityInMonths = validityInMonths;

		if (ownerName.length() == 0)
			ownerName = "Unknown";

		this->ownerName = ownerName;
	}

private:
	int id;
	int validityInMonths;
	std::string ownerName;

public:
	int GetId()
	{
		return this->id;
	}
	bool Extend(int numOfMonths)
	{
		if (numOfMonths <= 0)
			return false;

		validityInMonths += numOfMonths;
		return true;
	}
	bool Cancel()
	{
		if (validityInMonths == 0)
			return false;

		validityInMonths = 0;
		return true;
	}
	std::string GetInfo()
	{
		return "Subscription ID: " + std::to_string(this->id) + ". Valid for "
			+ std::to_string(this->validityInMonths) + " months. Owner is "
			+ this->ownerName + ".";
	}
};

// shows all existing subscriptions in array
void ShowAllSubscriptions(Subscription*subscriptions, int count)
{
	bool subscriptionsNotFound = true;

	for (int i = 0; i < count; i++)
	{
		// search existing subscription
		if (subscriptions[i].GetId() != 0)
		{
			subscriptionsNotFound = false;
			std::cout << subscriptions[i].GetInfo() << std::endl;
		}
	}

	// if there are no subscriptions in the system - say that to user
	if (subscriptionsNotFound)
	{
		std::cout << "There are no subscriptions in the system!" << std::endl;
	}
}

// remove spaces at the beginning and at the end
std::string Trim(std::string str)
{
	while (str[0] == ' ')
		str.erase(0, 1);

	while (str[str.length() - 1] == ' ')
		str.erase(str.length() - 1, 1);

	return str;
}

// remove extra spaces
std::string RemoveExtraSpaces(std::string str)
{
	int index = 0;

	// starting from index 'cause there are no reason
	// to check befour found spaces again
	while ((index = str.find("  "), index) != -1)
		str = str.replace(index, 2, " ");

	return str;
}

// splits words by spaces
std::string* SplitBySpace(std::string str, int &wordsCount)
{
	int begin = 0, end, index = -1;
	std::string* words;

	// set 0 'cause someone can pass non-zero value
	wordsCount = 0;

	// remove spaces at the beginning and at the end
	str = Trim(str);

	//remove multiple spaces
	str = RemoveExtraSpaces(str);

	// count words to create dynamic array
	while ((index = str.find(' ', index + 1)) != -1)
		wordsCount++;

	// last word is not followed by space, so add it
	// (words count = spacesCount + 1)
	wordsCount++;
	words = new std::string[wordsCount];

	// reuse index for another task
	index = 0;

	while ((end = str.find(' ', begin)) != -1)
	{
		words[index] = str.substr(begin, end - begin);
		index++;

		// jump over space
		begin = end + 1;
	}

	// last word
	words[index] = str.substr(begin);

	return words;
}

// search id in array of object with specific id
int SearchById(Subscription*subscriptions, int id)
{
	for (int i = 0; i < 10; i++)
	{
		if (subscriptions[i].GetId() == id)
		{
			return i;
		}
	}

	// if ibject is not present in array - return index -1
	return -1;
}

int main()
{
	Subscription subscriptions[10];
	Subscription nonExisting;
	std::string command;
	std::string* splitedCommand;
	int wordsCount = 0;
	int idInArray;

	while (command != "quit")
	{
		ShowAllSubscriptions(subscriptions, 10);

		std::cout << "Enter command: ";
		std::getline(std::cin, command);

		splitedCommand = SplitBySpace(command, wordsCount);

		if (splitedCommand[0] == "extend")
		{
			// extend command consists of 3 parameters
			// if there are more than 3 -> we don't use them
			// if there are less than 3 -> we cant do operations
			if (wordsCount < 3)
			{
				std::cout << "Invalid paramters!" << std::endl;
				continue;
			}

			// search subscriptions with specific ID
			idInArray = SearchById(subscriptions, std::stoi(splitedCommand[1]));

			if (idInArray != -1)
			{
				if (!subscriptions[idInArray].Extend(std::stoi(splitedCommand[2])))
				{
					std::cout << "Invalid month count parameter!" << std::endl;
				}
			}
			// if subscriptions with specific id was not found -> say that to user
			else
			{
				std::cout << "Subscription with ID " << splitedCommand[1]
					<< " was not found!" << std::endl;
			}
		}
		else if (splitedCommand[0] == "cancel")
		{
			if (wordsCount < 2)
			{
				std::cout << "Invalid paramters!" << std::endl;
				continue;
			}

			idInArray = SearchById(subscriptions, std::stoi(splitedCommand[1]));

			if (idInArray != -1)
			{
				if (!subscriptions[idInArray].Cancel())
				{
					std::cout << "Validity month count was 0 before operation!" << std::endl;
				}
			}
			else
			{
				std::cout << "Subscription with ID " << splitedCommand[1]
					<< " was not found!" << std::endl;
			}
		}
		else if (splitedCommand[0] == "delete")
		{
			if (wordsCount < 2)
			{
				std::cout << "Invalid paramters!" << std::endl;
				continue;
			}

			idInArray = SearchById(subscriptions, std::stoi(splitedCommand[1]));

			if (idInArray != -1)
			{
				subscriptions[idInArray] = nonExisting;
			}
			else
			{
				std::cout << "Subscription with ID " << splitedCommand[1]
					<< " was not found!" << std::endl;
			}
		}
		else if (splitedCommand[0] == "create")
		{
			if (wordsCount < 4)
			{
				std::cout << "Invalid paramters!" << std::endl;
				continue;
			}

			idInArray = SearchById(subscriptions, std::stoi(splitedCommand[1]));

			if (idInArray != -1)
			{
				std::cout << "Subscription with ID " << splitedCommand[1]
					<< " already exists!" << std::endl;
			}
			else
			{
				// reusing variable. searching id of free cell
				idInArray = SearchById(subscriptions, 0);

				// if all space was used
				if (idInArray == -1)
				{
					std::cout << "Unfortunately, all subscriptions are used!" << std::endl;
				}
				else
				{
					subscriptions[idInArray] = Subscription
					(
						std::stoi(splitedCommand[1]),
						0,
						splitedCommand[2] + " " + splitedCommand[3]
					);
				}
			}
		}
	}

	return 0;
}