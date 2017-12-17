#include <iostream>
#include <string>

class FlightBooking
{
public:
	FlightBooking(int id, int capacity, int reserved);
	FlightBooking();

	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservations(int number_ob_seats);
	int getId() { return id; };

private:
	int id;
	int capacity;
	int reserved;
};

FlightBooking::FlightBooking()
{
	id = 0; capacity = 0; reserved = 0;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = capacity;
	if (reserved >= 0 && reserved <= 105 * capacity / 100)
		this->reserved = reserved;
	else
		this->reserved = 105 * capacity / 100;
}

void FlightBooking::printStatus()
{
	std::cout << "Flight " << this->id << ": " << this->reserved <<
		"/" << this->capacity << " (" << this->reserved * 100 / this->capacity <<
		"%) seats reserved" << std::endl;
}

bool FlightBooking::reserveSeats(int numberOfSeats)
{
	if (numberOfSeats > 0 && this->reserved + numberOfSeats <= 105 * capacity / 100)
	{
		this->reserved += numberOfSeats;
		return true;
	}
	return false;
}

bool FlightBooking::cancelReservations(int numberOfSeats)
{
	if (numberOfSeats > 0 && this->reserved - numberOfSeats >= 0) {
		this->reserved -= numberOfSeats;
		return true;
	}

	return false;
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
	int index;

	while ((index = str.find("  ")) != -1)
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

void ShowFligths(FlightBooking* booking, int flightCount)
{
	bool atLeastOneIsPresent = false;

	for (int i = 0; i < 10; i++)
	{
		if (booking[i].getId() != 0)
		{
			booking[i].printStatus();
			atLeastOneIsPresent = true;
		}
	}

	if (!atLeastOneIsPresent)
		std::cout << "There are no flights in the system!" << std::endl;
}

int main()
{
	FlightBooking booking[10];
	FlightBooking nonExsisting;

	std::string command = "";
	std::string* splitedCommand;
	int wordsCount = 0;
	bool operationIsCompleted;
	bool idExists;

	while (command != "quit")
	{
		ShowFligths(booking, 10);

		std::cout << "What would you like to do?: ";
		std::getline(std::cin, command);

		splitedCommand = SplitBySpace(command, wordsCount);

		operationIsCompleted = false;
		idExists = false;

		if (splitedCommand[0] == "add")
		{
			if (wordsCount < 3)
			{
				std::cout << "Incorrect parameters!" << std::endl;
				continue;
			}

			for (int i = 0; i < 10; i++)
			{
				if (booking[i].getId() == std::stoi(splitedCommand[1]))
				{
					operationIsCompleted = booking[i].reserveSeats(std::stoi(splitedCommand[2]));
					break;
				}
			}

			if (!operationIsCompleted)
			{
				std::cout
					<< "Cannot perform this operation: there are no flight"
					<< " with such ID or too much sits adding!"
					<< std::endl;
			}
		}
		else if (splitedCommand[0] == "cancel")
		{
			if (wordsCount < 3)
			{
				std::cout << "Incorrect parameters!" << std::endl;
				continue;
			}

			for (int i = 0; i < 10; i++)
			{
				if (booking[i].getId() == std::stoi(splitedCommand[1]))
				{
					operationIsCompleted = booking[i].cancelReservations(std::stoi(splitedCommand[2]));
					break;
				}
			}

			if (!operationIsCompleted)
			{
				std::cout
					<< "Cannot perform this operation: there are no flight"
					<< " with such ID or too much seats cancelling!"
					<< std::endl;
			}
		}
		else if (splitedCommand[0] == "create")
		{
			if (wordsCount < 3)
			{
				std::cout << "Incorrect parameters!" << std::endl;
				continue;
			}

			for (int i = 0; i < 10; i++)
			{
				if (booking[i].getId() == std::stoi(splitedCommand[1]))
				{
					idExists = true;
					break;
				}
			}

			if (!idExists)
			{
				for (int i = 0; i < 10; i++)
				{
					if (booking[i].getId() == 0)
					{
						booking[i] = FlightBooking(std::stoi(splitedCommand[1]),
							std::stoi(splitedCommand[2]), 0);
						operationIsCompleted = true;
						break;
					}
				}
			}

			if (!operationIsCompleted)
			{
				std::cout
					<< "Cannot perform this operation: flight with this id already exists "
					<< "or there are no free space in the array."
					<< std::endl;
			}
		}
		else if (splitedCommand[0] == "delete")
		{
			if (wordsCount < 2)
			{
				std::cout << "Incorrect parameters!" << std::endl;
				continue;
			}

			for (int i = 0; i < 10; i++)
			{
				if (booking[i].getId() == std::stoi(splitedCommand[1]) && booking[i].getId() != 0)
				{
					booking[i] = nonExsisting;
					operationIsCompleted = true;
					break;
				}
			}

			if (!operationIsCompleted)
			{
				std::cout
					<< "Cannot perform this operation: flight with this id does not exist!"
					<< std::endl;
			}
		}
	}

	std::cout << "User prompts were omitted in the output" << std::endl;

	return 0;
}