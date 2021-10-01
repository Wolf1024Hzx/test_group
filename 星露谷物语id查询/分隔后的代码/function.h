#pragma once
#include "citem.h"
#include <iostream>
#include <string>
#include <vector>

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