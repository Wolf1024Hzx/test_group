// 储存单个地图信息
#pragma once
#include <string>
#include <vector>

using namespace std;

class MAP {
public:
	char** Map;
	int length, height;
	MAP(vector<string>& temp); // 把AllMaps中加载出的地图转换为MAP类
	MAP(MAP& anotherMap);
	void printMap();
	~MAP();
};