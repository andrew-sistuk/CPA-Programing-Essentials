#include <iostream>
#include <string>

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservations(int number_ob_seats);
private:
	int id;
	int capacity;
	int reserved;
};

void FlightBooking::printStatus()
{
	std::cout << "Flight " << this->id << ": " << this->reserved <<
		"/" << this->capacity << " (" << this->reserved * 100 / this->capacity <<
		"%) seats reserved" << std::endl;
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

int main()
{
	int reserved = 0,
		capacity = 0;

	std::string command = "";
	std::string* splitedCommand;
	int wordsCount = 0;

	std::cout << "Provide flight capacity: ";
	std::cin >> capacity;

	std::cout << "Provide number of reserved seats: ";
	std::cin >> reserved;

	// we must flush cin before using getline
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	FlightBooking booking(1, capacity, reserved);

	while (command != "quit")
	{
		booking.printStatus();

		std::cout << "What would you like to do?: ";
		getline(std::cin, command);

		splitedCommand = SplitBySpace(command, wordsCount);

		if (splitedCommand[0] == "cancel")
		{
			if (wordsCount < 2)
			{
				std::cout << "Incorrect parameters!" << std::endl;
				continue;
			}

			if (!booking.cancelReservations(std::stoi(splitedCommand[1])))
				std::cout << "Cannot perform this operation" << std::endl;
		}
		else if (splitedCommand[0] == "add")
		{
			if (wordsCount < 2)
			{
				std::cout << "Incorrect parameters!" << std::endl;
				continue;
			}

			if (!booking.reserveSeats(std::stoi(splitedCommand[1])))
				std::cout << "Cannot perform this operation" << std::endl;
		}
	}

	std::cout << "User prompts were omitted in the output" << std::endl;

	return 0;
}