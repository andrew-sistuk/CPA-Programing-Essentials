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

Node::Node(int val) : value(val), next(nullptr)
{
	cout << "+Node" << endl;
}

Node::~Node()
{
	cout << "-Node" << endl;
}

class List
{
public:
	List();
	~List();
	void push_front(int value);
	bool pop_front(int& value);

private:
	Node* head;
};

List::List() : head(nullptr) {}

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

int main()
{
	List list;

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);

	return 0;
}