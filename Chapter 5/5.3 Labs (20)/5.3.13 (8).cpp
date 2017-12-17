/*  
	ALL PREVIOUS LABS AND THIS THROWS EXEPTIONS IN DIFFERENT SITUATIONS
	IN MOST CASES IT OUTOFRANGE EXCEPTION
	WE DIDN'T LEARN EXCEPTION HANDLING YET
	SO I DIDN'T USED IT
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

class Node
{

public:
	Node(int val);
	~Node();
	int value;
	Node* prev;
	Node* next;
};

Node::Node(int val) : value(val), next(nullptr), prev(nullptr) {}

Node::~Node() {}

class List
{
public:
	List();
	~List();
	List(List &other);
	void push_front(int value);
	bool pop_front(int &value);
	void push_back(int value);
	bool pop_back(int &value);
	int at(int index);
	void insert_at(int index, int value);
	void remove_at(int index);
	int size();

private:
	Node* head;
	Node* tail;
};

List::List() : head(nullptr), tail(nullptr)
{
}

List::~List() {}

List::List(List &other)
{
	this->head = new Node(other.head->value);
	Node* headCopy = this->head;
	Node* otherHeadCopy = other.head;

	// copiying every node separatly
	while (other.head->next != nullptr)
	{
		this->head->next = new Node(other.head->next->value);
		this->head->next->prev = this->head;

		other.head = other.head->next;
		this->head = this->head->next;
	}

	this->tail = this->head;
	other.head = otherHeadCopy;
	this->head = headCopy;
}

void List::push_front(int value)
{
	Node* auxiliary = nullptr;

	if (head == nullptr)
	{
		head = new Node(value);
		head->next = nullptr;
		head->prev = nullptr;
		tail = head;
	}
	else
	{
		auxiliary = head;
		head = new Node(value);
		head->next = auxiliary;
		head->prev = nullptr;
		auxiliary->prev = head;
	}
}

bool List::pop_front(int &value)
{
	Node* auxiliary = head;

	if (head == nullptr)
		return false;

	if (head->next == nullptr)
	{
		value = head->value;
		auxiliary = head;
		head = nullptr;
	}
	else
	{
		head->next->prev = nullptr;
		head = head->next;
		value = auxiliary->value;
	}

	delete auxiliary;
	return true;
}

void List::push_back(int value)
{
	Node* new_tail = new Node(value);
	new_tail->next = nullptr;

	if (head == nullptr)
	{
		head = new_tail;
		tail = new_tail;
		head->prev = nullptr;
	}
	else
	{
		new_tail->prev = tail;
		tail->next = new_tail;
		tail = new_tail;
	}
}

bool List::pop_back(int& value)
{
	Node* auxiliary = head;

	if (auxiliary == nullptr)
		return false;

	if (auxiliary == tail)
	{
		value = head->value;
		tail = nullptr;
		head = nullptr;
	}
	else
	{
		auxiliary = tail;
		value = tail->value;
		tail->prev->next = nullptr;
		tail = tail->prev;

		delete auxiliary;
	}

	return true;
}

int List::size()
{
	Node* firstElement = head;
	int size = 0;

	while (head != nullptr)
	{
		size++;
		head = head->next;
	}

	head = firstElement;

	return size;
}

int List::at(int index)
{
	Node* firstElement = this->head;
	int value;

	int currentIndex = 0;

	while (index > currentIndex)
	{
		currentIndex++;
		this->head = head->next;
	}

	value = this->head->value;
	this->head = firstElement;

	return value;
}

void List::insert_at(int index, int value)
{
	Node* auxiliary = this->head;
	Node* newNode = new Node(value);

	int currentIndex = 0;

	while (index > currentIndex)
	{
		currentIndex++;
		head = head->next;
	}

	// can insert only in range 1-size()-2
	// for inserting in 0 and in size()-1 
	// we have push_front() and push_back()
	if (head != nullptr && head->prev != nullptr)
	{
		newNode->next = head;
		newNode->prev = head->prev;
		head->prev->next = newNode;
		head->prev = newNode;
	}

	head = auxiliary;
}

void List::remove_at(int index)
{
	Node* auxiliary;
	Node* firstElement = head;

	int currentIndex = 0;

	// is list is emty - we have nothing to remove
	if (this->head == nullptr)
		return;

	while (index > currentIndex)
	{
		head = head->next;
		currentIndex++;
	}

	// target element
	auxiliary = head;

	// if it is only one element in list
	if (head->next == nullptr && head->prev == nullptr)
	{
		firstElement = nullptr;
	}
	// if it is last element in list
	else if (head->next == nullptr && head->prev != nullptr)
	{
		head->prev->next = nullptr;
	}
	// it it is first element in list
	else if (head->next != nullptr && head->prev == nullptr)
	{
		firstElement = head->next;
		head->next->prev = nullptr;
	}
	else
	{
		head->prev->next = head->next;
		head->next->prev = head->prev;
	}

	head = firstElement;
	delete auxiliary;
}

void printList(List &list)
{
	for (int i = 0; i < list.size(); i++)
		cout << "list[" << i << "] == " << list.at(i) << endl;
}

int main()
{
	List list;
	int value;

	list.push_front(3);
	list.push_front(2);
	list.push_front(1);

	printList(list);

	cout << endl;

	list.insert_at(2, 0);

	printList(list);

	List list2(list);

	cout << endl;
	
	while (list2.pop_back(value))
		cout << value << endl;

	cout << endl;
	printList(list);

	cout << endl;
	printList(list2);

	return 0;
}