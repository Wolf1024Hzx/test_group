#include <iostream>
#include<conio.h>
#include <math.h>
#include <windows.h>
#include "functions.h"
#include "AllMaps.h"
#include "Map.h"

using namespace std;

void welcome_windows()
{
	system("cls");
	cout << "*********************************************" << endl;
	cout << "*  !!!Welcome To A Simple Minotaur Game!!!  *" << endl;
	cout << "*             1. start game                 *" << endl;
	cout << "*             2. creat new map              *" << endl;
	cout << "*             3. delete old map             *" << endl;
	cout << "*             4. modify old map             *" << endl;
	cout << "*             5. View existing maps         *" << endl;
	cout << "*********************************************" << endl;
	cout << "--please choose operation by entering number." << endl;
	cout << ">>";
}

vector<string> chooseMap(AllMaps& all)
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
		string index;
		if (order == '1')
		{
			cout << "--Now, please enter the name of the map you want to choose." << endl << ">>";
			while (1)
			{
				cin >> index;
				bool flag2 = false; // 若输入的名字合法但用户不想要且用户希望切换到序号查询，flag2置true跳出
				if (all.findMap(index, 1))
				{
					system("cls");
					cout << "Here's the map:" << endl;
					vector<string> m = all.loadMapByName(index);
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
							cout << endl << "--Do you want to change to enter the map's number?[y/n]" << endl << ">>";
							char order2;
							bool flag1 = false;
							while (1)
							{
								cin >> order2;
								if (order2 == 'y' || order2 == 'Y')
								{
									flag = false;
									flag2 = true;
									order = '2';
									break;
								}
								else if (order2 == 'n' || order2 == 'N')
								{
									cout << "--Please enter the name again." << endl << ">>";
									break;
								}
								else cout << "--We do not recognize this command, please enter again." << endl << ">>";
							}
							break;
						}
						else cout << "--We do not recognize this command, please enter again." << endl << ">>";
					}
					if (flag2) break;
				}
				else
				{
					cout << "--Sorry, we don't have this map." << endl;
					cout << endl << "--Do you want to change to enter the map's number?[y/n]" << endl << ">>";
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
			cout << "--Now, please enter the number of the map you want to choose." << endl << ">>";
			while (1)
			{
				cin >> index;
				bool flag2 = false; // 若输入的序号合法但用户不想要且用户希望切换到名字查询，flag2置true跳出
				if (all.findMap(index, 2))
				{
					system("cls");
					cout << "Here's the map:" << endl;
					vector<string> m = all.loadMapByNumber(stoi(index));
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
							char order2;
							cout << endl << "--Do you want to change to enter the map's name?[y/n]" << endl << ">>";
							while (1)
							{
								cin >> order2;
								if (order2 == 'y' || order2 == 'Y')
								{
									flag = false;
									flag2 = true;
									order = '1';
									break;
								}
								else if (order2 == 'n' || order2 == 'N')
								{
									cout << "--Please enter the number again." << endl << ">>";
									break;
								}
								else cout << "--We do not recognize this command, please enter again." << endl << ">>";
							}
							break;
						}
						else cout << "--We do not recognize this command, please enter again." << endl << ">>";
					}
					if (flag2) break;
				}
				else
				{
					cout << "--We don't have this number." << endl;
					cout << endl << "--Do you want to change to enter the map's name?[y/n]" << endl << ">>";
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

void startGame(AllMaps& all) {
	vector<string> tmp = chooseMap(all);
	MAP map(tmp);
	int px = map.begin_x, py = map.begin_y, ex = map.end_x, ey = map.end_y;
	bool flag = true;
	char ctrl;
	cout << "--The game will start in five seconds." << endl;
	cout << "--You could use 'wasd' to control your direction." << endl;
	cout << "--You could enter 'p' to exit." << endl;
	cout << "Let's go out of the minotaur!" << endl;
	Sleep(5000);
	while (1) {
		system("cls");
		map.printMap(px, py);
		if (px == ex && py == ey)
			break;
		ctrl = _getch();
		if (ctrl == 'w' && px > 0 && map.Map[px - 1][py] != '*')
			px--;
		else if (ctrl == 's' && px < map.height - 1 && map.Map[px + 1][py] != '*')
			px++;
		else if (ctrl == 'a' && py > 0 && map.Map[px][py - 1] != '*')
			py--;
		else if (ctrl == 'd' && py < map.length - 1 && map.Map[px][py + 1] != '*')
			py++;
		else if (ctrl == 'p') {
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "!!You Win!!!" << endl;
	else {
		cout << "Would you like me to tell you the correct route of the minotaur?[y/n]" << endl << ">>";
		while (1) {
			cin >> ctrl;
			if (ctrl == 'y' || ctrl == 'Y') {
				map.findSolutionByDFS();
				break;
			}
			else if (ctrl == 'n' || ctrl == 'N') {
				break;
			}
			else cout << "--We do not recognize this command, please enter again." << endl << ">>";
		}
	}
	cout << "Welcome to play again!" << endl;
	return;
}

bool creatNewMap(AllMaps& all) {
	string name;
	cout << "--Please enter the name of new map" << endl << ">>";
	cin >> name;
	if (!all.findMap(name, 1)) {
		vector<string> map;
		int height;
		cout << "--Please enter the height of new map" << endl << ">>";
		cin >> height;
		getchar();
		cout << "--Please create the new map:" << endl;
		while (height--) {
			string line;
			getline(cin, line);
			map.push_back(line);
		}
		all.newMap(name, map);
		cout << "created successfully" << endl;
		return true;
	}
	else return false;
}

bool deleteOldMap(AllMaps& all) {
	all.display();
	cout << "--You could delete Map by entering it's name or by entering it's number." << endl;
	cout << "--By which method would you like to?[1/2]" << endl << ">>";
	char order;
	bool flag = true;
	while (1) {
		if (flag) cin >> order;
		cout << endl;
		string index;
		if (order == '1') {
			cout << "--Now, please enter the name of the map you want to delete." << endl << ">>";
			while (1)
			{
				cin >> index;
				bool flag2 = false; // 若输入的名字合法但用户不想要且用户希望切换到序号查询，flag2置true跳出
				if (all.findMap(index, 1))
				{
					system("cls");
					cout << "Here's the map:" << endl;
					vector<string> m = all.loadMapByName(index);
					showMap(m);
					cout << endl << "--Do you want to delete this map?[y/n]" << endl << ">>";
					char order1;
					while (1)
					{
						cin >> order1;
						if (order1 == 'y' || order1 == 'Y')
						{
							all.deleteMapByName(index);
							return true;
						}
						else if (order1 == 'n' || order1 == 'N')
						{
							all.display();
							cout << endl << "--Do you want to change to enter the map's number?[y/n]" << endl << ">>";
							char order2;
							bool flag1 = false;
							while (1)
							{
								cin >> order2;
								if (order2 == 'y' || order2 == 'Y')
								{
									flag = false;
									flag2 = true;
									order = '2';
									break;
								}
								else if (order2 == 'n' || order2 == 'N')
								{
									cout << "--Please enter the name again." << endl << ">>";
									break;
								}
								else cout << "--We do not recognize this command, please enter again." << endl << ">>";
							}
							break;
						}
						else cout << "--We do not recognize this command, please enter again." << endl << ">>";
					}
					if (flag2) break;
				}
				else
				{
					cout << "--Sorry, we don't have this map." << endl;
					cout << endl << "--Do you want to change to enter the map's number?[y/n]" << endl << ">>";
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
		else if (order == '2')
		{
			cout << "--Now, please enter the number of the map you want to delete." << endl << ">>";
			while (1)
			{
				cin >> index;
				bool flag2 = false; // 若输入的序号合法但用户不想要且用户希望切换到名字查询，flag2置true跳出
				if (all.findMap(index, 2))
				{
					system("cls");
					cout << "Here's the map:" << endl;
					vector<string> m = all.loadMapByNumber(stoi(index));
					showMap(m);
					cout << endl << "--Do you want to delete this map?[y/n]" << endl << ">>";
					char order1;
					while (1)
					{
						cin >> order1;
						if (order1 == 'y' || order1 == 'Y')
						{
							all.deleteMapByNumber(stoi(index));
							return true;
						}
						else if (order1 == 'n' || order1 == 'N')
						{
							all.display();
							char order2;
							cout << endl << "--Do you want to change to enter the map's name?[y/n]" << endl << ">>";
							while (1)
							{
								cin >> order2;
								if (order2 == 'y' || order2 == 'Y')
								{
									flag = false;
									flag2 = true;
									order = '1';
									break;
								}
								else if (order2 == 'n' || order2 == 'N')
								{
									cout << "--Please enter the number again." << endl << ">>";
									break;
								}
								else cout << "--We do not recognize this command, please enter again." << endl << ">>";
							}
							break;
						}
						else cout << "--We do not recognize this command, please enter again." << endl << ">>";
					}
					if (flag2) break;
				}
				else
				{
					cout << "--We don't have this number." << endl;
					cout << endl << "--Do you want to change to enter the map's name?[y/n]" << endl << ">>";
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
		else{
			cout << "--We do not recognize this command, please enter again." << endl << ">>";
			flag = true;
		}
	}
	return false;
}

bool modifyOldMap(AllMaps& all) {
	all.display();
	cout << "--You could modify Map by entering it's name or by entering it's number." << endl;
	cout << "--By which method would you like to?[1/2]" << endl << ">>";
	char order;
	bool flag = true;
	while (1) {
		if (flag) cin >> order;
		cout << endl;
		string index;
		if (order == '1') {
			cout << "--Now, please enter the name of the map you want to modify." << endl << ">>";
			while (1)
			{
				cin >> index;
				bool flag2 = false; // 若输入的名字合法但用户不想要且用户希望切换到序号查询，flag2置true跳出
				if (all.findMap(index, 1))
				{
					system("cls");
					cout << "Here's the map:" << endl;
					vector<string> m = all.loadMapByName(index);
					showMap(m);
					vector<string> map;
					int height;
					cout << "--Please enter the height of modified map" << endl << ">>";
					cin >> height;
					getchar();
					cout << "--Please create the modified map:" << endl;
					while (height--) {
						string line;
						getline(cin, line);
						map.push_back(line);
					}
					cout << endl << "--Do you want to modify this map?[y/n]" << endl << ">>";
					char order1;
					while (1)
					{
						cin >> order1;
						if (order1 == 'y' || order1 == 'Y')
						{
							all.modifyMapByName(index, map);
							cout << "modified successfully" << endl;
							return true;
						}
						else if (order1 == 'n' || order1 == 'N')
						{
							all.display();
							cout << endl << "--Do you want to change to enter the map's number?[y/n]" << endl << ">>";
							char order2;
							bool flag1 = false;
							while (1)
							{
								cin >> order2;
								if (order2 == 'y' || order2 == 'Y')
								{
									flag = false;
									flag2 = true;
									order = '2';
									break;
								}
								else if (order2 == 'n' || order2 == 'N')
								{
									cout << "--Please enter the name again." << endl << ">>";
									break;
								}
								else cout << "--We do not recognize this command, please enter again." << endl << ">>";
							}
							break;
						}
						else cout << "--We do not recognize this command, please enter again." << endl << ">>";
					}
					if (flag2) break;
				}
				else
				{
					cout << "--Sorry, we don't have this map." << endl;
					cout << endl << "--Do you want to change to enter the map's number?[y/n]" << endl << ">>";
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
		else if (order == '2')
		{
			cout << "--Now, please enter the number of the map you want to modify." << endl << ">>";
			while (1)
			{
				cin >> index;
				bool flag2 = false; // 若输入的序号合法但用户不想要且用户希望切换到名字查询，flag2置true跳出
				if (all.findMap(index, 2))
				{
					system("cls");
					cout << "Here's the map:" << endl;
					vector<string> m = all.loadMapByNumber(stoi(index));
					showMap(m);
					vector<string> map;
					int height;
					cout << "--Please enter the height of modified map" << endl << ">>";
					cin >> height;
					getchar();
					cout << "--Please create the modified map:" << endl;
					while (height--) {
						string line;
						getline(cin, line);
						map.push_back(line);
					}
					cout << endl << "--Do you want to modify this map?[y/n]" << endl << ">>";
					char order1;
					while (1)
					{
						cin >> order1;
						if (order1 == 'y' || order1 == 'Y')
						{
							all.modifyMapByNumber(stoi(index), map);
							cout << "modified successfully" << endl;
							return true;
						}
						else if (order1 == 'n' || order1 == 'N')
						{
							all.display();
							char order2;
							cout << endl << "--Do you want to change to enter the map's name?[y/n]" << endl << ">>";
							while (1)
							{
								cin >> order2;
								if (order2 == 'y' || order2 == 'Y')
								{
									flag = false;
									flag2 = true;
									order = '1';
									break;
								}
								else if (order2 == 'n' || order2 == 'N')
								{
									cout << "--Please enter the number again." << endl << ">>";
									break;
								}
								else cout << "--We do not recognize this command, please enter again." << endl << ">>";
							}
							break;
						}
						else cout << "--We do not recognize this command, please enter again." << endl << ">>";
					}
					if (flag2) break;
				}
				else
				{
					cout << "--We don't have this number." << endl;
					cout << endl << "--Do you want to change to enter the map's name?[y/n]" << endl << ">>";
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
		else {
			cout << "--We do not recognize this command, please enter again." << endl << ">>";
			flag = true;
		}
	}
	return false;
}

void showMap(vector<string>& m)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	for (string& i : m)
		cout << i << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);;
	return;
}

bool operation(AllMaps& all, int order) {
	switch (order) {
	case 1: {
		startGame(all);
		return true;
	}
	case 2: {
		if (creatNewMap(all))
			return true;
		else return false;
	}
	case 3: {
		if (deleteOldMap(all))
			return true;
		else return false;
	}
	case 4: {
		if (modifyOldMap(all))
			return true;
		else return false;
	}
	case 5: {
		vector<string> tmp = chooseMap(all);
		return true;
	}
	default: return false;
	}
}