#pragma once
#include <vector>
#include <string>
#include "AllMaps.h"

using namespace std;

void welcome_windows();
vector<string> chooseMap(AllMaps& all);
void showMap(vector<string>& m);