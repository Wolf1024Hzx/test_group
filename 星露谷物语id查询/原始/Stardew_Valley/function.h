#include "citem.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "windows.h"
#include "stdlib.h"

using namespace std;

void welcome();
void help();
bool start();
bool if_search_again();
void finish();
void load(vector<item> &arr);
bool find(vector<item> &arr, string n);
bool find_id(vector<item> &arr, int ID);
bool find_type(vector<item> &arr, string type);
bool not_found();
void ADD(vector<item> &arr);
void add(vector<item> &arr, string name);
void add_id(vector<item> &arr, int id);
void Sort(vector<item> &arr);
void show_list(vector<item> &arr);

void welcome()
{
	string order;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
		FOREGROUND_BLUE);
	cout << "          *******************************************" << endl;
	cout << "          *                                         *" << endl;
	cout << "          * 欢迎使用本系统                          *" << endl;
	cout << "          * 请输入指令，或输入help获取指令列表      *" << endl;
	cout << "          *                                         *" << endl;
	cout << "          *******************************************" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	return;
}

void help()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
		FOREGROUND_BLUE);
	cout << "***************************************" << endl;
	cout << "***************************************" << endl;
	cout << "**                                   **" << endl;
	cout << "**  输入名称查询物品:    search      **" << endl;
	cout << "**  输入id查询物品:      search_id   **" << endl;
	cout << "**  输入类型查询物品:    search_type **" << endl;
	cout << "**  获取物品列表:        list        **" << endl;
	cout << "**  对物品列表进行排序:  sort        **" << endl;
	cout << "**  按名称添加物品:      add         **" << endl;
	cout << "**  结束程序:            finish      **" << endl;
	cout << "**                                   **" << endl;
	cout << "***************************************" << endl;
	cout << "***************************************" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
}

bool start()
{
	vector<item> arr;
	string order;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
		FOREGROUND_BLUE);
	cout << "请输入指令>>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	cin >> order;
	if (order == "help")
	{
		help();
		return true;
	}
	else if (order == "search")
	{
		string name;
		load(arr);
		cout << "请输入物品名称>>";
		cin >> name;
		if (!find(arr, name))
		{
			if (not_found())
				add(arr, name);
		}
		while(if_search_again())
		{
			cout << "请输入物品名称>>";
			cin >> name;
			if (!find(arr, name))
			{
				if (not_found())
					add(arr, name);
			}
		}
		return true;
	}
	else if (order == "search_id")
	{
		int id;
		load(arr);
		cout << "请输入物品id>>";
		cin >> id;
		if (!find_id(arr, id))
		{
			if (not_found())
				add_id(arr, id);
		}
		while(if_search_again())
		{
			cout << "请输入物品id>>";
			cin >> id;
			if (!find_id(arr, id))
			{
				if (not_found())
					add_id(arr, id);
			}
		}
		return true;
	}
	else if (order == "sort")
	{
		load(arr);
		Sort(arr);
		return true;
	}
	else if (order == "list")
	{
		load(arr);
		show_list(arr);
		return true;
	}
	else if (order == "search_type")
	{
		string type;
		load(arr);
		cout << "请输入物品类型>>";
		cin >> type;
		if (!find_type(arr, type))
			cout << "目前列表中没有该类型的物品~" << endl;
		while(if_search_again())
		{
			cout << "请输入物品类型>>";
			cin >> type;
			if (!find_type(arr, type))
				cout << "目前列表中没有该类型的物品~" << endl;
		}
		return true;
	}
	else if (order == "finish")
	{
		finish();
		return false;
	}
	else if (order == "add")
	{
		load(arr);
		ADD(arr);
		return true;
	}
	else 
	{
		cout << "当前不支持该指令呢~" << endl;
		return true;
	}
}

bool if_search_again()
{
	int i;
	cout << "是否再次查询？是的话请按1" << endl;
	cin >> i;
	if (i)
		return true;
	return false;
}

void finish()
{
	cout << "感谢使用，再见!" << endl;
}

