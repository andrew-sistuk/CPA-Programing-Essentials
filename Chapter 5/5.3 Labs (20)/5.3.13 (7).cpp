#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	Node(int val);
	~Node();
	int value;
	Node* next;
};

Node::Node(int val) : value(val), next(nullptr) {}

Node::~Node() {}

class List
{
public:
	List(List &other);
	List();
	~List();
	void push_front(int value);
	bool pop_front(int& value);
	void push_back(int value);
	bool pop_back(int& value);
	int at(int index);
	void insert_at(int index, int value);
	void remove_at(int index);
	int size();

private:
	int currentIndex;
	Node* head;
	Node* tail;
};

List::List() : head(nullptr), tail(nullptr)
{
	this->currentIndex = 0;
}

List::List(List &other)
{
	this->head = new Node(other.head->value);
	Node* headCopy = this->head;
	Node* otherHeadCopy = other.head;

	// copiying every node separatly
	while (other.head->next != nullptr)
	{
		this->head->next = new Node(other.head->next->value);

		other.head = other.head->next;
		this->head = this->head->next;
	}

	tail = this->head;
	other.head = otherHeadCopy;
	this->head = headCopy;
}


List::~List()
{
	Node* new_head;

	while (this->head != nullptr)
	{
		new_head = head->next;
		delete head;
		this->head = new_head;
	}
}

void List::insert_at(int index, int value)
{
	Node* firstElement = this->head;
	Node* newNode = new Node(value);

	// every time start from beginning
	this->currentIndex = 0;

	if (index == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		while ((index - 1) > this->currentIndex)
		{
			this->currentIndex++;
			this->head = head->next;
		}

		newNode->next = head->next;
		head->next = newNode;
		this->head = firstElement;
	}
}

void List::remove_at(int index)
{
	Node* firstElement = this->head;
	Node* exChangeNode = nullptr;

	// every time start from beginning
	this->currentIndex = 0;

	if (index == 0)
	{
		exChangeNode = head;
		head = head->next;
		delete exChangeNode;
	}
	else
	{
		while ((index - 1) > this->currentIndex)
		{
			this->currentIndex++;
			this->head = head->next;
		}

		// save before deleting
		if (this->head->next->next != nullptr)
			exChangeNode = this->head->next->next;

		// next el is target, so
		delete this->head->next;
		this->head->next = exChangeNode;
		this->head = firstElement;
	}
}

int List::at(int index)
{
	// saving head to restore it at the end
	Node* firstElement = this->head;
	int value;

	// every time start from beginning
	this->currentIndex = 0;

	while (index > this->currentIndex)
	{
		this->currentIndex++;
		this->head = head->next;
	}

	value = this->head->value;
	this->head = firstElement;

	return value;
}

void List::push_front(int value)
{
	Node* new_head = new Node(value);
	new_head->next = head;

	if (this->head == nullptr)
		this->tail = new_head;

	head = new_head;
}

bool List::pop_front(int& value)
{
	if (head == nullptr)
		return false;

	Node* new_head = head->next;
	value = head->value;
	delete head;
	head = new_head;

	return true;
}

void List::push_back(int value)
{
	Node* new_tail = new Node(value);

	// if pushed element is first
	// (list is clear)
	if (head == nullptr)
	{
		head = new_tail;
		tail = new_tail;
	}
	else
	{
		tail->next = new_tail;
		tail = new_tail;
	}
}

bool List::pop_back(int& value)
{
	Node* currentElement = head;

	// if list is clear
	if (currentElement == nullptr)
		return false;

	// if this is the last element in list
	if (currentElement == tail)
	{
		value = head->value;
		tail = nullptr;
		head = nullptr;
	}
	else
	{
		// getting last element
		while (currentElement->next != tail)
			currentElement = currentElement->next;

		// saving value and removing element
		value = currentElement->next->value;
		delete currentElement->next;
		// mark next element as null
		currentElement->next = nullptr;
		// change current tail
		tail = currentElement;
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

void printList(List &list)
{
	for (int i = 0; i < list.size(); i++)
		cout << "list[" << i << "] == " << list.at(i) << endl;
}

int main()
{
	List list1;

	// the same problem as in prev task
	//list1.push_front(1);
	//list1.push_front(2);
	//list1.push_front(3);
	//list1.push_front(4);

	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);

	cout << "list1" << endl;
	printList(list1);
	cout << endl;

	List list2(list1);
	cout << "list2" << endl;
	printList(list2);
	cout << endl;

	list1.insert_at(1, 6);
	list2.remove_at(2);

	cout << "list1" << endl;
	printList(list1);
	cout << endl;

	cout << "list2" << endl;
	printList(list2);
	cout << endl;

	return 0;
}