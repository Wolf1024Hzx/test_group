#include <iostream>
#include <windows.h>
#include "functions.h"
#include "AllMaps.h"

using namespace std;

void welcome_windows()
{
	system("cls");
}

vector<string> chooseMap(AllMaps &all)
{
	all.display();
	cout << "--You could choose Map by entering it's name or by entering it's number." << endl;
	cout << "--By which method would you like to?[1/2]" << endl << ">>";
	char order;
	bool flag = true; // 是否需要再次输入order
	while (1)
	{
		if (flag) cin >> order;
		cout << endl;
		if (order == '1')
		{
			cout << "--Now, please enter the name of the map you want to choose." << endl << ">>";
			string name;
			while (1)
			{
				cin >> name;
				if (all.names.count(name))
				{
					system("cls");
					cout << "Here's the map:" << endl;
					vector<string> m = all.loadMapByName(name);
					showMap(m);
					cout << endl << "--Do you want to choose this map?[y/n]" << endl << ">>";
					char order1;
					while (1)
					{
						cin >> order1;
						if (order1 == 'y' || order1 == 'Y')
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
							return m;
						}
						else if (order1 == 'n' || order1 == 'N')
						{
							all.display();
							cout << "--Please enter the name again." << endl << ">>";
							break;
						}
						else cout << "--We do not recognize this command, please enter again." << endl << ">>";
					}
				}
				else
				{
					cout << "--Sorry, we don't have this map." << endl << endl;
					cout << "--Do you want to enter the map's number?[y/n]" << endl << ">>";
					char order1;
					bool flag1 = false; // 若输入的名字不合法且用户希望切换到序号查询，flag1置true跳出
					while (1)
					{
						cin >> order1;
						if (order1 == 'y' || order1 == 'Y')
						{
							flag = false;
							flag1 = true;
							order = '2';
							break;
						}
						else if (order1 == 'n' || order1 == 'N')
						{
							cout << "--Please enter the name again." << endl << ">>";
							break;
						}
						else cout << "--We do not recognize this command, please enter again." << endl << ">>";
					}
					if (flag1) break;
				}
			}
		}
		if (order == '2')
		{
			int no, len = (int)all.namesOfMaps.size();
			cout << "--Now, please enter the number of the map you want to choose." << endl << ">>";
			while (1)
			{
				cin >> no;
				if (no < len && no >= 0)
				{
					system("cls");
					cout << "Here's the map:" << endl;
					vector<string> m = all.loadMapByNumber(no);
					showMap(m);
					cout << endl << "--Do you want to choose this map?[y/n]" << endl << ">>";
					char order1;
					while (1)
					{
						cin >> order1;
						if (order1 == 'y' || order1 == 'Y')
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
							return m;
						}
						else if (order1 == 'n' || order1 == 'N')
						{
							all.display();
							cout << "--Please enter the number again." << endl << ">>";
							break;
						}
						else cout << "--We do not recognize this command, please enter again." << endl << ">>";
					}
				}
				else
				{
					cout << "--We don't have this number." << endl << endl;
					cout << "--Do you want to enter the map's name?[y/n]" << endl << ">>";
					bool flag1 = false; // 若输入的数不合法且用户希望切换到名字查询，flag1置true跳出
					char order1;
					while (1)
					{
						cin >> order1;
						if (order1 == 'y' || order1 == 'Y')
						{
							flag = false;
							flag1 = true;
							order = '1';
							break;
						}
						else if (order1 == 'n' || order1 == 'N')
						{
							cout << "--Please enter the number again." << endl << ">>";
							break;
						}
						else cout << "--We do not recognize this command, please enter again." << endl << ">>";
					}
					if (flag1) break;
				}
			}
		}
		else
		{
			cout << "--We do not recognize this command, please enter again." << endl << ">>";
			flag = true;
		}
	}
	vector<string> rubbish;
	return rubbish;
}

void showMap(vector<string>& m)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	for (string& i : m)
		cout << i << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);;
	return;
}