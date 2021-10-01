#include <vector>
#include <string>
#include "Map.h"

using namespace std;

MAP::MAP(vector<string>& temp)
{
	length = temp[0].length();
	height = temp.size();
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

MAP::~MAP()
{
	for (int i = 0; i < height; i++) delete[] Map[i];
	delete[] Map;
	return;
}