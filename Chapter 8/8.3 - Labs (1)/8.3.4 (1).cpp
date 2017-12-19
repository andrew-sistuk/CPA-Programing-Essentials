#include <iostream>
#include <string>
#include <set>
using namespace std;

struct Node
{

	int value;
	Node* leftChild;
	Node* rightChild;
	Node() : Node(0) { };
	Node(int value)
	{
		this->value = value;
		leftChild = nullptr;
		rightChild = nullptr;
	}
	string Print()
	{
		string s = "";
		if (leftChild != nullptr) s += leftChild->Print();
		s.append(to_string(value));
		s.append(" ");
		if (rightChild != nullptr) s += rightChild->Print();
		return s;
	}
};

class btree
{

public:
	Node root;
	void Add(int value);
	bool Find(int value);
	btree(int value)
	{
		root = Node(value);
	}

};
bool btree::Find(int value)
{
	Node* temp = &this->root;
	while (temp != nullptr && temp->value != value)
	{
		if (temp->value > value) temp = temp->leftChild;
		else temp = temp->rightChild;
	}
	return temp != nullptr && temp->value == value;
}
void btree::Add(int value)
{
	if (!Find(value))
	{
		Node* temp = &this->root;
		while (temp->value != value)
		{
			if (temp->value > value)
			{
				if (temp->leftChild != nullptr)
					temp = temp->leftChild;
				else break;
			}
			else
			{
				if (temp->rightChild != nullptr)
					temp = temp->rightChild;
				else break;
			}
		}

		if (temp->value > value)
			temp->leftChild = new Node(value);
		else
			temp->rightChild = new Node(value);

	}
}
ostream& operator<<(ostream& os, btree& tree)
{
	os << tree.root.Print();
	return os;
}

int main()
{
	cout << "Input nodes. To stop type \"stop\"" << endl;

	int node;
	string line;
	cin >> line;
	btree tree(atoi(line.c_str()));
	do
	{
		cin >> line;
		if (line == "stop") break;
		node = atoi(line.c_str());
		tree.Add(node);
	} while (true);

	cout << tree << endl;

	return 0;
}