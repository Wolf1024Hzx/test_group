#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "GetMapFromFiles.h"
#include "Map.h"

using namespace std;

vector<string> loadMap(int no)
{
	stringstream ss;
	string pathOfFile = "../savedata/No";
	ss << pathOfFile << no << ".txt";
	ss >> pathOfFile;
	fstream readfile(pathOfFile, ios::binary | ios::in);
	readfile.seekg(0);
	vector<string> m;
	string temp;
	while (getline(readfile, temp))
		m.push_back(temp);
	readfile.close();
	return m;
}