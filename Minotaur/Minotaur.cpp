#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Map.h"
#include "GetMapFromFiles.h"

using namespace std;

int main()
{
	int no;
	cin >> no;
	for (string& i : loadMap(no))
		cout << i << endl;
	return 0;
}