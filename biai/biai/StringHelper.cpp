#include "StringHelper.h"

void replaceStrings(std::string& str, const std::string& toReplace, const std::string& replacer) {
	std::string::size_type n = 0;
	while ((n = str.find(toReplace, n)) != std::string::npos)
	{
		str.replace(n, toReplace.size(), replacer);
		n += replacer.size();
	}
}

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

string toStdString(System::String^ systemString) {
	return msclr::interop::marshal_as<std::string>(systemString);
}

System::String^ toSystemString(string s) {
	return gcnew System::String(s.c_str());
}

string showVectorVals(string label, std::vector<double> &v){
	string _text = "";
	_text += label;
	_text += " ";
	for (unsigned i = 0; i < v.size(); ++i) {
		_text += to_string(v[i]);
		_text += " ";
	}
	return _text;
}