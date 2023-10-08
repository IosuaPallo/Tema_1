#include "Grammar.h"


Grammar::Grammar()
{

}

Grammar::~Grammar()
{

}

Grammar::Grammar(map<string, vector<string>> grammarMap, string nonTerminals, string terminals, string startSymbol) {
	this->grammar = grammarMap;
	this->nonTerminals = nonTerminals;
	this->terminals = terminals;
	this->startSymbol = startSymbol;
	srand(time(0));
}

void Grammar::extremeLeft() {
	vector<string> results; 
	string result; 
	bool sem=false; 
	cout << "Extrem stanga \n";
	while (!sem) {
		result.clear(); 
		result = startSymbol;
		while (result.length() < 80) {
			int j = 0;
			while (j < result.length() && result.length() < 80) {
				int position = nonTerminals.find(result[j]);
				if (position != -1) {
					string nonTerminal;
					nonTerminal.push_back(result[j]);
					vector<string> value = grammar[nonTerminal];
					int length = value.size();
					int random = rand() % length;
					string replaceFunction = value[random];
					result.replace(position, nonTerminal.length(), replaceFunction);
					j = 0;
				}
				else {
					j++;
				}
			}
		}
		results.push_back(result);
		cout << result << "\n";
		if (result.length() < 80) {
			sem = true;
		}
	}
}

void Grammar::extremeRight() {
	cout << "Extrem dreapta\n";
}