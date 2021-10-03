#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "AllMaps.h"
#include "functions.h"

using namespace std;

int main()
{
	AllMaps a;
	vector<string> m = chooseMap(a);
	showMap(m);
	return 0;
}