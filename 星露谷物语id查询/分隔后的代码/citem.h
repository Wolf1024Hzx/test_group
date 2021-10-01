#pragma once
#include <string>

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