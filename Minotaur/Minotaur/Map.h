// ���浥����ͼ��Ϣ
#pragma once
#include <string>
#include <vector>

using namespace std;

class MAP {
public:
	char** Map;
	int length, height;
	MAP(vector<string>& temp); // ��AllMaps�м��س��ĵ�ͼת��ΪMAP��
	MAP(MAP& anotherMap);
	void printMap();
	~MAP();
};