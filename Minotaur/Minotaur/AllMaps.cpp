#include <vector>
#include <unordered_set>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include "AllMaps.h"

using namespace std;

AllMaps::AllMaps()
{
	fstream readfile("../savedata/MapNames.txt", ios::binary | ios::in);
	string file_name;
	readfile.seekg(0L, ios::beg);
	while (getline(readfile, file_name))
	{
		if (file_name[(int)file_name.length() - 1] == '\r' || file_name[(int)file_name.length() - 1] == '\n') file_name.pop_back();
		namesOfMaps.push_back(file_name);
		names.insert(file_name);
	}
	readfile.close();
	return;
}

void AllMaps::display()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "Here are the maps now:" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "___________________________________" << endl << "|                                 |" << endl;
	cout << "| number     name                 |" << endl;
	for (int i = 0; i < (int)namesOfMaps.size(); i++)
	{
		cout << "|  ";
		cout << setw(3) << setfill('0') << right << i;
		cout << "       ";
		cout << setw(21) << setfill(' ') << left << namesOfMaps[i];
		cout << '|' << endl;
	}
	cout << "|                                 |" << endl << "-----------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	return;
}

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

vector<string> AllMaps::loadMapByName(string& name)
{
	string Path = "../savedata/" + name + ".txt";
	string line;
	vector<string> m;
	fstream readfile(Path, ios::binary | ios::in);
	while (getline(readfile, line))
	{
		if (line[(int)line.length() - 1] == '\r' || line[(int)line.length() - 1] == '\n') line.pop_back();
		m.push_back(line);
	}
	readfile.close();
	return m;
}

vector<string> AllMaps::loadMapByNumber(int no)
{
	string Path = "../savedata/" + namesOfMaps[no] + ".txt";
	string line;
	vector<string> m;
	fstream readfile(Path, ios::binary | ios::in);
	while (getline(readfile, line))
	{
		if (line[(int)line.length() - 1] == '\r' || line[(int)line.length() - 1] == '\n') line.pop_back();
		m.push_back(line);
	}
	readfile.close();
	return m;
}