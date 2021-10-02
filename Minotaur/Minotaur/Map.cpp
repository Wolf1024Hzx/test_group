#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
#include "Map.h"

using namespace std;

MAP::MAP(vector<string>& temp)
{
	height = (int)temp.size();
	if (!height) length = (int)temp[0].length();
	else length = 0;
	Map = new char* [height];
	for (int i = 0; i < height; i++) Map[i] = new char[length];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < length; j++)
			Map[i][j] = temp[i][j];
	return;
}

MAP::MAP(MAP& anotherMap)
{
	length = anotherMap.length;
	height = anotherMap.height;
	for (int i = 0; i < height; i++) Map[i] = new char[length];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < length; j++)
			Map[i][j] = anotherMap.Map[i][j];
	return;
}

void MAP::printMap()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
			cout << Map[i][j];
		cout << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	return;
}

MAP::~MAP()
{
	for (int i = 0; i < height; i++) delete[] Map[i];
	delete[] Map;
	return;
}