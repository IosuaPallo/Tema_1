#pragma once
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;


class Grammar
{
public:
	Grammar();
	Grammar(map<string, vector<string>> grammarMap, string nonTerminals, string terminals, string startSymbol);
	~Grammar();
	void extremeRight();
	void extremeLeft(); 

private:
	map<string, vector<string>> grammar;
	string nonTerminals;
	string terminals;
	string startSymbol;
};

