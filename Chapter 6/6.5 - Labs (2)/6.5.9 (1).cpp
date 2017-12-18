#include <iostream>
#include <string>

using namespace std;


class Engine
{
private:
	double volume;

public:
	void Print();
	Engine();
	Engine(double volume);
};

Engine::Engine()
{
	this->volume = 0.0;
}

Engine::Engine(double volume)
{
	this->volume = volume;
}

void Engine::Print()
{
	cout.precision(1);
	cout << "Engine: " << fixed << this->volume << endl;
}


class Wheel
{
private:
	int size;

public:
	Wheel();
	Wheel(int size);
	void Print();
};

Wheel::Wheel()
{
	this->size = 0;
}

Wheel::Wheel(int size)
{
	this->size = size;
}

void Wheel::Print()
{
	cout << "Wheel: " << this->size << "inches" << endl;
}


class Chassis
{
private:
	string type;

public:
	Chassis();
	Chassis(string type);
	void Print();
};

Chassis::Chassis()
{
	this->type = "normal";
}

Chassis::Chassis(string type)
{
	this->type = type;
}

void Chassis::Print()
{
	cout << "Chassis: " << this->type << endl;
}


class Light
{
private:
	string type;

public:
	Light();
	Light(string type);
	void Print();
};

Light::Light()
{
	this->type = "Type 1";
}

Light::Light(string type)
{
	this->type = type;
}

void Light::Print()
{
	cout << "Light: " << this->type << endl;
}


class Body
{
private:
	string color;

public:
	Body();
	Body(string color);
	void Print();
};

Body::Body()
{
	this->color = "Black";
}

Body::Body(string color)
{
	this->color = color;
}

void Body::Print()
{
	cout << "Body: " << this->color << endl;
}


class Car
{
private:
	Engine engine;
	Wheel *wheels;
	Chassis chassis;
	Light *lights;
	Body body;

public:
	Car();
	Car(Engine engine, Wheel *wheels, Chassis chassis, Light * lights, Body body);
	void Print();
};

Car::Car()
{
	this->engine = Engine();
	this->body = Body();
	this->chassis = Chassis();
	this->lights = new Light[10];
	this->wheels = new Wheel[4];
}

Car::Car(Engine engine, Wheel *wheels, Chassis chassis, Light * lights, Body body)
{
	this->engine = engine;
	this->wheels = wheels;
	this->chassis = chassis;
	this->lights = lights;
	this->body = body;
}

void Car::Print()
{
	this->engine.Print();

	for (int i = 0; i < 4; i++)
		wheels[i].Print();

	this->chassis.Print();

	for (int i = 0; i < 10; i++)
		lights[i].Print();

	this->body.Print();
}


int main()
{
	Car *car = new Car(Engine(1.0), new Wheel[4]{ Wheel(16), Wheel(16), Wheel(16), Wheel(16) },
		Chassis("Normal"), new Light[10]{ Light("Type 1"), Light("Type 1"), Light("Type 2"), Light("Type 2") ,
		Light("Type 3"), Light("Type 3"), Light("Type 4"), Light("Type 4"), Light("Type 5"), Light("Type 5") },
		Body("Black"));

	car->Print();

	return 0;
}