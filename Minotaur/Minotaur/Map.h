// ���浥����ͼ��Ϣ
#pragma once
#include <string>
#include <vector>
#include <stack>

using namespace std;

class MAP {
public:
	char** Map;
	int length, height, begin_x, begin_y, end_x, end_y;
	MAP(vector<string>& temp); // ��AllMaps�м��س��ĵ�ͼת��ΪMAP��
	MAP(MAP& anotherMap);
	void printMap(int x, int y); // x��y����ǰ����
	void findSolutionByDFS();
	bool dfs(int x, int y, stack<int> &ans);
	~MAP();
};