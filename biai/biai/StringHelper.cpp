#include "StringHelper.h"

void splitString(const string& str, vector<string>& v) {
	stringstream ss(str);
	ss >> noskipws;
	string field;
	char ws_delim;
	while (1) {
		if (ss >> field)
			v.push_back(field);
		else if (ss.eof())
			break;
		else
			v.push_back(string());
		ss.clear();
		ss >> ws_delim;
	}
}