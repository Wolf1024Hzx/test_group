// 储存所有地图的名字，序号
#pragma once
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class AllMaps {
public:
	vector<string> namesOfMaps;
	unordered_set<string> names;
	AllMaps();
	AllMaps(vector<string>& name, unordered_set<string>& n);
	void newMap(string& name, vector<string> &thismap); // 没判断是否名字冲突
	void deleteMapByName(string& name);
	void deleteMapByNumber(int no);
};
