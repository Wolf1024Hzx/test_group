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
	AllMaps(); // 构造函数，读取出所有地图的名字并标上序号
	void display(); // 输出所有地图的序号和名字
	void newMap(string& name, vector<string> &thismap); // 通过名字创建地图，注意没判断是否名字冲突
	void deleteMapByName(string& name); // 通过名字删除地图，注意未判断该名字地图是否存在
	void deleteMapByNumber(int no); // 通过序号删除地图，注意未判断序号是否越界
	vector<string> loadMapByName(string& name); // 通过名字加载地图,注意未判断该名字地图是否存在
	vector<string> loadMapByNumber(int no); // 通过序号加载地图，注意未判断序号是否越界
	bool findMap(string index, int mode); //通过索引来寻找地图，分名字和序号两种模式
};
