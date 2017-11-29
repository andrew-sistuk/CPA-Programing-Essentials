#include <iostream>

class AdHocSquare
{
public:
	AdHocSquare(double side);
	void set_side(double side);
	double get_area();

private:
	double side;
};

AdHocSquare::AdHocSquare(double side)
{
	if (side <= 0)
		side = 1;

	this->side = side;
}

// setter

void AdHocSquare::set_side(double side)
{
	if (side <= 0)
		return;

	this->side = side;
}

double AdHocSquare::get_area()
{
	return this->side * this->side;
}

class LazySquare
{
public:
	LazySquare(double side);
	void set_side(double side);
	double get_area();

private:
	double side;
	double area;
	bool side_changed;
};

LazySquare::LazySquare(double side)
{
	if (side <= 0)
		side = 1;

	this->side = side;
}

// setter

void LazySquare::set_side(double side) 
{
	if (side <= 0)
		return;

	this->side = side;
	this->side_changed = true;
}

double LazySquare::get_area()
{
	// recalculate only if side was changed
	if (this->side_changed)
	{
		this->area = this->side * this->side;
		this->side_changed = false;
	}

	return this->area;
}

int main()
{
	AdHocSquare adHocSqure(5.5);
	LazySquare lazySquare(5.5);
	std::cout << adHocSqure.get_area() << std::endl;

	adHocSqure.set_side(10.);
	std::cout << adHocSqure.get_area() << std::endl;

	std::cout << lazySquare.get_area() << std::endl;
	
	lazySquare.set_side(10.0);

	std::cout << lazySquare.get_area() << std::endl;

	return 0;
}