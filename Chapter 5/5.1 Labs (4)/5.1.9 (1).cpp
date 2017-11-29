#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	string name;
	string lastName;
	double weight;
	int age;
};

void print(Person* person)
{
	cout << person->name << " is " << person->age << " years old" << endl;
}

int main()
{
	Person person;

	person.name = "Harry";
	person.lastName = "Homtom";
	person.age = 23;
	person.weight = 96.8;

	cout << "Meet " << person.name + " " + person.lastName << endl;
	print(&person);
	cout << "My weight is " << person.weight << "!" << endl;

	return 0;
}