void load(vector<item> &arr)
{
	item one;
	cout << "loading data..." << endl;
	fstream file("c:\\cpp_txt\\Stardew_Vallet_item_list", ios::binary | ios::in);
	file.seekg(0);
	while (1)
	{
		if (file.peek() == EOF)
			break;
		file.read((char*)&one, sizeof(item));
		arr.push_back(one);
		file.seekg(0, ios::cur);
	}
	file.close();
	cout << "done!" << endl;
	return;
}

bool find(vector<item>& arr, string n)
{
	for (int i = 0; i < (int)arr.size(); i++)
	{
		if (arr[i].name == n)
		{
			arr[i].show();
			return true;
		}
	}
	return false;
}

bool find_id(vector<item> &arr, int ID)
{
	for (int i = 0; i < (int)arr.size(); i++)
	{
		if (arr[i].id == ID)
		{
			arr[i].show();
			return true;
		}
	}
	return false;
}

bool find_type(vector<item> &arr, string type)
{
	bool flag = false;
	for (int i = 0; i < (int)arr.size(); i++)
	{
		if (type == arr[i].type)
		{
			flag = true;
			cout << arr[i].name << ' ' << arr[i].id << ' ' << arr[i].type << endl;
		}
	}
	return flag;
}

bool not_found()
{
	cout << "列表中暂无该物品，是否添加？" << endl;
	cout << "添加请按1" << endl;
	int order;
	cin >> order;
	if (order == 1)
		return true;
	else
		return false;
}

void add(vector<item> &arr, string name)
{
	string type;
	int id;
	cout << endl << "请输入物品id及类型，用空格分隔:" << endl;
	cin >> id >> type;
	item one(name, type, id);
	arr.push_back(one);
	int len = arr.size();
	fstream file("c:\\cpp_txt\\Stardew_Vallet_item_list", ios::binary | ios::out);
	file.seekp(0L, ios::end);
	for (int i = 0; i < len; i++)
	{
		one = arr[i];
		file.write((char *)&one, sizeof(item));
	}
	file.close();
	cout << "添加成功！" << endl;
	return;
}

void add_id(vector<item> &arr, int id)
{
	string type, name;
	cout << endl << "请输入物品名称及类型，用空格分隔:" << endl;
	cin >> name >> type;
	item one(name, type, id);
	arr.push_back(one);
	int len = arr.size();
	fstream file("c:\\cpp_txt\\Stardew_Vallet_item_list", ios::binary | ios::out);
	file.seekp(0L, ios::end);
	for (int i = 0; i < len; i++)
	{
		one = arr[i];
		file.write((char *)&one, sizeof(item));
	}
	file.close();
	cout << "添加成功！" << endl;
	return;
}

void Sort(vector<item> &arr)
{
	cout << "整理中。。。" << endl;
	sort(arr.begin(), arr.end());
	item temp;
	fstream file("c:\\cpp_txt\\Stardew_Vallet_item_list", ios::binary | ios::out);
	file.seekp(0L, ios::end);
	int len = (int)arr.size();
	for (int i = 0; i < len; i++)
	{
		temp = arr[i];
		file.write((char *)&temp, sizeof(item));
	}
	file.close();
	cout << "done!" << endl;
	return;
}

void show_list(vector<item> &arr)
{
	cout << "当前列表内收纳物品信息如下:" << endl;
	int len = (int)arr.size(), i;
	for (i = 0; i < len; i++)
		cout << arr[i].name << ' ' << arr[i].id << ' ' << arr[i].type << endl;
	return;
}

void ADD(vector<item> &arr)
{
	string name, type;
	int id;
	cout << "请输入需添加物品的名称,id,即类型:" << endl;
	cin >> name >> id >> type;
	item one(name, type, id);
	arr.push_back(one);
	int len = arr.size();
	fstream file("c:\\cpp_txt\\Stardew_Vallet_item_list", ios::binary | ios::out);
	file.seekp(0L, ios::end);
	for (int i = 0; i < len; i++)
	{
		one = arr[i];
		file.write((char *)&one, sizeof(item));
	}
	file.close();
	cout << "添加成功！" << endl;
	return;
}