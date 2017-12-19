#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> rods;

void Print()
{
	for (int i = 0; i < rods.size(); i++)
	{
		cout << "tower " << i + 1 << ": ";
		if (rods[i].size() == 0) cout << "empty";
		else for (int j = 0; j < rods[i].size(); j++)
		{
			cout << rods[i][j] << " ";
		}
		cout << endl;
	}
}


void Action(string user)
{
	int from, to;
	from = user[0] - 49;
	to = user[1] - 49;
	try
	{
		if (user.size() > 2 || from > 2 || to > 2)
			throw 1;

		if ((rods[from]).size() == 0)
			throw 2;

		int disk = rods[from][rods[from].size() - 1];

		if (rods[to].size() > 0 && rods[to][rods[to].size() - 1] < disk)
			throw 3;
		rods[from].pop_back();

		rods[to].push_back(disk);
	}
	catch (...)
	{
		throw;
	}
}

int main()
{	
	rods.push_back(vector<int>());
	rods.push_back(vector<int>());
	rods.push_back(vector<int>());
	rods[0].push_back(3);
	rods[0].push_back(2);
	rods[0].push_back(1);

	string user;
	Print();
	while (rods[2].size() < 3)
	{
		cin >> user;
		try
		{
			Action(user);
		}
		catch (int s)
		{
			if (s ==1)
				cout << "one or both towers are not in the 1–3 range" << endl;
			if (s == 2)
				cout << "there are no disks at the source rod" << endl;
			if (s == 3)
				cout << "disk moved is of an incorrect size (bigger than the one in the target rod)" << endl;
		}
		Print();
	}
	Print();

    return 0;
}