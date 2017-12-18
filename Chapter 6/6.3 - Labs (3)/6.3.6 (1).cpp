#include <iostream>

using namespace std;

class Piece
{
public:
	// initial pos is b1
	Piece() { x = 98; y = 1; }

protected:
	// x - horizontal (letters) (97-104)
	char x;
	// y - vertical (digits) (1-8)
	int y;

public:
	virtual bool CheckMove(int x, int y)
	{
		// all pieces can't go through board boundary
		if (x < 97 || x > 104 || y < 1 || y > 8)
			return false;

		return true;
	}
};

class Man : public Piece
{
	bool CheckMove(int x, int y)
	{
		// can go only foward
		if (x < this->x)
			return false;

		// to go by diagonal - both x and y must change
		// substraction is 1 'cause we can do only one step
		if (abs(this->x - x) != 1 || abs(this->y - y) != 1)
			return false;

		return Piece::CheckMove(x, y);
	}
};

class King : public Piece
{
	bool CheckMove(int x, int y)
	{
		// to go by diagonal - both x and y must change
		if (this->x - x == 0 || this->y - y == 0)
			return false;

		// check diagonal (both mush be changed at same value)
		if (this->x - x != this->y - y)
			return false;

		return Piece::CheckMove(x, y);
	}
};

int main()
{
	Piece* man = new Man();
	Piece* king = new King();

	cout << (man->CheckMove('c', 2) ? "true" : "false") << endl;
	cout << (king->CheckMove('d', 3) ? "true" : "false") << endl;
	cout << (man->CheckMove('d', 3) ? "true" : "false") << endl;

	return 0;
}