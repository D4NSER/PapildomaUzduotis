#pragma once
#include "mylib.h"

string getFileChoice();
bool canOpen (const string& fileChoice);
bool isURL (const string& zodis);
string fixWords(const string& zodis);
void addToTheList(const string& zodis, map<string, vector<int>>& sarasas, int eilutesNumeris);
void readFile(const string& fileChoice,  map<string, vector<int>>& sarasas, vector<string>& urls);
void output (map<string, vector<int>>& sarasas,vector<string> urls);