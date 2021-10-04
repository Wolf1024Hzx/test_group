#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "AllMaps.h"
#include "functions.h"

using namespace std;

int main()
{
	AllMaps all;
	while (1) {
		system("cls");
		welcome_windows();
		int order;
		cin >> order;
		if (!operation(all, order))
			cout << "operation failed" << endl;
		system("pause");
	}
	return 0;
}