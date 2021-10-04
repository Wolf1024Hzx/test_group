#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
#include "Map.h"

using namespace std;

MAP::MAP(vector<string>& temp)
{
	begin_x = begin_y = end_x = end_y = 0;
	height = (int)temp.size();
	if (height) length = (int)temp[0].length();
	else length = 0;
	Map = new char* [height];
	for (int i = 0; i < height; i++) Map[i] = new char[length];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			Map[i][j] = temp[i][j];
			if (Map[i][j] == 'B') begin_x = i, begin_y = j;
			if (Map[i][j] == 'E') end_x = i, end_y = j;
		}
	}
	return;
}

MAP::MAP(MAP& anotherMap)
{
	length = anotherMap.length;
	height = anotherMap.height;
	begin_x = anotherMap.begin_x;
	begin_y = anotherMap.begin_y;
	end_x = anotherMap.end_x;
	end_y = anotherMap.end_y;
	for (int i = 0; i < height; i++) Map[i] = new char[length];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < length; j++)
			Map[i][j] = anotherMap.Map[i][j];
	return;
}

void MAP::printMap(int x, int y)
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i == x && j == y) cout << 'O';
			else if (Map[i][j] != ' ' && Map[i][j] != '*') cout << ' ';
			else cout << Map[i][j];
		}
		cout << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	return;
}

void MAP::findSolutionByDFS()
{
	stack<int> ans;
	if (dfs(begin_x, begin_y, ans))
	{
		cout << "We have found a way to successfully reach our destination !" << endl;
		cout << "here are the route:" << endl;
		while (ans.size() > 2)
		{
			cout << "(" << ans.top() << ", ";
			ans.pop();
			cout << ans.top() << ") -> ";
			ans.pop();
		}
		cout << "(" << ans.top() << ", ";
		ans.pop();
		cout << ans.top() << ")" << endl;
	}
	else cout << "We can't find the way to our destination~" << endl;
	return;
}

bool MAP::dfs(int x, int y, stack<int>& ans)
{
	Sleep(1000);
	printMap(x, y);
	if (Map[x][y] == 'E')
	{
		ans.push(x);
		ans.push(y);
		return true;
	}
	Map[x][y] = '#';
	if (y < length - 1 && (Map[x][y + 1] == ' ' || Map[x][y + 1] == 'E') && dfs(x, y + 1, ans))
	{
		ans.push(x);
		ans.push(y);
		return true;
	}
	printMap(x, y);
	if (x < height - 1 && (Map[x + 1][y] == ' ' || Map[x + 1][y] == 'E') && dfs(x + 1, y, ans))
	{
		ans.push(x);
		ans.push(y);
		return true;
	}
	printMap(x, y);
	if (x > 0 && (Map[x - 1][y] == ' ' || Map[x - 1][y] == 'E') && dfs(x - 1, y, ans))
	{
		ans.push(x);
		ans.push(y);
		return true;
	}
	printMap(x, y);
	if (y > 0 && (Map[x][y - 1] == ' ' || Map[x][y - 1] == 'E') && dfs(x, y - 1, ans))
	{
		ans.push(x);
		ans.push(y);
		return true;
	}
	printMap(x, y);
	return false;
}

MAP::~MAP()
{
	for (int i = 0; i < height; i++) delete[] Map[i];
	delete[] Map;
	return;
}