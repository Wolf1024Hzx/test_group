#pragma once
#include <string>
#include <iostream>
#include "Windows.h"

using namespace std;

class item {
public:
	string name, type;
	int id;
	item() {}
	item(string n, string t, int i): name(n), type(t), id(i){}
	void set_item(string n, string t, int i);
	void show();
	bool operator <(item &p);
};

void item::set_item(string n, string t, int i)
{
	name = n;
	type = t;
	id = i;
	return;
}

void item::show()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
		FOREGROUND_BLUE);
	cout << endl << "物品名称: " << name << endl << "类型: " << type << endl << "id: " << id << endl;
	cout << "代码: player_add ";
	if (type == "武器")
		cout << "weapon " << id << " <数量>" << endl;
	else if (type == "戒指")
		cout << "ring " << id << " <数量>" << endl;
	else
		cout << "object " << id << " <数量> <品质>" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	cout << endl;
	return;
}

bool item::operator <(item &p)
{
	return (id < p.id);
}