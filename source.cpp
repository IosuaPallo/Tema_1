#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <time.h>

#include "Grammar.h"

using namespace std;

struct pos {
	int position;
	string key;
};

void citire(map<string, vector<string>>& grammar, vector<string>& nonTerminals, vector<string>& terminals, string& startSymbol);
string replaceString(int position, string result, string key, string replacement);
void extremeLeft(map<string, vector<string>>& grammar, vector<string>& nonTerminals, vector<string>& terminals, string& startSymbol);

void scriere() {
	ofstream fout("date.out");

	fout.close(); 
}

int main() {
	srand(time(0)); 
	map<string, vector<string>> grammarMap; 
	vector<string> nonTerminals, terminals;
	string startSymbol;
	citire(grammarMap, nonTerminals, terminals, startSymbol); 
	extremeLeft(grammarMap, nonTerminals, terminals, startSymbol);
}

void citire(map<string, vector<string>>& grammar, vector<string>& nonTerminals, vector<string>& terminals, string& startSymbol){
	ifstream fin("date.in");
	string line;
	getline(fin, line); 
	istringstream elements(line);
	while (getline(elements, line, ' ')) {
		nonTerminals.push_back(line); 
	}
	getline(fin, line);
	elements.clear(); 
	elements.str(line); 
	while (getline(elements, line, ' ')) {
		terminals.push_back(line);
	}

	while (getline(fin, line)) {
		istringstream stream(line);
		string key, value; 
		getline(stream, key, '=');
		getline(stream, value); 
		if (value=="") {
			startSymbol.append(key);
		}
		else {
			grammar[key].push_back(value);
		}
	}
	fin.close();
}


void extremeLeft(map<string, vector<string>>& grammar, vector<string>& nonTerminals, vector<string>& terminals, string& startSymbol) {
	vector<string> results;
	string result;
	bool sem = false;
	cout << "Extrem stanga \n";
	for (int i = 0; i < 20;i++) {
		result.clear();
		result = startSymbol;
		vector<int> position(nonTerminals.size(), -1);
		bool sem = 0;
		while (result.length() < 80 && sem==0 ) {
			int min = nonTerminals.size()+1; 
			string key;
			for (int k = 0; k < nonTerminals.size(); k++) {
				position[k] = result.find(nonTerminals[k]);
				if (position[k] < min && position[k]!=-1) {
					min = position[k]; 
					key = nonTerminals[k]; 
				}
			}
			if (min != nonTerminals.size() + 1) {
				vector<string> values = grammar[key];
				int random = rand() % values.size();
				string replacement = values[random];
				result = replaceString(min, result, key, replacement); 
				position.assign(position.size(), -1);
			}
			else {
				sem = 1; 
			}
		}
		results.push_back(result);
	}
	for (string str : results) {
		cout << str << "\n"; 
	}
}

string replaceString(int position, string result, string key, string replacement) {
	string resultString = result.substr(0, position); 
	resultString.append(replacement);
	resultString = resultString + result.substr(position + key.length());
	return resultString;
}