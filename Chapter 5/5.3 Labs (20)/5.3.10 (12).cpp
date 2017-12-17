#include <iostream>
#include <string>

using namespace std;

class FarmAnimal
{
public:
	FarmAnimal(double water_consumption);
	double getWaterConsumption();
private:
	double water_consumption;
};

class Sheep : public FarmAnimal
{
public:
	Sheep(double weight);
};

Sheep::Sheep(double weight) : FarmAnimal(weight / 10 * 1.1) {}

class Horse : public FarmAnimal
{
public:
	Horse(double weight);
};

Horse::Horse(double weight) : FarmAnimal(weight / 100 * 6.8) {}

class Cow : public FarmAnimal
{
public:
	Cow(double weight);
};

Cow::Cow(double weight) : FarmAnimal(weight / 100 * 8.6) {}

FarmAnimal::FarmAnimal(double water_consumption)
{
	this->water_consumption = water_consumption;
}

double FarmAnimal::getWaterConsumption()
{
	return water_consumption;
}

class ConsumptionAccumulator
{
public:
	ConsumptionAccumulator();
	double getTotalConsumption();
	void addConsumption(FarmAnimal animal);

private:
	double total_consumption;
};

ConsumptionAccumulator::ConsumptionAccumulator() :
	total_consumption(0) {}

double ConsumptionAccumulator::getTotalConsumption()
{
	return total_consumption;
}

void ConsumptionAccumulator::addConsumption(FarmAnimal animal)
{
	total_consumption += animal.getWaterConsumption();
}

int main()
{
	ConsumptionAccumulator accumulator;
	string input;
	string animal;
	int weight;

	for (;;)
	{
		cout << "Enter animal and weight: ";
		getline(cin, input);

		animal = input.substr(0, input.find(' '));
		weight = stoi(input.substr(input.find(' ') + 1));

		if (animal == "horse")
			accumulator.addConsumption(Horse(weight));
		else if (animal == "cow")
			accumulator.addConsumption(Cow(weight));
		else if (animal == "sheep")
			accumulator.addConsumption(Cow(weight));

		cout << accumulator.getTotalConsumption() << endl;
	}
	return 0;
}