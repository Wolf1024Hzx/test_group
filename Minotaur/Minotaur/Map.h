#pragma once
#include <string>
#include <vector>

using namespace std;

class MAP {
public:
	char** Map;
	int length, height;
	MAP(vector<string>& temp);
	MAP(MAP& anotherMap);
	~MAP();
};