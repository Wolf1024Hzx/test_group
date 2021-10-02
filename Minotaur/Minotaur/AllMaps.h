// �������е�ͼ�����֣����
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
	void newMap(string& name, vector<string> &thismap); // û�ж��Ƿ����ֳ�ͻ
	void deleteMapByName(string& name);
	void deleteMapByNumber(int no);
};
