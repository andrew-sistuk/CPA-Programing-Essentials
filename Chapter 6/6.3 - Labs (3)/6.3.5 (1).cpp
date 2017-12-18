#include <iostream>

using namespace std;

class TreeDrawer
{
public:
	virtual void Draw()
	{
		cout << " /\\ " << endl;
	}
};

class LineTreeDrawer : public TreeDrawer
{
	void Draw()
	{
		TreeDrawer::Draw();
		cout << "//\\\\" << endl;
	}
};

class PlusTreeDrawer : public TreeDrawer
{
	void Draw()
	{
		TreeDrawer::Draw();
		cout << "/++\\" << endl;
	}
};

class StarTreeDrawer : public TreeDrawer
{
	void Draw()
	{
		TreeDrawer::Draw();
		cout << "/**\\" << endl;
	}
};

int main()
{
	TreeDrawer** drawers = new TreeDrawer*[3];

	drawers[0] = new LineTreeDrawer();
	drawers[2] = new PlusTreeDrawer();
	drawers[1] = new StarTreeDrawer();

	for (int i = 0; i < 3; i++)
	{
		cout << "Drawing " << i + 1 << ":" << endl;
		drawers[i]->Draw();
	}

	return 0;
}