#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	Node(int val);
	int value;
	Node* next;
};

Node::Node(int val) : value(val), next(nullptr) {}

class List
{
public:
	List();
	~List();
	void push_front(int value);
	bool pop_front(int& value);
	void push_back(int value);
	int size();
private:
	Node* head;
	Node* tail;
};

List::List() : head(nullptr), tail(nullptr) {}

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

int main()
{
	List list;
	int value = 0;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	while (list.pop_front(value))
		cout << value << endl;

	return 0;
}