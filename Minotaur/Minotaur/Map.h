// 储存单个地图信息
#pragma once
#include <string>
#include <vector>
#include <stack>

using namespace std;

class MAP {
public:
	char** Map;
	int length, height, begin_x, begin_y, end_x, end_y;
	MAP(vector<string>& temp); // 把AllMaps中加载出的地图转换为MAP类
	MAP(MAP& anotherMap);
	void printMap(int x, int y); // x，y即当前坐标
	void findSolutionByDFS();
	bool dfs(int x, int y, stack<int> &ans);
	~MAP();
};