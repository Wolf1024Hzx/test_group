#include <vector>
#include <unordered_set>
#include <fstream>
#include <cstdio>
#include <string>
#include "AllMaps.h"

using namespace std;

AllMaps::AllMaps()
{
	fstream readfile("../savedata/MapNames.txt", ios::binary | ios::in);
	string file_name;
	while (getline(readfile, file_name))
	{
		namesOfMaps.push_back(file_name);
		names.insert(file_name);
	}
	readfile.close();
	return;
}

AllMaps::AllMaps(vector<string>& name, unordered_set<string>& n): namesOfMaps(name), names(n){}

void AllMaps::newMap(string& name, vector<string>& thismap)
{
	namesOfMaps.push_back(name);
	names.insert(name);
	string Path = "../savedata/" + name + ".txt";
	fstream writefile;
	writefile.open(Path, ios::binary | ios::out);
	writefile.seekp(0, ios::beg);
	for (string& i : thismap) writefile << i << endl;
	writefile.close();
	Path = "../savedata/MapNames.txt";
	writefile.open(Path, ios::binary | ios::out);
	writefile.seekp(0, ios::beg);
	for (string& i : namesOfMaps) writefile << i << endl;
	writefile.close();
	return;
}

void AllMaps::deleteMapByName(string& name)
{
	names.erase(name);
	for (int i = 0; i < (int)namesOfMaps.size(); i++)
	{
		if (namesOfMaps[i] == name)
		{
			for (int j = i; j < (int)namesOfMaps.size() - 1; j++) namesOfMaps[j] = namesOfMaps[j + 1];
			namesOfMaps.pop_back();
			break;
		}
	}
	string Path = "../savedata/" + name + ".txt";
	remove(Path.c_str());
	Path = "../savedata/MapNames.txt";
	fstream writefile;
	writefile.open(Path, ios::binary | ios::out);
	writefile.seekp(0, ios::beg);
	for (string& i : namesOfMaps) writefile << i << endl;
	writefile.close();
	return;
}

void AllMaps::deleteMapByNumber(int no)
{
	names.erase(namesOfMaps[no]);
	string Path = "../savedata/" + namesOfMaps[no] + ".txt";
	for (int i = no; i < (int)namesOfMaps.size() - 1; i++) namesOfMaps[i] = namesOfMaps[i + 1];
	namesOfMaps.pop_back();
	remove(Path.c_str());
	Path = "../savedata/MapNames.txt";
	fstream writefile;
	writefile.open(Path, ios::binary | ios::out);
	writefile.seekp(0, ios::beg);
	for (string& i : namesOfMaps) writefile << i << endl;
	writefile.close();
	return;
}