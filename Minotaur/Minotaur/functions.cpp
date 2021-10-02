#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include "functions.h"
#include "Map.h"

using namespace std;

AllMaps loadAllMaps()
{
	fstream readfile("../savedata/MapNames.txt", ios::binary | ios::in);
	string file_name;
	vector<string> namesOfMaps;
	unordered_set<string> names;
	while (getline(readfile, file_name))
	{
		namesOfMaps.push_back(file_name);
		names.insert(file_name);
	}
	AllMaps maps(namesOfMaps, names);
	return maps;
}

vector<string> loadMap(int no)
{
	stringstream ss;
	string pathOfFile = "../savedata/No";
	ss << pathOfFile << no << ".txt";
	ss >> pathOfFile;
	fstream readfile(pathOfFile, ios::binary | ios::in);
	readfile.seekg(0, ios::beg);
	vector<string> m;
	string temp;
	while (getline(readfile, temp))
		m.push_back(temp);
	readfile.close();
	return m;
}