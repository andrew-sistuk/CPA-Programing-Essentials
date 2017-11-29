#include <string>
#include <iostream>

class ShopItemOrder
{
public:
	ShopItemOrder(std::string name, double price, int numOfOrderedItems);

private:
	std::string name;
	double unitPrice;
	int numOfOrderedItems;

public:
	double GetTotalPrice();
	std::string GetInfo();

	void SetName(std::string name);
	void SetUnitPrice(double unitPrice);
	void SetNumOfOrderedItems(int numOfOrderedItems);

	std::string GetName();
	double GetUnitPrice();
	int GetNumOfOrderedItems();
};

// setters

void ShopItemOrder::SetName(std::string name)
{
	if (name.length() == 0)
		return;

	this->name = name;
}

void ShopItemOrder::SetNumOfOrderedItems(int numOfOrderedItems)
{
	if (numOfOrderedItems < 0)
		return;

	this->numOfOrderedItems = numOfOrderedItems;
}

void ShopItemOrder::SetUnitPrice(double unitPrice)
{
	if (unitPrice < 0)
		return;

	this->unitPrice = unitPrice;
}

// getters

std::string ShopItemOrder::GetName()
{
	return this->name;
}

int ShopItemOrder::GetNumOfOrderedItems()
{
	return this->numOfOrderedItems;
}

double ShopItemOrder::GetUnitPrice()
{
	return this->unitPrice;
}

ShopItemOrder::ShopItemOrder(std::string name, double unitPrice, int numOfOrderedItems)
{
	this->name = name;
	this->unitPrice = unitPrice;
	this->numOfOrderedItems = numOfOrderedItems;
}

double ShopItemOrder::GetTotalPrice()
{
	return numOfOrderedItems * unitPrice;
}

std::string  ShopItemOrder::GetInfo()
{
	return "Product name: " + this->name + "\n-----\nUnit price: " +
		std::to_string(this->unitPrice) + "\nNumber of ordered intems: "
		+ std::to_string(this->numOfOrderedItems) + "\n";
}

int main()
{
	ShopItemOrder order("Beer", 9.50, 5);

	std::cout << order.GetInfo() << std::endl;
	std::cout << "Total price is: " + std::to_string(order.GetTotalPrice()) << std::endl;

	std::cout << "Unit price: " + std::to_string(order.GetUnitPrice()) << std::endl;
	std::cout << "Name: " + order.GetName() << std::endl;
	std::cout << "Number of ordered items: " + std::to_string(order.GetNumOfOrderedItems()) << std::endl;
	

	order.SetName("Vodka");
	order.SetNumOfOrderedItems(190);
	order.SetUnitPrice(45.95);

	std::cout << order.GetInfo() << std::endl;
	std::cout << "Total price is: " + std::to_string(order.GetTotalPrice()) << std::endl;

	std::cout << "Unit price: " + std::to_string(order.GetUnitPrice()) << std::endl;
	std::cout << "Name: " + order.GetName() << std::endl;
	std::cout << "Number of ordered items: " + std::to_string(order.GetNumOfOrderedItems()) << std::endl;

	