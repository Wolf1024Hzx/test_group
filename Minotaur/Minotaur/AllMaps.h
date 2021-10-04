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
	AllMaps(); // ���캯������ȡ�����е�ͼ�����ֲ��������
	void display(); // ������е�ͼ����ź�����
	void newMap(string& name, vector<string> &thismap); // ͨ�����ִ�����ͼ��ע��û�ж��Ƿ����ֳ�ͻ
	void deleteMapByName(string& name); // ͨ������ɾ����ͼ��ע��δ�жϸ����ֵ�ͼ�Ƿ����
	void deleteMapByNumber(int no); // ͨ�����ɾ����ͼ��ע��δ�ж�����Ƿ�Խ��
	vector<string> loadMapByName(string& name); // ͨ�����ּ��ص�ͼ,ע��δ�жϸ����ֵ�ͼ�Ƿ����
	vector<string> loadMapByNumber(int no); // ͨ����ż��ص�ͼ��ע��δ�ж�����Ƿ�Խ��
	bool findMap(string index, int mode); //ͨ��������Ѱ�ҵ�ͼ�������ֺ��������ģʽ
};
