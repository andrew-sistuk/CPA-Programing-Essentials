#include <iostream>

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
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
	this->reserved = reserved;
}

int main() {

	int reserved = 0,
		capacity = 0;

	std::cout << "Provide flight capacity: ";
	std::cin >> capacity;

	std::cout << "Provide number of reserved seats: ";
	std::cin >> reserved;

	FlightBooking booking(1, capacity, reserved);

	booking.printStatus();

	return 0;
}