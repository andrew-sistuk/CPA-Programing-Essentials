#include <iostream>
#include <string>

using namespace std;

class FarmAnimal {
public:
	FarmAnimal(double water_consumption, double grass_consumption);
	double getWaterConsumption();
	double getGrassConsumption();

private:
	double water_consumption;
	double grass_consumption;
};

FarmAnimal::FarmAnimal(double water_consumption, double grass_consumption)
{
	this->water_consumption = water_consumption;
	this->grass_consumption = grass_consumption;
}

double FarmAnimal::getWaterConsumption()
{
	return water_consumption;
}

double FarmAnimal::getGrassConsumption()
{
	return grass_consumption;
}

class DummyAnimal : public FarmAnimal
{
public:
	DummyAnimal();
};

DummyAnimal::DummyAnimal() : FarmAnimal(10.0, 150.0) {}

class DoublingAnimal : public FarmAnimal
{
public:
	DoublingAnimal(double given_water_consumption, double given_grass_consumption);
};

DoublingAnimal::DoublingAnimal(double given_water_consumption, double given_grass_consumption)
	: FarmAnimal(2 * given_water_consumption, 10 * given_grass_consumption) {}

void printConsumption(FarmAnimal animal)
{
	cout << "This animal consumes " << animal.getWaterConsumption()
		<< " liters of water and " << animal.getGrassConsumption()
		<< "kg of grass." << endl;
}

int main()
{
	FarmAnimal animalA(5, 150);
	DummyAnimal animalB;
	DoublingAnimal animalC(21, 150);

	cout << "animalA consumes " << animalA.getWaterConsumption()
		<< " liters of water." << animalA.getGrassConsumption()
		<< "kg of grass." << endl;
	cout << "What about the others?" << endl;

	printConsumption(animalB);
	printConsumption(animalC);

	return 0;
}