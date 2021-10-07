#pragma once
#include <vector>
#include <string>
#include "AllMaps.h"

using namespace std;

void welcome_windows();
vector<string> chooseMap(AllMaps& all);
bool creatNewMap(AllMaps& all);
bool deleteOldMap(AllMaps& all);
bool modifyOldMap(AllMaps& all);
void showMap(vector<string>& m);
bool operation(AllMaps& all, int order);//选择执行操作