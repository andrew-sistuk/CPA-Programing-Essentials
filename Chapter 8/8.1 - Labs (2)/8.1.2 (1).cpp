#include <string>
#include <iostream>

using namespace std;


class Stack {
private:
	int *stackstore;
	int stacksize;
	int SP;
public:
	Stack(int size) throw(string, string) {
		if (size <= 0)
			throw string("size must be >= 0");
		try {
			stackstore = new int[size];
		}
		catch (bad_alloc ba) {
			throw string("stack_bad_alloc");
		}
		stacksize = size;
		SP = 0;
	}
	~Stack(void) {
		delete stackstore;
	}
	void push(int value) throw(string) {
		if (SP == stacksize)
			throw string("stack size exceeded");
		stackstore[SP++] = value;
	}
	int pop(void) throw(string) {
		if (SP == 0)
			throw string("stack is empty");
		return stackstore[--SP];
	}
	int top(void) throw(string) {
		if (SP == 0)
			throw string("stack is empty");
		return stackstore[SP];
	}
	Stack& operator<< (int v) throw(string) {
		push(v);
		return *this;
	}
	Stack& operator >> (int &v) throw(string) {
		v = pop();
		return *this;
	}
};

int main(void) {
	int n;

	cout << "Enter how many items should be pushed onto the stack: ";
	cin >> n;
	Stack stk(n);
	int j;
	try
	{
		for (int i = 0; i < n; i++)
		{
			cin >> j;
			stk << j;
		}
	}
	catch (string e)
	{
		cout << "Exeption: " << e;
	}

	cout << "Enter how many items your program should print: ";
	cin >> n;
	try
	{
		for (int i = 0; i < n; i++)
		{
			stk >> j;
			cout << j << endl;
		}
	}
	catch (string e)
	{
		cout << "Exeption: " << e;
	}


	return 0;
}