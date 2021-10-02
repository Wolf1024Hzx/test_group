#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "AllMaps.h"

using namespace std;

int main()
{
	AllMaps a;
	vector<string> arr{ "*   *", "*****" };
	string n = "test_create_map";
	a.newMap(n, arr);
	a.display();
	return 0;
}